#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
int minimumDifference(vector<int>& nums, int k) {
        // 1. Sort the array. 
        // This ensures that for any subset of size k, the "closest" values
        // are grouped together.
        sort(nums.begin(), nums.end());

        // Initialize min difference to the maximum possible integer
        int minDiff = INT_MAX;

        // 2. Sliding Window
        // We look at every window of size 'k'.
        // Because it's sorted:
        //   - The Lowest value in the window is at index 'i'
        //   - The Highest value in the window is at index 'i + k - 1'
        for (int i = 0; i <= nums.size() - k; i++) {
            int currentDiff = nums[i + k - 1] - nums[i];
            
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
            }
        }
        
        return minDiff;
    }
};

int main()
{
    int target;
    cout << "Enter target value";
    cin >> target;

    int n, num;
    vector<int> nums;

    cout << "Enter size of array: ";
    if (!(cin >> n))
        return 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;
    int val = solution.minimumDifference(nums, target);
    cout << "Final Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Output: " + val;

    return 0;
}