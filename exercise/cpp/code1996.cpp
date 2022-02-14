#include "common.h"

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        stack<int> sk;
        //攻击从小到大排序,（攻击值相同防御值从大到小排序）！！！！避免相同攻击值进栈，防御值高的顶出防御值低的，故让防御值高的先进栈
        sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]); });
        int ans = 0;
        for (auto item : properties)
        {
            while (!sk.empty() && sk.top() < item[1])
            {
                sk.pop();
                ans++;
            }
            sk.push(item[1]);
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> aa = {{1, 5}, {10, 4}, {4, 3}};
    cout << S.numberOfWeakCharacters(aa) << endl;
}