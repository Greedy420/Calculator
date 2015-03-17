#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H
#include "Prefix.h"
#include "Postfix.h"
#include "Infix.h"
#include "EParser.h"
#include "StdCalc.h"
#include "LogicCalc.h"
#include "MemoryHandler.h"
#include <sstream>

class CommandProcessor {
public:
    CommandProcessor()
    {
        C = new StdCalc(1, 1);
        In = new Prefix;
    }

    void Redo(int n)
    {
        if (CStack.isEmpty() == 1)
            cout << "Nothing to redo" << endl;
        else {
            int i = n;
            string dump;
            Stack<string> temp, temp2;
            while (CStack.isEmpty() != 1 && i > 0 ) {
                CStack.Pop(dump);
                temp.Push(dump);
                i--;
                cout << dump << endl;
            }
            while(temp.isEmpty() != 1) {
                temp.Pop(dump);
                temp2.Push(dump);
            }
            while(temp2.isEmpty() != 1) {
                temp2.Pop(dump);
                CStack.Push(dump);
                Process(dump);
            }
        }
    }

    void Undo(int n)
    {
        if (CStack.isEmpty() == 1)
            cout << "Nothing to undo" << endl;
        else {
            int i = n;
            string dump;
            while (CStack.isEmpty() != 1 && i > 0 ) {
                CStack.Pop(dump);
                i--;
            }
            cout << "Undo successful" << endl;
        }
    }

    void Process(string command, int n)
    {
        if (command == "Show Mem") {
            Mem.PrintNMem(n);
            system("pause");
        }
        else if (command == "Redo") {
            Redo(n);
            ostringstream convert;
            convert << n;
            Mem.PushToMem(command + " " + convert.str());
            system("pause");
        }
        else if (command == "Undo") {
            Undo(n);
            ostringstream convert;
            convert << n;
            Mem.PushToMem(command + " " + convert.str());
            system("pause");
        }
    }

    void Process(string command)
    {
        if (command == "Show All") {
            Mem.PrintAll();
            system("pause");
        }
        else if (command == "Save") {
            Mem.SaveMem();
            system("pause");
        }
        else {
            if (command == "Start") {
                cout << "Input = ";
                string temp;
                getline(cin, temp);
                In->GetInput(temp);
                input = In->GetResult();
                EXP.StartParse(input);
                C->StartCalc(EXP.T.root);
                cout << "Result = " << C->GetCalcResult() << endl;
                ostringstream convert;
                convert << C->GetCalcResult();
                Mem.PushToMem(temp + " = " + convert.str());
                CStack.Push(temp + " = " + convert.str());
                system("pause");
            }
            else {
                Mem.PushToMem(command);
                CStack.Push(command);
                if (command == "set Prefix") {
                    delete In;
                    In = new Prefix;
                }
                else if (command == "set Postfix") {
                    delete In;
                    In = new Postfix;
                }
                else if (command == "set Infix Std") {
                    delete In;
                    In = new Infix(1);
                }
                else if (command == "set Infix Logic") {
                    delete In;
                    In = new Infix(2);
                }
                else if (command == "set Logic") {
                    delete C;
                    C = new LogicCalc;
                }
                else if (command == "set Std Arab") {
                    delete C;
                    C = new StdCalc(1, 1);
                }
                else if (command == "set Std Roman") {
                    delete C;
                    C = new StdCalc(2, 1);
                }
            }
        }
    }
private:
    Calculate *C;
    Input *In;
    EParser EXP;
    vector<string> input;
    MemoryHandler Mem;
    Stack<string> CStack;
};

#endif // COMMANDPROCESSOR_H


