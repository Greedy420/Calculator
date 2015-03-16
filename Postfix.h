#ifndef POSTFIX_H
#define POSTFIX_H

#include "Input.h"

class Postfix : public Input {
public:
    void GetInput()
    {
        string input;
        getline(cin, input);
        Tokenize(input, Result);
        reverse(Result.begin(), Result.end());
    }
};

#endif // POSTFIX_H
