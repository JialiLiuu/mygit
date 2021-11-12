#include "common.h"

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() == 0)
            return 0;
        vector<int>::iterator t = data.begin() + int(data.size() / 2);
        vector<int>::iterator begin = data.begin();
        vector<int>::iterator end = data.end();
        int ans = 0;
        if (t == data.begin() && *t != k)
            return 0;
        if (*t < k)
        {
            vector<int> v(t, end);
            return GetNumberOfK(v, k);
        }

        else if (*t > k)
        {
            vector<int> v(begin, t);
            return GetNumberOfK(v, k);
        }
        else //*t == k
        {
            vector<int>::iterator tt = t;
            while (1)
            {
                if (*tt == k)
                    ans++;
                if (tt == data.begin())
                    break;
                else
                    tt--;
            }
            tt = t + 1;
            while (tt != data.end())
            {
                if (*tt == k)
                    ans++;
                tt++;
            }
            return ans;
        }
    }
};

int main()
{
    Solution S;
    cout << S.GetNumberOfK({1, 3, 3, 3, 3, 4, 5}, 2) << endl;
}