#ifndef INT_EXPR_H
#define INT_EXPR_H

class Expr{
	public:
		virtual ~Expr(){}

		int line() const {return m_line;}
		// Value expr();

	protected:
		Expr(int line) : m_line(line){}

	private:
		int m_line;

};

#endif
