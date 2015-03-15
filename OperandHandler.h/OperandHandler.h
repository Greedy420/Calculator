//Abstract Base Class
#ifndef OperandH
#define OperandH
#include <string>

class OperandHandler {
public :
	virtual void setvalue(std::string value) = 0;
	virtual float getvalue() const = 0;
};
#endif
