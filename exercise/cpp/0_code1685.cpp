#include "../include/common.h"

class Solution
{
public:
    // vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    // {
    //     vector<int> ans(nums.size(), 0);
    //     // vector<int> diff = adjacent_difference(nums.begin(), nums.end());
    // }
};

int main()
{
    Solution S;
    std::vector<int> v{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::adjacent_difference(v.begin(), v.end(), v.begin());

    for (auto n : v)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // Fibonacci
    // Notice, next item on the list is the result of the current iteration

    v = std::vector<int>(10);
    v[0] = 1;

    std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1, std::plus<int>());

    for (auto n : v)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}