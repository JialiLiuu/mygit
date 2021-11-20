#include "common.h"

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int v[n][n];
        for (int i = 0; i < times.size(); i++)
        {
            v[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == k - 1)
                    continue;
            }
        }
    }
};

int main()
{
    Solution S;
}