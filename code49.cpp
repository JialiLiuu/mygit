#include "common.h"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> v;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            v.push_back(t);
        }
        for (int i = 0; i < v.size(); i++)
        {
            vector<string> vec = {};
            vector<string>::iterator it = v.begin() + i;
            if (*it == "A")
                continue;
            while (it != v.end())
            {
                vec.push_back(strs[it - v.begin()]);
                vector<string>::iterator bit = it;
                it = find(bit + 1, v.end(), *bit);
                *bit = "A";
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<string> v = {""};
    S.groupAnagrams(v);
}