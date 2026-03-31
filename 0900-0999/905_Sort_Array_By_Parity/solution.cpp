#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;

        // push even numbers
        for (int n = 0; n < nums.size(); n++)
        {
            if (nums[n] % 2 == 0)
            {
                result.push_back(nums[n]);
            }
        }

        // push odd numbers
        for (int n = 0; n < nums.size(); n++)
        {
            if (nums[n] % 2 != 0)
            {
                result.push_back(nums[n]);
            }
        }

        return result;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Assuming input format: k, n, then array
    if (cin >> n) {

        vector<int> result;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        result = sol.sortArrayByParity(nums);

        cout << "Sorted Array: " << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }

    return 0;
}