#ifndef CALCULATE_H
#define CALCULATE_H

#include "AngkaHandler.h"
#include "RomanHandler.h"
#include "LogicHandler.h"
#include "StdOptr.h"
#include "LogicOptr.h"
#include "Tree.h"

class Calculate {
public:
    ~Calculate() {}

    float GetCalcResult()
    {
        return CalcResult;
    }

    void StartCalc(node<string> *leaf)
    {
        CalcResult = Calc(leaf);
    }

    virtual float Calc(node<string> *leaf) = 0;

protected:
    float CalcResult;
    OperandHandler *Opr;
    OperatorHandler *Optr;
};

#endif // CALCULATE_H
