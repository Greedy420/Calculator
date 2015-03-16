#include "Prefix.h"
#include "Postfix.h"
#include "Infix.h"
#include "EParser.h"
#include "StdCalc.h"
#include "AngkaHandler.h"
#include "RomanHandler.h"
#include "LogicHandler.h"
#include "MemoryHandler.h"

int main()
{
    Infix In;
    Postfix Post;
    Prefix Pre;
    EParser EXP;
    StdCalc C;
    vector<string> input;
    AngkaHandler A1;
    RomanHandler B1;
    LogicHandler C1;
    MemoryHandler M;

    In.GetInput();
    input = In.GetResult();
    EXP.StartParse(input);

    C.StartCalc(EXP.T.root);
    cout << C.GetCalcResult() << endl;

    A1.setvalue("420.42");
    B1.setvalue("MMD");
    C1.setvalue("true");
    cout << A1.getvalue() << endl;
    cout << B1.getvalue() << endl;
    cout << C1.getvalue() << endl;

    M.Push("BOSS NIGGA");
    M.Push("4 NIGGA");
    M.Push("3 NIGGA");
    M.Push("2 NIGGA");
    M.Push("1 NIGGA");
    M.PrintNMem(3);
    cout << endl;
    M.PrintAll();
    M.SaveMem();

    return 0;
}
