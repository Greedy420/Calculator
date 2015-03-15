#ifndef EPARSER_H
#define EPARSER_H

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "Tree.h"
#include "Stack.h"

using namespace std;

class EParser {
public:
    virtual ~EParser() {}
    virtual void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ") = 0;
    virtual vector<string> GetInput() = 0;
    virtual node<string> *Parse(vector<string>& input) = 0;
    virtual void PrintParser(node<string> *leaf) = 0;

    Tree<string> T;
};

#endif // EPARSER_H
