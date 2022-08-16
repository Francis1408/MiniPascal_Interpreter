#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>

enum TokenType{
	// Specials
	TT_UNEXPECTED_EOF = -2,
	TT_INVALID_TOKEN  = -1,
	TT_END_OF_FILE    =  0,

	//Symbols
	TT_SEMICOLON,	  // ;
	TT_COMMA,         // ,
	TT_PERIOD,		  // .
	TT_ASSIGN,        // :=
	TT_POINTS,        // :
	TT_PAR1,          // (
	TT_PAR2,          // )

	//Logic Operators
	TT_EQUAL,		  // =
	TT_NOT_EQUAL,     // <>
	TT_LOWER,         // <
	TT_GREATER,       // >
	TT_LESS_EQUAL,    // <=
	TT_GREATER_EQUAL, // >=

	// Conector Operators
	TT_NOT,           // not
	TT_AND,           // and
	TT_OR,            // or
	TT_OF, 			  //of

	// Arithmetic operators
	TT_ADD,           // +
	TT_SUB,           // -
	TT_MUL,           // *
	TT_DIV,           // /
	TT_MOD,           // %

	//Keywords
	TT_PROG,		  // program
	TT_BEGIN,		  // begin
	TT_END,			  // end
	TT_IF,            // if
	TT_ELSE,          // else
	TT_THEN,          // then
	TT_CASE,          // case
	TT_WHILE,         // while
	TT_REPEAT,        // repeat
	TT_UNTIL,         // until
	TT_FOR,           // for
	TT_WRITE,         // write
	TT_WRITELN,       // writeln
	TT_READLN,        // readln
	TT_DO,			  // do
	TT_TRUE,          // true
	TT_FALSE,         // false
	TT_TO,			  // to


	//Others
	TT_VAR,           // varible
	TT_INT,           // int
	TT_FLOAT,         // float
	TT_STRING,        // string
	TT_BOOL,          // boolean
	TT_CONST,         // const
	TT_VARI,          // var

};

inline std::string tt2str(enum TokenType type) {

	switch (type) {
		// Specials
		case TT_UNEXPECTED_EOF:
			return "UNEXPECTED_EOF";
		case TT_INVALID_TOKEN:
			return "INVALID_TOKEN";
		case TT_END_OF_FILE:
			return "END_OF_FILE";

		//Symbols
		case TT_SEMICOLON:
			return "SEMICOLON";
		case TT_COMMA:
			return "COMMA";
		case TT_PERIOD:
			return "PERIOD";
		case TT_ASSIGN:
			return "ASSIGN";
		case TT_POINTS:
			return "POINTS";
		case TT_PAR1:
			return "PAR1";
		case TT_PAR2:
			return "PAR2";

		//Logic Operators
		case TT_EQUAL:
			return "EQUAL";
		case TT_NOT_EQUAL:
			return "NOT_EQUAL";
		case TT_LOWER:
			return  "LOWER";
		case TT_GREATER:
			return  "GREATER";
		case TT_LESS_EQUAL:
			return  "LESS_EQUAL";
		case TT_GREATER_EQUAL:
			return "GREATER_EQUAL";

		// Conector Operators
		case TT_NOT:
			return "NOT";
		case TT_AND:
			return "AND";
		case TT_OR:
			return "OR";
		case TT_OF:
			return "OF";

		// Arithmetic operators
		case TT_ADD:
			return "ADD";
		case TT_SUB:
			return "SUB";
		case TT_MUL:
			return "MUL";
		case TT_DIV:
			return "DIV";
		case TT_MOD:
			return "MOD";

		//Keywords
		case TT_PROG:
			return "PROGRAM";
		case TT_BEGIN:
			return "BEGIN";
		case TT_END:
			return "END";
		case TT_IF:
			return "IF";
		case TT_ELSE:
			return "ELSE";
		case TT_THEN:
			return "THEN";
		case TT_CASE:
			return "CASE";
		case TT_WHILE:
			return "WHILE";
		case TT_REPEAT:
			return "REPEAT";
		case TT_UNTIL:
			return "UNTIL";
		case TT_FOR:
			return "FOR";
		case TT_WRITE:
			return "WRITE";
		case TT_WRITELN:
			return "WRITELN";
		case TT_READLN:
			return "READLN";
		case TT_DO:
			return "DO";
		case TT_TRUE:
			return "TRUE";
		case TT_FALSE:
			return "FALSE";
		case TT_TO:
			return "TO";

		//Others
		case TT_VAR:
			return "VAR";
		case TT_INT:
			return "INT";
		case TT_FLOAT:
			return "FLOAT";
		case TT_STRING:
			return "STRING";
		case TT_BOOL:
			return "BOOL";
		case TT_CONST:
			return "CONST";
		case TT_VARI:
			return "VARI";
		default:
			throw std::string("invalid token type");

	}
}

#endif
