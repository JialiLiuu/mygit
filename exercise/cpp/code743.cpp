#include "common.h"

class Solution
{
    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) //要用常数，不然编译错误
    {
        return p1.second > p2.second;
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        map<string, int> side;
        for (int i = 0; i < times.size(); i++)
        {
            string temp = to_string(times[i][0] - 1) + "_" + to_string(times[i][1] - 1);
            side.insert({temp, times[i][2]});
        }
        vector<pair<int, int>> _map;
        for (int i = 0; i < n; i++)
        {
            if (i != k - 1)
            {
                map<string, int>::iterator it = side.find(to_string(k - 1) + "_" + to_string(i));
                if (it == side.end())
                    _map.push_back(make_pair(i, INT_MAX));
                else
                    _map.push_back(make_pair(i, it->second));
            }
        }

        for (int i = 0; i < n - 2; i++)
        {
            sort(_map.begin(), _map.end(), cmp);
            auto item = _map[_map.size() - 1];
            if (item.second != INT_MAX)
                _map.pop_back();
            else
                return -1;

            for (vector<pair<int, int>>::iterator mm = _map.begin(); mm != _map.end(); mm++)
            {
                map<string, int>::iterator it = side.find(to_string(item.first) + "_" + to_string(mm->first));
                if (it == side.end())
                    continue;

                if (mm->second == INT_MAX || mm->second > item.second + it->second)
                {
                    mm->second = item.second + it->second;
                }
            }
        }
        return _map[0].second == INT_MAX ? -1 : _map[0].second;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> aa = {{1, 2, 1}};
    int n = 2, k = 1;
    cout << S.networkDelayTime(aa, n, k) << endl;
}