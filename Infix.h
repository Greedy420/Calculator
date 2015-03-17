#ifndef INFIX_H
#define INFIX_H

#include "Input.h"

class Infix : public Input {
public:
    Infix(int x)
    {
       switch (x) {
       default:
       case 1:  Optr = new StdOptr; break;
       case 2:  Optr = new LogicOptr; break;
       }

    }

    int Precedence(string opr)
    {
        if (opr == "NOT")
            return 3;
        else if (opr == "*" || opr == "/" || opr == "div" || opr == "mod" || opr == "AND")
            return 2;
        else
            return 1;
    }

    void GetInput(string input)
    {
        string temp, temp2;
        vector<string> split;
        Stack<string> s;
        Tokenize(input, split);

        Result.erase(Result.begin(), Result.end());
        reverse(split.begin(), split.end());
        for (int i = 0; i < split.size(); i++) {
            if (split[i] == "(")
                split[i] = ")";
            else if (split[i] == ")")
                split[i] = "(";
        }

        while (!split.empty()) {
            temp = split.front();
            Optr->SetOperator(temp);
            split.erase(split.begin());
            if (Optr->isOperator()) {
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
                            Result.push_back(temp2);
                            s.Push(temp);
                        }
                        else if (Precedence(s.GetTop()) > Precedence(temp)) {
                            s.Pop(temp2);
                            Result.push_back(temp2);
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
                    Result.push_back(temp2);
                    s.Pop(temp2);
                }
            }
            else
                Result.push_back(temp);
        }
        while (s.isEmpty() == 0) {
            s.Pop(temp);
            Result.push_back(temp);
        }

        reverse(Result.begin(), Result.end());
    }
};

#endif // INFIX_H
