#include "common.h"

class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str == "")
            return str;
        string temp = "";
        string ans = "";
        string::iterator it = str.begin();
        while (it != str.end())
        {
            if (*it == ' ')
            {
                ans = " " + temp + ans;
                temp = "";
            }
            else
                temp = temp + *it;
            it++;
        }
        ans = temp + ans;
        return ans;
    }
};

int main()
{
    Solution S;
    cout << S.ReverseSentence("12 34 55 6") << endl;
}