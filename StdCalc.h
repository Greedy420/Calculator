#ifndef STDCALC_H
#define STDCALC_H

#include "Calculate.h"

class StdCalc : public Calculate {
public:
    StdCalc()
    {
        O = new AngkaHandler;
    }

    ~StdCalc() {}

    float Calc(node<string> *leaf)
    {
        if (leaf != NULL) {
            string temp = leaf->value;
            if (temp == "+" || temp == "-" || temp == "*" || temp == "/") {
                if (temp == "+")
                    return (Calc(leaf->left) + Calc(leaf->right));
                else if (temp == "-")
                    return (Calc(leaf->left) - Calc(leaf->right));
                else if (temp == "*")
                    return (Calc(leaf->left) * Calc(leaf->right));
                else if (temp == "/")
                    return (Calc(leaf->left) / Calc(leaf->right));
            }
            else {
                O->setvalue(temp);
                return O->getvalue();
            }
        }
    }
};

#endif
