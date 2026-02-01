#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // The first subarray MUST start at index 0.
        // So nums[0] is always part of the total cost.
        int cost = nums[0];

        // We need to split the remaining part (nums[1] to end) into 2 more subarrays.
        // The cost of a subarray is its FIRST element.
        // To minimize sum, we just need to pick the two smallest numbers 
        // from the rest of the array to be the starts of the 2nd and 3rd subarrays.

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        // Linear scan to find the two smallest elements starting from index 1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min1) {
                min2 = min1; // Demote current min to 2nd min
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }

        return cost + min1 + min2;
    }
};

int main() {
    int n, val;
    vector<int> nums;

    cout << "Enter number of elements (>=3): ";
    if (!(cin >> n)) return 0;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    Solution sol;
    cout << "Minimum Cost: " << sol.minimumCost(nums) << endl;

    return 0;
}