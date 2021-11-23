#include "common.h"

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> vec(n, vector<int>(n, INT_MAX));
        int first_index[2];
        int value = INT_MAX;
        for (int i = 0; i < times.size(); i++)
        {
            vec[times[i][0] - 1][times[i][1] - 1] = times[i][2];
            if (times[i][2] < value)
            {
                first_index[0] = times[i][0] - 1;
                first_index[1] = times[i][1] - 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            vec[i][i] = 0;
        }
        vector<int> flag = {k - 1};

        for (int i = 0; i < n - 1; i++)
        {
            int index;
            int lens = INT_MAX;
            for (int j = 0; j < flag.size(); j++)
            {
                for (int kk = 0; kk < n; kk++)
                {
                    if (vec[flag[j]][kk] < lens && find(flag.begin(), flag.end(), kk) == flag.end())
                    {
                        index = kk;
                        lens = vec[flag[j]][kk];
                    }
                }
            }
            if (lens == INT_MAX)
            {
                return -1;
            }
            else
            {
                flag.push_back(index);
            }

            for (int j = 0; j < n; j++)
            {
                if (vec[k - 1][index] != INT_MAX && vec[index][j] != INT_MAX && vec[k - 1][j] > vec[k - 1][index] + vec[index][j])
                {
                    vec[k - 1][j] = vec[k - 1][index] + vec[index][j];
                }
            }
        }
        int maxPosition = max_element(vec[k - 1].begin(), vec[k - 1].end()) - vec[k - 1].begin();
        return vec[k - 1][maxPosition];
    }
};

int main()
{
    Solution S;
    vector<vector<int>> aa = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << S.networkDelayTime(aa, n, k) << endl;
}