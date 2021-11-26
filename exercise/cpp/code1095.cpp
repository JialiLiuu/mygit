#include "common.h"
//左边找不到找右边！！！
class MountainArray
{
public:
    vector<int> v;
    int n = 0;

    int length()
    {
        return v.size();
    }

    int get(int index)
    {
        if (n < 100)
        {
            n++;
            return v[index];
        }
        else
            return -1;
    }
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int left = 0, right = mountainArr.length() - 1;
        int peak;
        while (1)
        {
            peak = mountainArr.get(int((left + right) / 2));
            if (left == right)
                break;
            int right_peak = mountainArr.get(int((left + right) / 2) + 1);
            if (peak > right_peak)
                right = int((left + right) / 2);
            else
                left = int((left + right) / 2) + 1;
        }
        left = 0;
        if (target > peak)
            return -1;
        int middle = right;
        while (1)
        {
            peak = mountainArr.get(int((left + right) / 2));
            if (target == peak)
                return int((left + right) / 2);
            if (left >= right)
                break;
            if (target < peak)
                right = int((left + right) / 2) - 1;
            else
                left = int((left + right) / 2) + 1;
        }
        left = middle;
        right = mountainArr.length() - 1;
        while (1)
        {
            peak = mountainArr.get(int((left + right) / 2));
            if (target == peak)
                return int((left + right) / 2);
            if (left >= right)
                return -1;
            if (target < peak)
                left = int((left + right) / 2) + 1;
            else
                right = int((left + right) / 2) - 1;
        }
    }
};

int main()
{
    Solution S;
    MountainArray array;
    array.v = {1, 5, 2};
    cout << S.findInMountainArray(2, array);
}