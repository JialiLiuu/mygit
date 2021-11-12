#include "common.h"

class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        for (int i = 0; i < array.size(); i++)
        {
            if (find(array.begin() + i + 1, array.end(), sum - array[i]) != array.end())
                return {array[i], sum - array[i]};
        }
        return {};
    }
};

int main()
{
    Solution S;
    cout << S.FindNumbersWithSum({1, 4, 9}, 8)[0] << endl;
}