#include "../include/common.h"

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int C = 0;
        for (int i = 0; i < matchsticks.size(); i++)
        {
            C += matchsticks[i];
        }
        sort(matchsticks.begin(),matchsticks.end());
        if(C%4!=0||matchsticks[-1]>(C/4))
            return false;
    }
};

int main()
{
    Solution S;
    //    cout<< <<endl;
    return 0;
}