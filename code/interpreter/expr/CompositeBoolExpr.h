#ifndef COMPOSITE_BOOL_EXPR_H
#define COMPOSITE_BOOL_EXPR_H

#include "BoolExpr.h"

class CompositeBoolExpr : public BoolExpr{

	public:

	enum Op {
			AND,
			OR
		};

		CompositeBoolExpr(int line, BoolExpr* m_left, enum Op op, BoolExpr* m_right);
		virtual ~CompositeBoolExpr();

		int getLine();
		bool expr();

	private:
		BoolExpr* m_left;
		enum Op m_op;
		BoolExpr* m_right;


};


#endif
