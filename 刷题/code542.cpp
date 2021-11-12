#include "common.h"

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> index;
        int n = 0;
        int end_n = mat.size() * mat[0].size();
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    n++;
                    index.push_back({i, j});
                }
                else
                    mat[i][j] = INT32_MAX;
            }
        }
        index.erase(unique(index.begin(), index.end()), index.end());
        while (n < end_n)
        {
            for (int ii = 0; ii < index.size(); ii++)
            {
                int i = index[ii][0];
                int j = index[ii][1];
                if (i != 0 && mat[i][j] < mat[i - 1][j])
                {
                    n++;
                    mat[i - 1][j] = mat[i][j] + 1;
                    index.push_back({i - 1, j});
                }
                if (j != 0 && mat[i][j] < mat[i][j - 1])
                {
                    n++;
                    mat[i][j - 1] = mat[i][j] + 1;
                    index.push_back({i, j - 1});
                }
                if (i != mat.size() - 1 && mat[i][j] < mat[i + 1][j])
                {
                    n++;
                    mat[i + 1][j] = mat[i][j] + 1;
                    index.push_back({i + 1, j});
                }
                if (j != mat[0].size() - 1 && mat[i][j] < mat[i][j + 1])
                {
                    n++;
                    mat[i][j + 1] = mat[i][j] + 1;
                    index.push_back({i, j + 1});
                }
            }
            index.erase(unique(index.begin(), index.end()), index.end());
        }
        return mat;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    S.updateMatrix(mat);
}