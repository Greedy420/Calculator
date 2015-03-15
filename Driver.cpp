#include "Prefix.h"
#include "Postfix.h"
#include "Infix.h"
#include "AngkaHandler.h"
#include "RomanHandler.h"
#include "LogicHandler.h"
#include <iostream>

using namespace std;
int main()
{
    Infix A;
    Prefix B;
    AngkaHandler A1;
    RomanHandler B1;
    LogicHandler C1;
    
    vector<string> split;
    split = A.GetInput();
    A.T.root = A.Parse(split);
    B.PrintParser(A.T.root);
    
    A1.setvalue("420.42");
    B1.setvalue("MMD");
    C1.setvalue("true");
    cout << A1.getvalue() << endl;
    cout << B1.getvalue() << endl;
    cout << C1.getvalue() << endl;
    return 0;
}
