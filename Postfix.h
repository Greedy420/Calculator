#ifndef POSTFIX_H
#define POSTFIX_H

#include "EParser.h"

class Postfix : public EParser {
public:
    ~Postfix() {}

    void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
    {
        string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        string::size_type pos     = str.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos)
        {
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            lastPos = str.find_first_not_of(delimiters, pos);
            pos = str.find_first_of(delimiters, lastPos);
        }
    }

    vector<string> GetInput()
    {
        string input;
        vector<string> split;
        getline(cin, input);
        Tokenize(input, split);
        reverse(split.begin(), split.end());
        return split;
    }

    node<string> *Parse(vector<string>& input)
    {
        string container = input[0];
        input.erase(input.begin());
        if (container == "+" || container == "-" || container == "*" || container == "/") {
            node<string> *leaf;
            leaf = new node<string>;
            leaf->value = container;
            leaf->left = Parse(input);
            leaf->right = Parse(input);
            return leaf;
        }
        else {
            node<string> *leaf;
            leaf = new node<string>;
            leaf->value = container;
            leaf->left = NULL;
            leaf->right = NULL;
            return leaf;
        }
    }

    void PrintParser(node<string> *leaf)
    {
        if (leaf != NULL) {
            PrintParser(leaf->left);
            PrintParser(leaf->right);
            cout << leaf->value << " " ;
        }
    }
};

#endif // POSTFIX_H
