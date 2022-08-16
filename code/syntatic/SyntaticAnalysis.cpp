#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SyntaticAnalysis.h"



SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex):
	m_lex(lex), m_current(lex.nextToken()) {
}

SyntaticAnalysis::~SyntaticAnalysis(){
}

void SyntaticAnalysis::start(){
	procProgram();
	eat(TT_END_OF_FILE);
}

void SyntaticAnalysis::advance() {
	m_current = m_lex.nextToken();
}

void SyntaticAnalysis::eat(enum TokenType type) {
	std::cout << "Expected (...," << tt2str(type)
			  << "), found (\"" + m_current.token << "\", "
			  << tt2str(m_current.type) + ")" << std::endl;
    if (type == m_current.type) {
        advance();
    } else {
        showError();
    }
}

void SyntaticAnalysis::showError() {
	std::cout << std::setw(2) << std::setfill('0') << m_lex.line() << ": ";

	switch (m_current.type) {
		case TT_INVALID_TOKEN:
			std::cout << "Lexema inválido [" << m_current.token << "]" << std::endl;
			break;
		case TT_UNEXPECTED_EOF:
		case TT_END_OF_FILE:
			std::cout << "Fim de arquivo inesperado" << std::endl;
			break;
		default:
			std::cout << "Lexema não esperado [" << m_current.token << "]" << std::endl;
			break;
	}

    exit(1);
}
//<program> ::= program <id> ';'
// [ const <const> { <const> } ]
// [ var <var> { <var> } ]
// <block> '.'
void SyntaticAnalysis::procProgram(){
	eat(TT_PROG);
	eat(TT_VAR);
	eat(TT_SEMICOLON);
	if(m_current.type == TT_CONST){
		advance();
		procConst();
		while(m_current.type == TT_VAR){
			procConst();
		}
	}
	if(m_current.type == TT_VARI){
		advance();
		procVar();
		while(m_current.type == TT_VAR){
			procVar();
		}
	}
	procBlock();
	eat(TT_PERIOD);
}
// <const> ::= <id> '=' <value> ';'
void SyntaticAnalysis::procConst(){
	eat(TT_VAR);
	eat(TT_EQUAL);
	procValue();
	eat(TT_SEMICOLON);
}
//<var> ::= <id> { ',' <id> } [ '=' <value> ] ';'
void SyntaticAnalysis::procVar(){
	eat(TT_VAR);
	while(m_current.type == TT_COMMA){
		advance();
		eat(TT_VAR);
	}
	if(m_current.type == TT_EQUAL){
		advance();
		procValue();
	}
	eat(TT_SEMICOLON);
}
//<body> ::= <block> | <cmd>
void SyntaticAnalysis::procBody(){
	if(m_current.type == TT_BEGIN){
		procBlock();
	}else if(m_current.type == TT_VAR || m_current.type == TT_IF ||
			 m_current.type == TT_CASE || m_current.type == TT_WHILE ||
			 m_current.type == TT_FOR || m_current.type == TT_REPEAT ||
			 m_current.type == TT_WRITE ||m_current.type == TT_WRITELN||
			 m_current.type == TT_READLN ){

		procCmd();
	}else{
		showError();
	}

}

//<block> ::= begin [ <cmd> { ';' <cmd> } ] end
void SyntaticAnalysis::procBlock(){
	eat(TT_BEGIN);
	if(m_current.type == TT_VAR || m_current.type == TT_IF ||
			 m_current.type == TT_CASE || m_current.type == TT_WHILE ||
			 m_current.type == TT_FOR || m_current.type == TT_REPEAT ||
			 m_current.type == TT_WRITE || m_current.type == TT_WRITELN||
			 m_current.type == TT_READLN){

		procCmd();
		while (m_current.type == TT_SEMICOLON) {
			advance();
			procCmd();
		}
	}
	eat(TT_END);
}
//<cmd> ::= <assign> | <if> | <case> | <while> | <for> |
//<repeat> | <write> | <read>
void SyntaticAnalysis::procCmd(){
	if (m_current.type == TT_VAR){
		procAssign();
	}else if (m_current.type == TT_IF){
		procIf();
	}else if (m_current.type == TT_CASE){
		procCase();
	}else if (m_current.type == TT_WHILE){
		procWhile();
	}else if (m_current.type == TT_FOR){
		procFor();
	}else if (m_current.type == TT_REPEAT){
		procRepeat();
	}else if (m_current.type == TT_WRITE || m_current.type == TT_WRITELN ){
		procWrite();
	}else if (m_current.type == TT_READLN){
		procRead();
	}else{
		showError();
	}
}
//<assign> ::= <id> ':=' <expr>
void SyntaticAnalysis::procAssign(){
	eat(TT_VAR);
	eat(TT_ASSIGN);
	procExpr();

}
// <if> ::= if <boolexpr> then <body> [ else <body> ]
void SyntaticAnalysis::procIf(){
	eat(TT_IF);
	procBoolExpr();
	eat(TT_THEN);
	procBody();
	if(m_current.type == TT_ELSE){
		advance();
		procBody();
	}
}
// <case> ::= case <expr> of { <value> ':' <body> ';' }
// [ else <body> ';' ] end
void SyntaticAnalysis::procCase(){
	eat(TT_CASE);
	procExpr();
	eat(TT_OF);
	while(m_current.type == TT_INT || m_current.type == TT_FLOAT ||
		  m_current.type == TT_STRING ){

		procValue();
		eat(TT_POINTS);
		procBody();
		eat(TT_SEMICOLON);
	}
	if(m_current.type == TT_ELSE){
		advance();
		procBody();
		eat(TT_SEMICOLON);
	}
	eat(TT_END);
}
// <while> ::= while <boolexpr> do <body>
void SyntaticAnalysis::procWhile(){
	eat(TT_WHILE);
	procBoolExpr();
	eat(TT_DO);
	procBody();

}
// <repeat> ::= repeat [ <cmd> { ';' <cmd> } ] until <boolexpr>
void SyntaticAnalysis::procRepeat(){
	eat(TT_REPEAT);
	if(m_current.type == TT_VAR || m_current.type == TT_IF ||
	   m_current.type == TT_CASE || m_current.type == TT_WHILE ||
	   m_current.type == TT_FOR || m_current.type == TT_REPEAT ||
	   m_current.type == TT_WRITE || m_current.type == TT_READLN){

		procCmd();
		while(m_current.type == TT_SEMICOLON){
			advance();
			procCmd();
		}

	}
	eat(TT_UNTIL);
	procBoolExpr();
}
// <for> ::= for <id> ':=' <expr> to <expr> do <body>
void SyntaticAnalysis::procFor(){
	eat(TT_FOR);
	eat(TT_VAR);
	eat(TT_ASSIGN);
	procExpr();
	// eat(TT_TO);
	procExpr();
	eat(TT_DO);
	procBody();

}
// <write> ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
void SyntaticAnalysis::procWrite(){
	if(m_current.type == TT_WRITE || m_current.type == TT_WRITELN){
		if(m_current.type == TT_WRITE){
			eat(TT_WRITE);
		}else{
			eat(TT_WRITELN);
		}
		eat(TT_PAR1);
		if(m_current.type == TT_INT || m_current.type == TT_FLOAT ||
		   m_current.type == TT_STRING || m_current.type == TT_VAR){

			   procExpr();
			   while(m_current.type == TT_COMMA){
				   advance();
				   procExpr();
			   }
		}
		eat(TT_PAR2);
	}else{
		showError();
	}
}
// <read> ::= readln '(' <id> { ',' <id> } ')'
void SyntaticAnalysis::procRead(){
	eat(TT_READLN);
	eat(TT_PAR1);
	eat(TT_VAR);
	while(m_current.type == TT_COMMA){
		advance();
		eat(TT_VAR);
	}
	eat(TT_PAR2);
}
//<boolexpr> ::= [ not ] <cmpexpr> [ (and | or) <boolexpr> ]
void SyntaticAnalysis::procBoolExpr(){
	if(m_current.type == TT_NOT){
		eat(TT_NOT);
	}
	procCmpExpr();
		if(m_current.type == TT_AND || m_current.type == TT_OR ){
			advance();
			procBoolExpr();
		}
}
//<cmpexpr> ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr>
void SyntaticAnalysis::procCmpExpr(){
	procExpr();
	if(m_current.type == TT_EQUAL || m_current.type == TT_NOT_EQUAL ||
	   m_current.type == TT_LOWER || m_current.type == TT_GREATER ||
	   m_current.type == TT_LESS_EQUAL || m_current.type == TT_GREATER_EQUAL){
		   advance();
		   procExpr();
	}else{
		showError();
	}

}
// <expr> ::= <term> { ('+' | '-') <term> }
void SyntaticAnalysis::procExpr(){
	procTerm();
	while (m_current.type == TT_ADD || m_current.type == TT_SUB){
		if(m_current.type == TT_ADD){
			eat(TT_ADD);
		}else{
			eat(TT_SUB);
		}
		procTerm();

	}
}
//<term> ::= <factor> { ('*' | '/' | '%') <factor> }
void SyntaticAnalysis::procTerm(){
	procFactor();
	while (m_current.type == TT_MUL || m_current.type == TT_DIV ||
		   m_current.type == TT_MOD){
		if(m_current.type == TT_MUL){
			eat(TT_MUL);
		}else if(m_current.type == TT_DIV){
			eat(TT_DIV);
		}else{
			eat(TT_MOD);
		}
		procFactor();
	}
}
//<factor> ::= <value> | <id> | '(' <expr> ')'
void SyntaticAnalysis::procFactor(){
	if(m_current.type == TT_INT || m_current.type == TT_FLOAT ||
	   m_current.type == TT_STRING){

		procValue();
	}else if(m_current.type == TT_VAR){
		advance();
	}else if(m_current.type == TT_PAR1){
		advance();
		procExpr();
		eat(TT_PAR2);
	}
}
// <value> ::= <integer> | <real> | <string>
void SyntaticAnalysis::procValue(){
	if(m_current.type == TT_INT){
		eat(TT_INT);
	}else if(m_current.type == TT_FLOAT){
		eat(TT_FLOAT);
	}else if(m_current.type == TT_STRING){
		eat(TT_STRING);
	}else{
		showError();
	}
}
