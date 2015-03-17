#ifndef PREFIX_H
#define PREFIX_H

#include "Input.h"

class Prefix : public Input {
public:
    void GetInput(string input)
    {
        Result.erase(Result.begin(), Result.end());
        Tokenize(input, Result);
    }
};

#endif // PREFIX_H
