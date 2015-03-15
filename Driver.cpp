#include "Prefix.h"
#include "Postfix.h"
#include "Infix.h"

int main()
{
    Infix A;
    Prefix B;
    vector<string> split;
    split = A.GetInput();
    A.T.root = A.Parse(split);
    B.PrintParser(A.T.root);
    return 0;
}
