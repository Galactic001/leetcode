#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base Case: If we've reached the end of the array, we have a valid permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Loop through the remaining elements to place at the 'start' index
        for (int i = start; i < nums.size(); i++) {
            // 1. Choose: Swap the current element with the 'start' element
            swap(nums[start], nums[i]);
            
            // 2. Explore: Recursively build the rest of the permutation
            backtrack(nums, start + 1, result);
            
            // 3. Un-choose (Backtrack): Swap back to restore the original state for the next iteration
            swap(nums[start], nums[i]);
        }
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;
    vector<vector<int>> val;

    // Assuming input format: k, n, then array
    if (cin >> n)
    {
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        val = sol.permute(nums);

        cout << "Value: ";

        for (int i = 0; i < val.size(); i++)
        {
            for (int j = 0; j < val[i].size(); j++)
            {
                cout << val[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}