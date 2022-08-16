#ifndef READ_COMMAND_H
#define READ_COMMAND_H

#include "Command.h"
#include <list>

class Expr;

class ReadCommand : public Command{

	public:
	ReadCommand(int line);
	virtual ~ReadCommand();

	//addVariable(Variable* var);
	void execute();

	private:
	//std::list<Variable*> vars;


};

#endif
