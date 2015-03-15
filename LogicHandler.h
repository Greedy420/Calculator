//Operand Handler Logic
#include "OperandHandler.h"
#ifndef LHandler_H
#define LHandler_H
class LogicHandler : public OperandHandler {
public :
	LogicHandler();
	LogicHandler(const LogicHandler& LH);
    ~LogicHandler();
    LogicHandler& operator=(const LogicHandler& LH);
	void setvalue(std::string value);
	float getvalue() const;

private :
    float value;
};

#endif
