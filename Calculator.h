#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "CommandProcessor.h"
#include <Conio.h>

class Calculator {
public:
    Calculator()
    {
        char control, dummy;
        bool isLogic = false;
        bool isRoman = false;
        bool isInfix = false;
        bool exit = false;
        do {
            PrintMenu();
            control = getch();
            switch (control) {
            case '1': CP.Process("start"); break;
            case '2': PrintMenu2();
                    control = getch();
                    switch (control) {
                    case '1': PrintMenu21();
                            control = getch();
                            switch (control) {
                            case '1': if (isRoman)
                                        CP.Process("set Roman");
                                    else
                                        CP.Process("set Arab");
                                    if (isInfix)
                                        CP.Process("set Infix Std");
                                    isLogic = false;
                                    break;
                            case '2': CP.Process("set Logic");
                                    if (isInfix)
                                        CP.Process("set Infix Logic");
                                    isLogic = true;
                                    break;
                            default: break;
                            }
                            break;
                    case '2': PrintMenu22();
                            control = getch();
                            switch (control) {
                            case '1': CP.Process("set Prefix");
                                    isInfix = false;
                                    break;
                            case '2': CP.Process("set Postfix");
                                    isInfix = false;
                                    break;
                            case '3': if (isLogic)
                                        CP.Process("set Infix Logic");
                                    else
                                        CP.Process("set Infix Std");
                                    isInfix = true;
                                    break;
                            default: break;
                            }
                            break;
                    case '3': PrintMenu23();
                            control = getch();
                            switch (control) {
                            case '1': if (isLogic) {
                                        cout << "Tidak bisa" << endl;
                                        system("pause");
                                    }
                                    else {
                                        CP.Process("set Arab");
                                        isRoman = false;
                                    }
                                    break;
                            case '2': if (isLogic) {
                                        cout << "Tidak bisa" << endl;
                                        system("pause");
                                    }
                                    else {
                                        CP.Process("set Roman");
                                        isRoman = true;
                                    }
                                    break;
                            default: break;
                            }
                    default: break;
                    }
                    break;
            case '3': exit = true; break;
            default: break;
            }
        } while (!exit);
    }

    void PrintMenu()
    {
        system("cls");
        cout << "Main Menu: " << endl;
        cout << "1. Start Calculator" << endl;
        cout << "2. Settings" << endl;
        cout << "3. Exit" << endl << endl;
    }

    void PrintMenu2()
    {
        system("cls");
        cout << "Settings: " << endl;
        cout << "1. Set Calculator Mode" << endl;
        cout << "2. Set Expression Mode" << endl;
        cout << "3. Set Operand Type" << endl;
        cout << "4. Exit" << endl << endl;
    }

    void PrintMenu21()
    {
        system("cls");
        cout << "Set Calculator Mode: " << endl;
        cout << "1. Standard" << endl;
        cout << "2. Logic" << endl;
        cout << "3. Exit" << endl << endl;
    }

    void PrintMenu22()
    {
        system("cls");
        cout << "Set Expression Mode: " << endl;
        cout << "1. Prefix" << endl;
        cout << "2. Postfix" << endl;
        cout << "3. Infix" << endl;
        cout << "4. Exit" << endl << endl;
    }

    void PrintMenu23()
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


