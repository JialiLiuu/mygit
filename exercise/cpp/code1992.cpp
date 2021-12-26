#include "../include/common.h"

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int i = 0;
        vector<vector<int>> ans = {};
        while (i < land.size())
        {
            auto j = find(land[i].begin(), land[i].end(), 1);
            if (j == land[i].end())
            {
                i++;
                continue;
            }
            auto k = find(j, land[i].end(), 0);
            int start = j - land[i].begin();
            int end = k - land[i].begin();
            vector<int> temp(j, k);
            int c = i;
            while (c < land.size())
            {
                vector<int> temp1(land[c].begin() + start, land[c].begin() + end);
                if (temp1 == temp)
                {
                    land[c].erase(land[c].begin() + start, land[c].begin() + end);
                    vector<int> aa(end - start, 0);
                    land[c].insert(land[c].begin() + start, aa.begin(), aa.end());
                    c++;
                }
                else
                    break;
            }
            ans.push_back({i, start, c - 1, end - 1});
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> aa = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    S.findFarmland(aa);
}