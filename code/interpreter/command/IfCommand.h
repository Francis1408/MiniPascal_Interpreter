#ifndef IF_COMMAND_H
#define IF_COMMAND_H

#include "Command.h"

class BoolExpr;

class IfCommand : public Command{

	public:
		IfCommand(int line, BoolExpr* cond, Command* thenCmds);
		virtual ~IfCommand();

		void setElseCommands(Command* elseCmds);
		void execute();

	private:
		BoolExpr* cond;
		Command* thenCmds;
		Command* elseCmds;
};


#endif
