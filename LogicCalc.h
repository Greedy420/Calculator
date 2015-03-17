#ifndef LOGICCALC_H
#define LOGICCALC_H

#include "Calculate.h"

class LogicCalc : public Calculate {
public:
    LogicCalc()
    {
        Opr = new LogicHandler;
        Optr = new LogicOptr;
    }

    ~LogicCalc() {}

    float Calc(node<string> *leaf)
    {
        if (leaf != NULL) {
            Optr->SetOperator(leaf->value);
            if (Optr->isOperator()) {
                if (Optr->GetOperator() == "AND")
                    return (Calc(leaf->left) && Calc(leaf->right));
                else if (Optr->GetOperator() == "OR")
                    return (Calc(leaf->left) || Calc(leaf->right));
                else if (Optr->GetOperator() == "NOT")
                    return !(Calc(leaf->left));
            }
            else {
                Opr->setvalue(leaf->value);
                return Opr->getvalue();
            }
        }
    }
};

#endif

