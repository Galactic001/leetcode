#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Optimized
    int minPairSum(vector<int> &nums)
    {
        // Optimization: Use Counting Sort because constraints say max val is 100,000
        // This reduces Time Complexity from O(N log N) to O(N + K)

        int maxVal = 0;
        for (int num : nums)
            maxVal = max(maxVal, num);

        // Frequency array to store counts of each number
        vector<int> freq(maxVal + 1, 0);
        for (int num : nums)
            freq[num]++;

        int minPtr = 0;
        int maxPtr = maxVal;
        int maxPairSum = 0;

        // Iterate while we still have pairs to form
        // We simulate the "Two Pointer" approach on the frequency array
        while (minPtr <= maxPtr)
        {
            // 1. Find the smallest available number
            if (freq[minPtr] == 0)
            {
                minPtr++;
                continue;
            }

            // 2. Find the largest available number
            if (freq[maxPtr] == 0)
            {
                maxPtr--;
                continue;
            }

            // 3. Pair them up
            maxPairSum = max(maxPairSum, minPtr + maxPtr);

            // 4. Decrement counts
            freq[minPtr]--;
            freq[maxPtr]--;

            // Note: We don't increment/decrement pointers here because
            // we might have duplicates (e.g., three 2s and two 10s).
            // The 'continue' logic at the start of the loop handles moving pointers.
        }

        return maxPairSum;
    }

    // Brute Force
    int minPairSumBrute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int maxSum = 0;
        int left = 0;
        int right = nums.size() - 1;

        // Two Pointer Approach
        // Pair the smallest (left) with the largest (right)
        while (left < right)
        {
            int currentPairSum = nums[left] + nums[right];

            // We want to minimize the *maximum* pair sum,
            // so we just need to track the highest sum created by this strategy.
            maxSum = max(maxSum, currentPairSum);

            left++;
            right--;
        }

        return maxSum;
    }
};

int main()
{
    vector<int> arr;
    int x, num;

    cout << "Enter length of array: ";
    cin >> x;

    cout << "Enter values of array" << endl;

    for (int i = 0; i < x; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    Solution solution;
    int val = solution.minPairSum(arr);
    cout << endl
         << val;
}