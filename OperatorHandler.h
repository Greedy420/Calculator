#ifndef OPERATORHANDLER_H
#define OPERATORHANDLER_H
#include <string>

using namespace std;

class OperatorHandler {
public:
    ~OperatorHandler() {}

    void SetOperator(string optr)
    {
        Operator = optr;
    }

    string GetOperator()
    {
        return Operator;
    }

    virtual bool isOperator() = 0;

protected:
    string Operator;
};

#endif // OPERATORHANDLER_H
