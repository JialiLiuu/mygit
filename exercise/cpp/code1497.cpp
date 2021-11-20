#include "../include/common.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int index[k]={0};
        vector<int>::iterator i=arr.begin();
        while(i<arr.end()){
            int temp=*i>0?*i%k:k+*i%k;
            index[temp%k]++;
            i++;
        }
        if(index[0]%2!=0)
            return false;
        for(int i=1;i<k/2+1;i++){
            if(index[i]!=index[k-i])
                return false;
        }
        return true;
    }
};

int main(){
    Solution S;
    vector<int> v={-1,1,-2,2,-3,3,-4,4};
    cout<<S.canArrange(v,3) <<endl;
    return 0;
}