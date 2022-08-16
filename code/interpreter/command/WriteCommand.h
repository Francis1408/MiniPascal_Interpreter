#ifndef WRITE_COMMAND_H
#define WRITE_COMMAND_H

#include <list>
#include "Command.h"

class Expr;

class WriteCommand: public Command{

	public:
		WriteCommand(int line, bool writeln = false);
		virtual ~WriteCommand();

		void addExpr(Expr* expr);
		void execute();


	private:
		bool writeln;
		std::list<Expr*> exprs;
};


#endif
