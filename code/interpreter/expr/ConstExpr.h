#ifndef CONST_EXPR_H
#define CONST_EXPR_H

#include "Expr.h"

class ConstExpr : public Expr{

	public:
		//ConstExpr(int line, Value value);
		virtual ~ConstExpr();

		//Value expr();

	private:
		// Value value;
};


#endif
