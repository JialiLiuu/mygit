#include "../include/common.h"

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> vec;
        vector<string>::iterator it = tokens.begin();
        while (it != tokens.end())
        {
            if (*it == "+")
            {
                int b = vec.back();
                vec.pop_back();
                int a = vec.back();
                vec.pop_back();
                vec.push_back(a + b);
            }
            else if (*it == "-")
            {
                int b = vec.back();
                vec.pop_back();
                int a = vec.back();
                vec.pop_back();
                vec.push_back(a - b);
            }
            else if (*it == "*")
            {
                int b = vec.back();
                vec.pop_back();
                int a = vec.back();
                vec.pop_back();
                vec.push_back(a * b);
            }
            else if (*it == "/")
            {
                int b = vec.back();
                vec.pop_back();
                int a = vec.back();
                vec.pop_back();
                vec.push_back(a / b);
            }
            else
            {
                if ((*it)[0] == '-')
                {
                    vec.push_back(atoi((*it).substr(1).c_str()) * (-1));
                }
                else
                {
                    vec.push_back(atoi((*it).c_str()));
                }
            }
            it++;
        }
        return vec[0];
    }
};

int main()
{
    Solution S;
    vector<string> aa = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << S.evalRPN(aa) << endl;
}