#include "common.h"
//辗转相除法相关，https://blog.csdn.net/whiskey_wei/article/details/79280367
//注意括号只括循环节，还有负数！！！int范围-2,147,483,648 到2,147,483,647
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long long n=(long long)numerator;
        long long d=(long long)denominator;
        string s1 = to_string(n / d);
        s1 == "0" && (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) ? s1 = "-" + s1 : s1;
        long long xiaoshu = n % d;
        vector<string> his;
        string s2 = "";
        while (xiaoshu != 0)
        {
            string shang = to_string(abs(xiaoshu * 10 / denominator));
            xiaoshu = (xiaoshu * 10) % denominator;
            string temp = shang + "_" + to_string(xiaoshu);
            vector<string>::iterator it = find(his.begin(), his.end(), temp);
            s2 += shang;
            if (it != his.end())
            {
                s2.erase(s2.end() - 1);
                int index = it - his.begin();
                s2.insert(index, "(");
                s2 += ")";
                break;
            }
            his.push_back(temp);
        }
        return s2 == "" ? s1 : s1 + "." + s2;
    }
};

int main()
{
    Solution S;
    S.fractionToDecimal(-2147483648, -1);
}