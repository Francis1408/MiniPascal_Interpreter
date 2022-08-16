#ifndef NOT_BOOL_EXPR_H
#define NOT_BOOL_EXPR_H

#include "BoolExpr.h"

class BoolExpr;

class NotBoolExpr : public BoolExpr{

	public:
		NotBoolExpr(int line, BoolExpr* expr);
		virtual ~NotBoolExpr();

		int getLine();
		bool expr();

	private:
		BoolExpr* expr;

};

#endif
