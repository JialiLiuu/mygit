#include "../include/common.h"

class Solution
{
public:
    bool splitString(string s)
    {
        long n;
        for (int i = 0; i < s.length() - 1; i++)
        {
            n = stoi(s.substr(0, i + 1));
            // if (n - stoi(s.substr(i + 1)) > 1)
            //     return false;
            if (n == 0)
                continue;
            int flag = i;
            while (1)
            {
                int j = findString(s.substr(flag + 1), n - 1);
                if (j == -1)
                    break;
                else
                    flag += (j + 1);

                if (flag == s.length() - 1)
                    return true;
                n--;
            }
        }
        return false;
    }

    int findString(string s, long target)
    {
        long n;
        if (target > stoi(s))
            return -1;

        string tt = to_string(target);
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == tt[j])
                j++;
            else if (s[i] == '0')
                continue;
            else
                return -1;
            if (j == tt.length())
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    string ss = "53520515049";
    cout << S.splitString(ss) << endl;
    return 0;
}