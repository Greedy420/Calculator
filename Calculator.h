#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "CommandProcessor.h"
#include <Conio.h>

class Calculator {
public:
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

    Calculator()
    {
        string input;
        vector<string> temp;
        size_t found1, found2, found3;
        bool exit = false;
        bool isLogic = false;
        bool isRoman = false;
        bool isInfix = false;
        char control;
        do {
            system("cls");
            getline(cin, input);
            found1 = input.find("Show Mem");
            found2 = input.find("Redo");
            found3 = input.find("Undo");
            temp.erase(temp.begin(), temp.end());
            if (input == "Set") {
                do {
                    PrintMenu();
                    control = getch();
                    switch (control) {
                    case '1':   PrintMenu1();
                                control = getch();
                                switch (control) {
                                case '1':   if (isRoman)
                                                CP.Process("set Std Roman");
                                            else
                                                CP.Process("set Std Arab");
                                            if (isInfix)
                                                CP.Process("set Infix Std");
                                            isLogic = false;
                                            cout << "Berhasil" << endl;
                                            system("pause");
                                            break;
                                case '2':   CP.Process("set Logic");
                                            if (isInfix)
                                                CP.Process("set Infix Logic");
                                            isLogic = true;
                                            cout << "Berhasil" << endl;
                                            system("pause");
                                            break;
                                case '3':   exit = true; break;
                                default:    break;
                                }
                                break;
                    case '2':   PrintMenu2();
                                control = getch();
                                switch (control) {
                                case '1':   CP.Process("set Prefix");
                                            isInfix = false;
                                            cout << "Berhasil" << endl;
                                            system("pause");
                                            break;
                                case '2':   CP.Process("set Postfix");
                                            isInfix = false;
                                            cout << "Berhasil" << endl;
                                            system("pause");
                                            break;
                                case '3':   if (isLogic)
                                                CP.Process("set Infix Logic");
                                            else
                                                CP.Process("set Infix Std");
                                            isInfix = true;
                                            cout << "Berhasil" << endl;
                                            system("pause");
                                            break;
                                case '4':   exit = true; break;
                                default :   break;
                                }
                                break;
                    case '3':   PrintMenu3();
                                control = getch();
                                switch (control) {
                                case '1':   if (isLogic) {
                                                cout << "Tidak berhasil" << endl;
                                                system("pause");
                                            }
                                            else {
                                                CP.Process("set Std Arab");
                                                isRoman = false;
                                                cout << "Berhasil" << endl;
                                                system("pause");
                                            }
                                            break;
                                case '2':   if (isLogic) {
                                                cout << "Tidak berhasil" << endl;
                                                system("pause");
                                            }
                                            else {
                                                CP.Process("set Std Roman");
                                                isRoman = true;
                                                cout << "Berhasil" << endl;
                                                system("pause");
                                            }
                                            break;
                                case '3':   exit = true; break;
                                default:    break;
                                }
                                break;
                    case '4':   exit = true; break;
                    default:    break;
                    }
                } while (!exit);
                exit = false;
            }
            else if (input == "Show All") {
                CP.Process(input);
            }
            else if (found1 == 0) {
                Tokenize(input, temp);
                CP.Process("Show Mem", atoi(temp[2].c_str()));
            }
            else if (input == "Start") {
                CP.Process("Start");
            }
            else if (input == "Save") {
                CP.Process("Save");
            }
            else if (found2 == 0) {
                Tokenize(input, temp);
                CP.Process("Redo", atoi(temp[1].c_str()));
            }
            else if (found3 == 0) {
                Tokenize(input, temp);
                CP.Process("Undo", atoi(temp[1].c_str()));
            }
            else if (input == "Exit")
                exit = true;
        } while (!exit);
    }

    void PrintMenu()
    {
        system("cls");
        cout << "Settings: " << endl;
        cout << "1. Set Calculator Mode" << endl;
        cout << "2. Set Expression Mode" << endl;
        cout << "3. Set Operand Type" << endl;
        cout << "4. Exit" << endl << endl;
    }

    void PrintMenu1()
    {
        system("cls");
        cout << "Set Calculator Mode: " << endl;
        cout << "1. Standard" << endl;
        cout << "2. Logic" << endl;
        cout << "3. Exit" << endl << endl;
    }

    void PrintMenu2()
    {
        system("cls");
        cout << "Set Expression Mode: " << endl;
        cout << "1. Prefix" << endl;
        cout << "2. Postfix" << endl;
        cout << "3. Infix" << endl;
        cout << "4. Exit" << endl << endl;
    }

    void PrintMenu3()
    {
        system("cls");
        cout << "Set Operand Type: " << endl;
        cout << "1. Arabic" << endl;
        cout << "2. Roman" << endl;
        cout << "3. Exit" << endl << endl;
    }

private:
    CommandProcessor CP;
};
#endif // CALCULATOR_H


