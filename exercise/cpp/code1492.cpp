#include "../include/common.h"

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> his;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (i != sqrt(n))
                    his.insert(his.begin(), n / i);
                k--;
            }
            if (k == 0)
                return i;
        }
        return k > his.size() ? -1 : his[k - 1];
    }
};

int main()
{
    Solution S;
    cout << S.kthFactor(4, 3) << endl;
}