#include "../include/common.h"
//超时
class Solution
{
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        sort(rooms.begin(), rooms.end(), [](const vector<int> &a, const vector<int> &b) {return a[1] > b[1]; });
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            auto it=find_if(rooms.begin(), rooms.end(), [&](const vector<int> &a) {return a[1] <= queries[i][1]; });
            if(it==rooms.end())
                ans.push_back(-1);
            else{
                vector<vector<int>> aa(it,rooms.end());
                sort(aa.begin(), aa.end(), [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0]; });
                auto temp=find_if(aa.begin(), aa.end(), [&](const vector<int> &a) {return a[0] >= queries[i][0]; });
                if(temp==aa.end())
                    ans.push_back(aa[aa.size()-1][0]);
                else{
                    int key=temp==aa.begin()||temp[0][0]+(temp-1)[0][0]-queries[i][0]*2<0?temp[0][0]:(temp-1)[0][0];
                    ans.push_back(key);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> r = {{1,4},{2,3},{3,5},{4,1},{5,2}};
    vector<vector<int>> q = {{2,3},{2,4},{2,5}};
    S.closestRoom(r, q);
}