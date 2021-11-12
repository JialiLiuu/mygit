#include "common.h"

class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        int n0 = 0;
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] == 0)
                n0++;
            else if (numbers[i + 1] == numbers[i])
                return false;
            else
                n0 = n0 - (numbers[i + 1] - numbers[i] - 1);
        }
        if (n0 >= 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution S;
    cout << S.IsContinuous({1, 0, 0, 1, 0}) << endl;
}