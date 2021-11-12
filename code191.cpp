#include "common.h"

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans += n % 2;
            n = n >> 1;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    uint32_t n = 00000000000000000000000000001011;
    cout << S.hammingWeight(n) << endl;
}