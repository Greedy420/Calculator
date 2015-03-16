#ifndef PREFIX_H
#define PREFIX_H

#include "Input.h"

class Prefix : public Input {
public:
    void GetInput()
    {
        string input;
        getline(cin, input);
        Tokenize(input, Result);
    }
};

#endif // PREFIX_H
