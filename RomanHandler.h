//Operand Handler Romawi
#include "OperandHandler.h"
#ifndef RHandler_H
#define RHandler_H

class RomanHandler : public OperandHandler {
public :
	RomanHandler();
	RomanHandler(const RomanHandler& RH);
    ~RomanHandler();
    RomanHandler& operator=(const RomanHandler& RH);
	void setvalue(std::string value);
	float getvalue() const;

private :
    float value;
};

#endif
