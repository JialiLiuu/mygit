#include "common.h"

class Solution
{
public:
    vector<int> FindNumsAppearOnce(vector<int> &array)
    {
        vector<int> ans;
        for (int i = 0; i < array.size(); i++)
        {
            vector<int>::iterator it = find(ans.begin(), ans.end(), array[i]);
            if (it != ans.end())
                ans.erase(it);
            else
                ans.push_back(array[i]);
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> array = {1, 1, 2, 3, 5, 5, 6, 6};
    cout << S.FindNumsAppearOnce(array)[0] << endl;
    cout << S.FindNumsAppearOnce(array)[1] << endl;
}