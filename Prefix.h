#ifndef PREFIX_H
#define PREFIX_H

#include "Input.h"

class Prefix : public Input {
public:
    vector<string> GetInput()
    {
        string input;
        getline(cin, input);
        Tokenize(input, Result);
        return Result;
    }
};

#endif // PREFIX_H
