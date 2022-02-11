#include "common.h"

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int,int> rank;
        rank.insert({ properties[0][0],properties[0][1] });
        vector<vector<int>>::iterator it=properties.begin()+1;
        while(it!=properties.end()){
            
        }
    }
};

int main()
{
    Solution S;
}