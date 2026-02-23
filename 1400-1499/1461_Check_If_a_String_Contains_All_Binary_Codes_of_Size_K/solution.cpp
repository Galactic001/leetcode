#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int required_count = 1 << k; // 2^k

        // Early exit: string isn't long enough to hold all codes
        if (s.length() < required_count)
            return false;

        unordered_set<string> seen;

        // Slide a window of size k across the string
        for (int i = 0; i <= s.length() - k; i++)
        {
            seen.insert(s.substr(i, k));

            // Optimization: if we found all of them, no need to keep checking
            if (seen.size() == required_count)
                return true;
        }

        return seen.size() == required_count;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int k;
    string str;

    // Assuming input format: k, n, then array
    if (cin >> str >> k)
    {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.hasAllCodes(str, k) << endl;
    }

    return 0;
}