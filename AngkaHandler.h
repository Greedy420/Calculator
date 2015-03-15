//Operand Handler Angka
#include "OperandHandler.h"
#ifndef AHandler_H
#define AHandler_H
class AngkaHandler : public OperandHandler {
public :
	AngkaHandler();
	AngkaHandler(const AngkaHandler& AH);
    ~AngkaHandler();
    AngkaHandler& operator=(const AngkaHandler& AH);
	void setvalue(std::string value);
	float getvalue() const;

private :
    float value;
};

#endif
