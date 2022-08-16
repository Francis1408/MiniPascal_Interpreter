#include "SymbolTable.h"

SymbolTable::SymbolTable() {
	//Symbols
	m_symbols[";"]   = TT_SEMICOLON;
	m_symbols[","]   = TT_COMMA;
	m_symbols["."]   = TT_PERIOD;
	m_symbols[":="]  = TT_ASSIGN;
	m_symbols[":"]   = TT_POINTS;
	m_symbols["("]   = TT_PAR1;
	m_symbols[")"]   = TT_PAR2;

	//Logic Operators
	m_symbols["="]   = TT_EQUAL;
	m_symbols["<>"]  = TT_NOT_EQUAL;
	m_symbols["<"]   = TT_LOWER;
	m_symbols[">"]   = TT_GREATER;
	m_symbols["<="]  = TT_LESS_EQUAL;
	m_symbols[">="]  = TT_GREATER_EQUAL;

	// Conector Operators
	m_symbols["not"] = TT_NOT;
	m_symbols["and"] = TT_AND;
	m_symbols["or"]  = TT_OR;
	m_symbols["of"]  = TT_OF;

	// Arithmetic operators
	m_symbols["+"]   = TT_ADD;
	m_symbols["-"]   = TT_SUB;
	m_symbols["*"]   = TT_MUL;
	m_symbols["/"]   = TT_DIV;
	m_symbols["%"]   = TT_MOD;

	//Keywords
	m_symbols["program"]= TT_PROG;
	m_symbols["begin"]  = TT_BEGIN;
	m_symbols["end"]    = TT_END;
	m_symbols["if"]     = TT_IF;
	m_symbols["else"]   = TT_ELSE;
	m_symbols["then"]   = TT_THEN;
	m_symbols["case"]   = TT_CASE;
	m_symbols["while"]  = TT_WHILE;
	m_symbols["repeat"] = TT_REPEAT;
	m_symbols["until"]  = TT_UNTIL;
	m_symbols["for"]    = TT_FOR;
	m_symbols["write"]  = TT_WRITE;
	m_symbols["writeln"]= TT_WRITELN;
	m_symbols["readln"] = TT_READLN;
	m_symbols["do"]     = TT_DO;
	m_symbols["true"]   = TT_TRUE;
	m_symbols["false"]  = TT_FALSE;
	m_symbols["to"]  = 	  TT_TO;


	//Others
	m_symbols["const"]  = TT_CONST;
	m_symbols["var"]    = TT_VARI;


}

SymbolTable::~SymbolTable() {
}

bool SymbolTable::contains(const std::string& token) const {
	return m_symbols.find(token) != m_symbols.end();
}

enum TokenType SymbolTable::find(const std::string& token){
	return this->contains(token) ?
				m_symbols[token] : TT_VAR;
}
