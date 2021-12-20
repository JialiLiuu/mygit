#include "../include/common.h"

class Solution
{
public:
    bool splitString(string s)
    {
        int i;
        //去掉s开头的0
        for (i = 0; i < s.length(); i++)
            if (s[i] != '0')
                break;
        s = s.substr(i);
        for (i = 0; i <= s.length() / 2; i++)
        {
            string n = s.substr(0, i + 1);
            int flag = i;
            while (1)
            {
                n = bigCount(n);
                if (n == "-1")
                    return false;
                int j = findString(s.substr(flag + 1), n);
                if (j == -1)
                    break;
                else
                    flag += (j + 1);

                if (flag == s.length() - 1)
                    return true;
            }
        }
        return false;
    }

    string bigCount(string s)
    {
        int i = s.length() - 1;
        while (i >= 0)
        {
            if (s[i] == '0')
                s[i] = '9';
            else
            {
                s[i]--;
                return s.length() == 1 ? s : s.substr(s.find_first_not_of('0'));
            }
            i--;
        }
        return "-1";
    }

    int findString(string s, string target)
    {
        if (s.length() < target.length())
            return -1;
        if (target == "0" && s.find_first_not_of('0') == string::npos)
            return s.length() - 1;
        int i, j = 0;
        //去掉s开头的0
        for (i = 0; i < s.length(); i++)
            if (s[i] != '0')
                break;

        for (; i < s.length(); i++)
        {
            if (s[i] == target[j])
                j++;
            else
                return -1;
            if (j == target.length())
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    string ss = "200100";
    cout << S.splitString(ss) << endl;
    return 0;
}