#include "../include/common.h"
//超时
class Solution
{
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        //房间由大到小排序
        sort(rooms.begin(), rooms.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] > b[1]; });
        vector<int> ans(queries.size(), -1);
        vector<int> rank(queries.size());
        iota(rank.begin(), rank.end(), 0);
        //房间id顺序
        sort(rank.begin(), rank.end(), [&](const int &a, const int &b)
             { return queries[a][1] > queries[b][1]; });
        int i, j = 0;
        set<int> s;
        while (j < queries.size())
        {
            if (i < rooms.size() && rooms[i][1] >= queries[rank[j]][1])
            {
                s.emplace(rooms[i][0]);
                i++;
            }
            else
            {
                if (s.empty())
                {
                    j++;
                    continue;
                }
                auto it = s.lower_bound(queries[rank[j]][0]);
                // auto it = find_if(s.begin(), s.end(), [&](int a)
                //                   { return a > queries[rank[j]][0]; });
                if (it == s.end())
                    ans[rank[j]] = *prev(it);
                else if (it == s.begin())
                    ans[rank[j]] = *it;
                else
                {
                    int key = queries[rank[j]][0] - *prev(it) > *it - queries[rank[j]][0] ? *it : *prev(it);
                    ans[rank[j]] = key;
                }
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    // vector<vector<int>> r = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}};
    // vector<vector<int>> q = {{10, 2}, {2, 4}, {2, 5}};
    vector<vector<int>> r = {{2, 2}, {1, 2}, {3, 2}};
    vector<vector<int>> q = {{3, 1}, {3, 3}, {5, 2}};
    S.closestRoom(r, q);
}