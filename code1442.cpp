#include "common.h"

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int t = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                t ^= arr[j];
                if (t == 0)
                    ans += j - i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> a = {2, 3, 1, 6, 7};
    cout << S.countTriplets(a) << endl;
}