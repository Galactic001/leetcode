#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        // XOR Property:
        // 1. A ^ A = 0 (Duplicates cancel out)
        // 2. A ^ 0 = A
        // 3. Order doesn't matter (Associative)

        // If we XOR every number in the array:
        // [4, 1, 2, 1, 2]
        // 4 ^ 1 ^ 2 ^ 1 ^ 2
        // = 4 ^ (1 ^ 1) ^ (2 ^ 2)
        // = 4 ^ 0 ^ 0
        // = 4

        for (int num : nums)
        {
            cout << "result: " << result << " num: " << num << endl;
            result ^= num;
        }

        return result;
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
        cout << "Minimum Cost: " << sol.singleNumber(nums) << endl;
    }

    return 0;
}