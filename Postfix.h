#ifndef POSTFIX_H
#define POSTFIX_H

#include "Input.h"

class Postfix : public Input {
public:
    vector<string> GetInput()
    {
        string input;
        getline(cin, input);
        Tokenize(input, Result);
        reverse(Result.begin(), Result.end());
        return Result;
    }
};

#endif // POSTFIX_H
