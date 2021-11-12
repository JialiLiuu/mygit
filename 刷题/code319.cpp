#include "common.h"
#include <numeric>

class Solution
{
public:
    int bulbSwitch(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            (int)sqrt(i) * (int)sqrt(i) == i ? ans++ : ans;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    cout << S.bulbSwitch(9999999) << endl;
}