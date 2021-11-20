#include "../include/common.h"

class Solution {
public:
    bool isPathCrossing(string path) {
        vector<string> vec;
        vec.push_back(to_string(0)+","+to_string(0));
        string::iterator it=path.begin();
        int x=0;
        int y=0;
        while(it!=path.end()){
            if(*it=='N')
                y++;
            else if(*it=='E')
                x++;
            else if(*it=='S')
                y--;
            else if(*it=='W')
                x--;
            vector<string>::iterator f=find(vec.begin(),vec.end(),to_string(x)+","+to_string(y));
            if(f==vec.end())
                vec.push_back(to_string(x)+","+to_string(y));
            else
                return true;
            it++;
        }
        return false;
    }
};

int main(){
    Solution S;
    cout<<S.isPathCrossing("NES")<<endl;
    return 0;
}