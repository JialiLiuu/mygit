#include "common.h"

class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        vector<int> _uglys = {1};
        int _multiple[] = {0, 0, 0}; //记录乘数在_uglys的位置
        for (int i = 1; i < index; i++)
        {
            int t1 = 2 * _uglys[_multiple[0]];
            int t2 = 3 * _uglys[_multiple[1]];
            int t3 = 5 * _uglys[_multiple[2]];
            if (t1 <= t2 && t1 <= t3)
                if (t1 != _uglys[i - 1])
                {
                    _uglys.push_back(t1);
                    _multiple[0]++;
                }
                else
                {
                    _multiple[0]++;
                    i--;
                }
            else if (t2 <= t1 && t2 <= t3)
                if (t2 != _uglys[i - 1])
                {
                    _uglys.push_back(t2);
                    _multiple[1]++;
                }
                else
                {
                    _multiple[1]++;
                    i--;
                }
            else if (t3 <= t1 && t3 <= t2)
                if (t3 != _uglys[i - 1])
                {
                    _uglys.push_back(t3);
                    _multiple[2]++;
                }
                else
                {
                    _multiple[2]++;
                    i--;
                }
        }
        return _uglys[index - 1];
    }
};

int main()
{
    Solution S;
    cout << "结果是: " << S.GetUglyNumber_Solution(10) << endl;
}
