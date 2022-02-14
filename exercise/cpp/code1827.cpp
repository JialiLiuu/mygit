#include "../include/common.h"

class Solution
{
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int left=0;
        for(auto n:nums){
            if(n<=left){
                ans+=(left-n+1);
                left++;
            }
            else
                left=n; 
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> aa = {3,1,5};
    cout<<S.minOperations(aa)<<endl;
}