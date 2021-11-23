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
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if (C % 4 != 0 || matchsticks[0] > (C / 4))
            return false;
        vector<int> side(4, C / 4);
        vector<int> inx = {0};
        side[0] -= matchsticks[0];
        for (int i = 1; i < matchsticks.size(); i++)
        {
            int pre = -1;
            if (inx.size() == i + 1)
            {
                pre = inx[i];
                inx.pop_back();
                side[pre] += matchsticks[i];
            }
            for (int j = pre + 1; j < 4; j++)
            {
                if (side[j] >= matchsticks[i])
                {
                    inx.push_back(j);
                    side[j] -= matchsticks[i];
                    break;
                }
            }
            if (inx.size() != i + 1)
            {
                if (i == 0)
                    return false;
                i -= 2;
            }
        }
        return true;
    }
};

int main()
{
    Solution S;
    vector<int> aa = {2,2,2,2,2,6};
    cout << S.makesquare(aa) << endl;
    return 0;
}