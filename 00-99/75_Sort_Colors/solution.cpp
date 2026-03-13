#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                // Swap with low boundary, expand 0s section, move mid forward
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                // Element is in the correct middle section, just move mid forward
                mid++;
            }
            else if (nums[mid] == 2)
            {
                // Swap with high boundary, expand 2s section.
                // Do NOT increment mid, because the newly swapped element at mid needs evaluation
                swap(nums[mid], nums[high]);
                high--;
            }
        }
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
        sol.sortColors(nums);

        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}