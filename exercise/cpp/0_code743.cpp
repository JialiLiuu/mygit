#include "common.h"

class Solution
{
public:
    bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    }
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

        // for (vector<pair<int, int>>::iterator i = _map.begin(); i != _map.end(); i++)
        // {
        //     auto item = min_element(_map.begin(), _map.end());
        //     if (item->second != INT_MAX)
        //         _map.erase(item->first);
        //     else
        //         return -1;

        //     for (auto mm : _map)
        //     {
        //         map<string, int>::iterator it = side.find(to_string(item->first) + "_" + to_string(mm.first));
        //         if (it == side.end())
        //             continue;

        //         if (mm.second > item->second + it->second)
        //         {
        //             mm.second = item->second + it->second;
        //         }
        //     }
        // }
        stable_sort(_map.begin(), _map.end(), cmp);
        return 1;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> aa = {{2, 1, 4}, {2, 3, 3}, {3, 4, 5}};
    int n = 4, k = 2;
    cout << S.networkDelayTime(aa, n, k) << endl;
}