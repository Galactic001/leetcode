#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        // 1. Sort the array
        // The minimum difference MUST occur between adjacent elements in a sorted array.
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        int minDiff = INT_MAX;

        // 2. Single pass to find minDiff and collect pairs simultaneously
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int currentDiff = arr[i + 1] - arr[i];

            // Case A: We found a NEW, smaller difference
            if (currentDiff < minDiff)
            {
                minDiff = currentDiff;
                result.clear(); // Discard previous pairs, they are no longer the "minimum"
                result.push_back({arr[i], arr[i + 1]});
            }
            // Case B: We found another pair with the SAME minimum difference
            else if (currentDiff == minDiff)
            {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};

int main()
{
    int n, val;
    vector<int> arr;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }

    Solution sol;
    vector<vector<int>> res = sol.minimumAbsDifference(arr);

    cout << "Pairs with minimum difference:" << endl;
    for (const auto &pair : res)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}