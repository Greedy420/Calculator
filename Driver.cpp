#include "Prefix.h"
#include "Postfix.h"
#include "Infix.h"
#include "EParser.h"
#include "AngkaHandler.h"
#include "RomanHandler.h"
#include "LogicHandler.h"

// gak perlu iostream & std, udah ada di include entah yg mana

int main()
{
    Infix In;
    Prefix Pre;
    Postfix Post;
    vector<string> input;
    AngkaHandler A1;
    RomanHandler B1;
    LogicHandler C1;
    
    input = Pre.GetInput();
    EXP.T.SetRoot(EXP.Parse(input));
    EXP.PrintPrefix(EXP.T.GetRoot());
    
    A1.setvalue("420.42");
    B1.setvalue("MMD");
    C1.setvalue("true");
    cout << A1.getvalue() << endl;
    cout << B1.getvalue() << endl;
    cout << C1.getvalue() << endl;
    return 0;
}
