#ifndef STDCALC_H
#define STDCALC_H

#include "Calculate.h"

class StdCalc : public Calculate {
public:
    StdCalc()
    {
        Opr = new AngkaHandler;
        Optr = new StdOptr;
    }

    ~StdCalc() {}

    float Calc(node<string> *leaf)
    {
        if (leaf != NULL) {
            Optr->SetOperator(leaf->value);
            if (Optr->isOperator()) {
                if (Optr->GetOperator() == "+")
                    return (Calc(leaf->left) + Calc(leaf->right));
                else if (Optr->GetOperator() == "-")
                    return (Calc(leaf->left) - Calc(leaf->right));
                else if (Optr->GetOperator() == "*")
                    return (Calc(leaf->left) * Calc(leaf->right));
                else if (Optr->GetOperator() == "/")
                    return (Calc(leaf->left) / Calc(leaf->right));
                else if (Optr->GetOperator() == "div") {
                    div_t divresult;
                    divresult = div((int)Calc(leaf->left), (int)Calc(leaf->right));
                    return divresult.quot;
                }
                else if (Optr->GetOperator() == "mod")
                    return ((int)Calc(leaf->left) % (int)Calc(leaf->right));
            }
            else {
                Opr->setvalue(leaf->value);
                return Opr->getvalue();
            }
        }
    }
};

#endif
