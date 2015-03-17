#ifndef STDOPTR_H
#define STDOPTR_H
#include "OperatorHandler.h"

class StdOptr : public OperatorHandler {
public:
    bool isOperator()
    {
        if (Operator == "+" || Operator == "-" || Operator == "*" || Operator == "/" || Operator == "div" || Operator == "mod")
            return true;
        else
            return false;
    }
};


#endif // STDOPTR_H
