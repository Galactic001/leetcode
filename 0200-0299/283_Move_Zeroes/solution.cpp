#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int insertPos = 0;

        // 1. Move all the non-zero elements to the front
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }

        // 2. Fill the remaining positions with zeroes
        while (insertPos < nums.size())
        {
            nums[insertPos] = 0;
            insertPos++;
        }
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
        sol.moveZeroes(nums);
        cout << "Final Array: ";
        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}