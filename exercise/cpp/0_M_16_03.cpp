#include "common.h"

class Solution
{
public:
    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2)
    {
        
        double x, y, k1, k2, b1, b2;
        if (end1[0] == start1[0] && end2[0] == start2[0])
        {
            if (end1[0] == end2[0])
            {
                if (start1[1] <= start2[1] && start2[1] <= end1[1])
                {
                    x = start2[0];
                    y = start2[1];
                }
                else if (start1[1] >= start2[1] && start1[1] <= end2[1])
                {
                    x = start1[0];
                    y = start1[1];
                }
                else
                    return {};
            }
            else
                return {};
        }
        else if (end1[0] != start1[0] && end2[0] == start2[0])
        {
            x = start2[0];
            k1 = (end1[1] - start1[1]) / (end1[0] - start1[0]);
            b1 = start1[1] - k1 * start1[0];
            y = k1 * x + b1;
        }
        else if (end1[0] == start1[0] && end2[0] != start2[0])
        {
            x = start1[0];
            k2 = (end2[1] - start2[1]) / (end2[0] - start2[0]);
            b2 = start2[1] - k2 * start2[0];
            y = k2 * x + b2;
        }
        else
        {
            k1 = (end1[1] - start1[1]) / (end1[0] - start1[0]);
            b1 = start1[1] - k1 * start1[0];
            k2 = (end2[1] - start2[1]) / (end2[0] - start2[0]);
            b2 = start2[1] - k2 * start2[0];
            if (k1 == k2 && b1 == b2)
            {
                if (start1[0] <= start2[0] && start2[0] <= end1[0])
                {
                    x = start2[0];
                    y = start2[1];
                }
                else if (start1[0] >= start2[0] && start1[0] <= end2[0])
                {
                    x = start1[0];
                    y = start1[1];
                }
                else
                    return {};
            }
            else if (k1 == k2 && b1 != b2)
                return {};
            else
            {
                x = (b2 - b1) / (k1 - k2);
                y = k1 * x + b1;
            }
        }
        if (x <= end1[0] && x >= start1[0] && x <= end2[0] && x >= start2[0] && y <= end1[1] && y >= start1[1] && y <= end2[1] && y >= start2[1])
            return {x, y};
        else
            return {};
    }
};

int main()
{
    Solution S;
    vector<int> v1,v2,v3,v4;
    v1={0,0};
    v2={0,1};
    v3={0,0};
    v4={0,-1};
    vector<double>ans = S.intersection(v1,v2,v3,v4);
    cout<<ans.size()<<endl;
}