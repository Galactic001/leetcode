#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0;
        int right = letters.size() - 1;

        // Standard Binary Search to find the first element > target
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target)
            {
                // This character is valid, but is there a smaller valid one to the left?
                right = mid - 1;
            }
            else
            {
                // This character is too small (or equal), look to the right.
                left = mid + 1;
            }
        }

        // The 'left' pointer will end up pointing to the answer.
        // If 'left' goes out of bounds (== size), it means NO letter was bigger.
        // The problem says to wrap around to the start in that case.
        // We use the modulo operator (%) to handle the wrap-around elegantly.
        return letters[left % letters.size()];
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;
    char k;

    // Assuming input format: k, dist, n, then array
    if (cin >> k >> n)
    {
        vector<char> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.nextGreatestLetter(nums, k) << endl;
    }

    return 0;
}