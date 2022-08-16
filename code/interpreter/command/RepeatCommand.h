#ifndef REPEAT_COMMAND_H
#define REPEAT_COMMAND_H

#include "Command.h"
#include <list>

class BoolExpr;

class RepeatCommand: public Command{

	public:
		RepeatCommand(int line, Command* cmds, BoolExpr* cond);
		virtual ~RepeatCommand();

		void execute();

	private:
		std::list<Command*> cmds;
		BoolExpr* cond;

};

#endif
