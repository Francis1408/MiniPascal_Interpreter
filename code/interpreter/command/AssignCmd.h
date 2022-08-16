#ifndef ASSING_COMMAND_H
#define ASSING_COMMAND_H

#include "Command.h"

class Expr;

class AssingCommand: public Command {

	public:
		//AssingCommand(int line, Variable* m_left, Expr* m_right);
		virtual ~AssingCommand();

		void execute();

	private:
		//Variable* m_left;
		Expr* m_right;

};

#endif
