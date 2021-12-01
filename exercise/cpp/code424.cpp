#include "../include/common.h"

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> times(26, 0);
        int ans = 0;
        int left = 0;
        int right = 1;
        char target;
        while (right <= s.length())
        {
            times[s[right - 1] - 'A']++;
            target = 'A' + max_element(times.begin(), times.end()) - times.begin();
            string ss = s.substr(left, right - left);
            int it = accumulate(times.begin(), times.end(), 0);
            if ((it - times[target - 'A']) > k)
            {
                times[s[left] - 'A']--;
                left++;
            }
            else
                ans = right - left;
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    cout << S.characterReplacement("BAAA", 0) << endl;
}