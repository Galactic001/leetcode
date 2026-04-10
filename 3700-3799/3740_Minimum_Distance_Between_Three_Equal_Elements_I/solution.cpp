#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> indices;

        // 1. Store the indices of every occurrence of each number
        for (int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]].push_back(i);
        }

        int min_dist = -1;

        // 2. Iterate through our map of indices
        for (const auto &pair : indices)
        {
            const vector<int> &idxs = pair.second;

            // 3. We only care if the number appeared at least 3 times
            if (idxs.size() >= 3)
            {
                // 4. Check every consecutive triplet of indices
                for (int i = 0; i <= idxs.size() - 3; i++)
                {
                    // Our simplified math formula: 2 * (k - i)
                    int dist = 2 * (idxs[i + 2] - idxs[i]);

                    // Update the global minimum distance
                    if (min_dist == -1 || dist < min_dist)
                    {
                        min_dist = dist;
                    }
                }
            }
        }

        return min_dist;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

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
        cout << "Value: " << sol.minimumDistance(nums) << endl;
    }

    return 0;
}