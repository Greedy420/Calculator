#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Stack.h"

using namespace std;

class Input {
public:
    ~Input() {}

    virtual void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ") // Untuk split string
    {
        string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        string::size_type pos = str.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos)
        {
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            lastPos = str.find_first_not_of(delimiters, pos);
            pos = str.find_first_of(delimiters, lastPos);
        }
    }

    virtual vector<string> GetInput() = 0; // Baca input user sesuai notasi dan return sebuah vector

protected:
    vector<string> Result;
};

#endif // INPUT_H
