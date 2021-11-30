#include "common.h"

class Solution
{
public:
    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2)
    {
        double xmin, xmax, ymin, ymax;
        vector<double> xtemp = {(double)start1[0], (double)end1[0], (double)start2[0], (double)end2[0]};
        sort(xtemp.begin(), xtemp.end());
        double xx = (xtemp[1] + xtemp[2]) / 2;
        if (xx <= max(start1[0], end1[0]) && xx >= min(start1[0], end1[0]))
        {
            xmin = min(xtemp[1], xtemp[2]);
            xmax = max(xtemp[1], xtemp[2]);
        }
        else
            return {};
        vector<double> ytemp = {(double)start1[1], (double)end1[1], (double)start2[1], (double)end2[1]};
        sort(ytemp.begin(), ytemp.end());
        double yy = (ytemp[1] + ytemp[2]) / 2;
        if (yy <= max(start1[1], end1[1]) && yy >= min(start1[1], end1[1]))
        {
            ymin = min(ytemp[1], ytemp[2]);
            ymax = max(ytemp[1], ytemp[2]);
        }
        else
            return {};
        double x, y, k1, k2, b1, b2;
        if (end1[0] == start1[0] && end2[0] == start2[0])
        {
            x = end1[0];
            y = ymin;
        }
        else if (end1[0] != start1[0] && end2[0] == start2[0])
        {
            x = end2[0];
            end1[1] == start1[1] ? k1 = 0 : k1 = ((double)end1[1] - (double)start1[1]) / ((double)end1[0] - (double)start1[0]);
            b1 = (double)start1[1] - k1 * (double)start1[0];
            y = k1 * x + b1;
        }
        else if (end1[0] == start1[0] && end2[0] != start2[0])
        {
            x = end1[0];
            end2[1] == start2[1] ? k2 = 0 : k2 = ((double)end2[1] - (double)start2[1]) / ((double)end2[0] - (double)start2[0]);
            b2 = (double)start2[1] - k2 * (double)start2[0];
            y = k2 * x + b2;
        }
        else
        {
            end1[1] == start1[1] ? k1 = 0 : k1 = ((double)end1[1] - (double)start1[1]) / ((double)end1[0] - (double)start1[0]);
            b1 = (double)start1[1] - k1 * (double)start1[0];
            end2[1] == start2[1] ? k2 = 0 : k2 = ((double)end2[1] - (double)start2[1]) / ((double)end2[0] - (double)start2[0]);;
            b2 = (double)start2[1] - k2 * (double)start2[0];
            if (k1 == k2 && b1 == b2)
            {
                x = xmin;
                y = k1 * x + b1;
            }
            else if (k1 == k2 && b1 != b2)
                return {};
            else
            {
                x = (b2 - b1) / (k1 - k2);
                y = k1 * x + b1;
            }
        }
        if (x <= xmax && x >= xmin && y <= ymax && y >= ymin)
            return {x, y};
        else
            return {};
    }
};

int main()
{
    Solution S;
    vector<int> v1, v2, v3, v4;
    v1 = {1, 1};
    v2 = {-1, 1};
    v3 = {1, 0};
    v4 = {-3, 2};
    vector<double> ans = S.intersection(v1, v2, v3, v4);
    cout << ans.size() << endl;
}