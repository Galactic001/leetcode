#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;

        // Loop until the pointers meet in the middle
        while (left < right)
        {
            // Swap the characters at left and right
            swap(s[left], s[right]);

            // Move pointers towards the center
            left++;
            right--;
        }
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Assuming input format: k, dist, n, then array
    if (cin >> n)
    {
        vector<char> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        Solution sol;
        sol.reverseString(nums);

        cout << "Reversed String: ";
        for (char c : nums)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}