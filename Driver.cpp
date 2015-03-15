#include "Prefix.h"
#include "Postfix.h"

int main()
{
    Prefix A;
    Postfix B;
    vector<string> split;
    split = B.GetInput();
    B.T.root = A.Parse(split);
    B.PrintParser(B.T.root);
    return 0;
}
