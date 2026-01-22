#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int operations = 0;

        while (!isSorted(nums))
        {
            int minSum = INT_MAX;
            int minIndex = -1;

            // Find the adjacent pair with the minimum sum
            // If ties exist, this loop naturally keeps the leftmost one
            // because we only update if (sum < minSum) strictly.
            for (size_t i = 0; i < nums.size() - 1; ++i)
            {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum)
                {
                    minSum = sum;
                    minIndex = i;
                }
            }

            // Perform the merge operation
            // 1. Replace the left element with the sum
            nums[minIndex] = minSum;
            // 2. Remove the right element
            nums.erase(nums.begin() + minIndex + 1);

            operations++;
        }

        return operations;
    }

private:
    bool isSorted(const vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
};

int main()
{
    int n, val;
    vector<int> nums;

    cout << "Enter number of elements: ";
    if (!(cin >> n))
        return 0;

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        nums.push_back(val);
    }

    Solution sol;
    int ops = sol.minimumPairRemoval(nums);

    cout << "Minimum operations: " << ops << endl;

    // Print final state of array
    // The problem doesn't ask for it, but useful for debugging.
    cout << "Final Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}