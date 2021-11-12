#include "common.h"
//超时

class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        int ans = 0;
        bool flag = false;
        for (int i = 0; i < data.size() - 1; i++)
        {
            for (int j = 0; j < data.size() - i - 1; j++)
            {
                if (data[j] > data[j + 1])
                {
                    swap(data[j], data[j + 1]);
                    ans++;
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    cout << S.InversePairs({1, 2, 4, 3});
}