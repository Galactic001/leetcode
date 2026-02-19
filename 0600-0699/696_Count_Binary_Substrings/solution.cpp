#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int prev_len = 0;
        int curr_len = 1;
        int ans = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == s[i])
            {
                curr_len++;
            }
            else
            {
                // Character changed, add the valid substrings from the previous transition
                ans += min(prev_len, curr_len);
                prev_len = curr_len;
                curr_len = 1; // Reset for the new character
            }
        }

        // Add the very last group transition
        ans += min(prev_len, curr_len);

        return ans;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str;

    // Assuming input format: k, dist, n, then array
    if (cin >> str)
    {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.countBinarySubstrings(str) << endl;
    }

    return 0;
}