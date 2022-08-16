#ifndef BOOL_EXPR_H
#define BOOL_EXPR_H

class BoolExpr {
	public:
		virtual ~BoolExpr() {}

		int line() const { return m_line; }
		bool expr();

	protected:
		BoolExpr(int line) : m_line(line) {}

	private:
		int m_line;

};

#endif
