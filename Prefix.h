#ifndef PREFIX_H
#define PREFIX_H

#include "EParser.h"

class Prefix : public EParser {
public:
    ~Prefix() {}

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
            cout << leaf->value << " " ;
            PrintParser(leaf->left);
            PrintParser(leaf->right);
        }
    }
};

#endif // PREFIX_H
