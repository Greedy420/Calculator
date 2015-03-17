#ifndef EPARSER_H
#define EPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"

using namespace std;

class EParser {
public:
    ~EParser()
    {}

    void StartParse(vector<string>& input)
    {
        T.root= Parse(input);
    }

    node<string> *Parse(vector<string>& input) // Membaca string prefix dan masukkan ke tree
    {
        string container = input[0];
        input.erase(input.begin());
        if (container == "+" || container == "-" || container == "*" || container == "/" || container == "div" || container == "mod") {
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

    void PrintPrefix(node<string> *leaf)
    {
        if (leaf != NULL) {
            cout << leaf->value << " " ;
            PrintPrefix(leaf->left);
            PrintPrefix(leaf->right);
        }
    }

    void PrintPostfix(node<string> *leaf)
    {
        if (leaf != NULL) {
            PrintPostfix(leaf->left);
            PrintPostfix(leaf->right);
            cout << leaf->value << " " ;
        }
    }

    void PrintInfix(node<string> *leaf)
    {
        if (leaf != NULL) {
            PrintInfix(leaf->left);
            cout << leaf->value << " " ;
            PrintInfix(leaf->right);
        }
    }

    Tree<string> T;
};

#endif // EPARSER_H
