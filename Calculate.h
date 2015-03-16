#ifndef CALCULATE_H
#define CALCULATE_H

#include "AngkaHandler.h"
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
    OperandHandler *O;
};

#endif // CALCULATE_H
