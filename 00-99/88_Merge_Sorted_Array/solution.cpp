#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;       // Pointer for the end of actual elements in nums1
        int j = n - 1;       // Pointer for the end of nums2
        int k = m + n - 1;   // Pointer for the very end of nums1's capacity

        // Start from the back and place the largest elements at the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are remaining elements in nums2, place them
        // (No need to check nums1, as its elements are already in place)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
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
        vector<int> arr1(m);
        vector<int> arr2(n);
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        // nums1 must have enough space for m + n elements
        arr1.resize(m + n);
        Solution sol;
        sol.merge(arr1, m, arr2, n);

        cout << "Merged array: ";
        for (int i = 0; i < m + n; ++i)
        {
            cout << arr1[i] << " ";
        }
        cout << endl;
    }

    return 0;
}