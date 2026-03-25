#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> unique_set;

        for (int num : nums2)
        {
            if (set1.count(num))
            {
                unique_set.insert(num);
            }
        }

        return vector<int>(unique_set.begin(), unique_set.end());
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int m, n;

    // Assuming input format: k, n, then array
    if (cin >> m >> n)
    {
        vector<int> nums1(m);
        for (int i = 0; i < n; i++)
        {
            cin >> nums1[i];
        }

        vector<int> nums2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums2[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        vector<int> result = sol.intersection(nums1, nums2);
        cout << "Value: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
        
    }

    return 0;
}