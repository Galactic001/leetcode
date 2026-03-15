#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();

        // Edge case: if needle is longer than haystack, it can't be inside it
        if (n > m)
            return -1;

        // 1. Outer loop: slide the window across the haystack
        for (int i = 0; i <= m - n; i++)
        {
            int j = 0;

            // 2. Inner loop: check if the needle matches the current window
            while (j < n && haystack[i + j] == needle[j])
            {
                j++;
            }

            // 3. If j reached the end of the needle, we found a full match
            if (j == n)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    // File I/O setup for local testing
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string haystack, needle;

    // Read input strings
    if (cin >> haystack >> needle)
    {
        Solution sol;
        cout << "Index: " << sol.strStr(haystack, needle) << endl;
    }

    return 0;
}