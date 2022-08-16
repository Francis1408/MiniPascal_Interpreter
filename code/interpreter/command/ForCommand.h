#ifndef FOR_COMMAND_H
#define FOR_COMMAND_H

#include "Command.h"

class Expr;

class ForCommand : public Command{

	public:
		//ForCommand(int line, Variable* var, Expr* src, Expr* dst);
		virtual ~ForCommand();

		void execute();

	private:
		//Variable* var;
		Expr* src;
		Expr* dst;
		Command* cmd;
};

#endif
