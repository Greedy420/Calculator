#ifndef LOGICOPTR_H
#define LOGICOPTR_H
#include "OperatorHandler.h"

class LogicOptr : public OperatorHandler {
public:
    bool isOperator()
    {
        if (Operator == "AND" || Operator == "OR" || Operator == "NOT")
            return true;
        else
            return false;
    }
};


#endif
