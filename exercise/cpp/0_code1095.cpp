#include "common.h"

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
            int right_peak = mountainArr.get(int((left + right) / 2) + 1);
            if (peak > left_peak && peak > right_peak)
                break;
            else if ()
        }

        for (int i = 0; i < mountainArr.length(); i++)
        {
            if (mountainArr.get(i) == target)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    MountainArray array;
    array.v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82};
    cout << S.findInMountainArray(101, array);
}