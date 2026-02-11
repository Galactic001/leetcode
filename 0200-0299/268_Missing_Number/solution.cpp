#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        // 1. Calculate the expected sum of numbers from 0 to n
        // Formula: Sum = n * (n + 1) / 2
        int expectedSum = n * (n + 1) / 2;

        // 2. Calculate the actual sum of the elements in the array
        int actualSum = 0;
        for (int num : nums)
        {
            actualSum += num;
        }

        // 3. The difference is the missing number
        return expectedSum - actualSum;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Assuming input format: k, dist, n, then array
    if (cin >> n)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.missingNumber(nums) << endl;
    }

    return 0;
}