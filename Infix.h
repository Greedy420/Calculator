#ifndef INFIX_H
#define INFIX_H

#include "EParser.h"

class Infix : public EParser {
public:
    ~Infix() {}

    void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
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

    int Precedence(string opr)
    {
        if (opr == "*" || opr == "/")
            return 2;
        else // (opr == "+" || opr == "-")
            return 1;
    }

    vector<string> GetInput()
    {
        string input;
        string temp;
        string temp2;
        vector<string> split;
        vector<string> split_out;
        Stack<string> s;
        getline(cin, input);
        Tokenize(input, split);

        reverse(split.begin(), split.end());
        for (int i = 0; i < split.size(); i++) {
            if (split[i] == "(")
                split[i] = ")";
            else if (split[i] == ")")
                split[i] = "(";
        }

        while (!split.empty()) {
            temp = split.front();
            split.erase(split.begin());
            if (temp == "+" || temp == "-" || temp == "*" || temp == "/") {
                label :
                    if (s.isEmpty() == 1)
                        s.Push(temp);
                    else {
                        if (s.GetTop() == "(")
                            s.Push(temp);
                        else if (Precedence(s.GetTop()) < Precedence(temp)) {
                            s.Push(temp);
                        }
                        else if (Precedence(s.GetTop()) == Precedence(temp)) {
                            s.Pop(temp2);
                            split_out.push_back(temp2);
                            s.Push(temp);
                        }
                        else if (Precedence(s.GetTop()) > Precedence(temp)) {
                            s.Pop(temp2);
                            split_out.push_back(temp2);
                            goto label;
                        }
                    }
            }
            else if (temp == "(") {
                s.Push(temp);
            }
            else if (temp == ")") {
                s.Pop(temp2);
                while (temp2 != "(") {
                    split_out.push_back(temp2);
                    s.Pop(temp2);
                }
            }
            else
                split_out.push_back(temp);
        }
        while (s.isEmpty() == 0) {
            s.Pop(temp);
            split_out.push_back(temp);
        }

        reverse(split_out.begin(), split_out.end());
        return split_out;
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
            cout << leaf->value << " " ;
            PrintParser(leaf->right);
        }
    }
};

#endif // INFIX_H
