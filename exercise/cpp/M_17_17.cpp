#include "../include/common.h"

class Solution
{
public:
    vector<vector<int>> multiSearch(string big, vector<string> &smalls)
    {
        vector<vector<int>> ans;
        for (auto s : smalls)
        {
            int k = 0;
            vector<int> aa;
            if(s=="")
                k=big.size();
            while (k < big.size())
            {
                int index = big.find(s, k);
                if (index != -1)
                {
                    k = index + 1;
                    aa.push_back(index);
                }
                else{
                    break;
                }
            }
            ans.push_back(aa);
        }
        return ans;
    }
};

int main()
{
    Solution S;
    string b = "mississippi";
    vector<string> s = {"", "ppi", "hi", "sis", "i", "ssippi"};
    S.multiSearch(b, s);
}