#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // APPROACH 1: Brute Force (O(N^2)) - Simplest to understand
        // We check every pair. If we find it, return immediately.
        // /*
        for (int i = 0; i < nums.size(); i++)
        {
            // Start j at i + 1 to avoid using the same element twice
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
        // */

        // APPROACH 2: Hash Map (O(N)) - Optimized for Speed
        // We store values we've seen in a map: {Value -> Index}
        // Then we look for the "complement" (Target - CurrentValue)
        /*
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            // If the complement exists in the map, we found the pair!
            if (map.find(complement) != map.end())
            {
                return {map[complement], i};
            }

            // Otherwise, store current number and index for later
            map[nums[i]] = i;
        }

        return {};
        */
    }
};

int main()
{
    int n, target, val;
    vector<int> nums;

    cout << "Enter Target: ";
    cin >> target;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}