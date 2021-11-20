#include "common.h"

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        return str.substr(n) + str.substr(0, n);
    }
};

int main()
{
    Solution S;
    cout << S.LeftRotateString("qwerety", 2) << endl;
}