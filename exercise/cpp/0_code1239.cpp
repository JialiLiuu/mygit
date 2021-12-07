#include "../include/common.h"

class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<vector<int>> his;
        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> temp(26, 0);
            for (int j = 0; j < arr[i].size(); j++)
                temp[j - 'a'] = 1;
            his.push_back(temp);
        }
        vector<vector<int>> value;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
            }
        }
    }
};

int main()
{
    Solution S;
}