#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {

        // Strings must be the same length (though problem guarantees length 4)
        if (s1.size() != s2.size())
        {
            return false;
        }

        // Iterate ONLY up to index 1.
        // If we go further, i+2 will result in an out-of-bounds memory error!
        for (int i = 0; i < 2; i++)
        {
            // If the current character doesn't match s2, we MUST swap it
            // with the only available option (i + 2)
            if (s1[i] != s2[i])
            {
                swap(s1[i], s1[i + 2]);
            }
        }

        // After all necessary forced swaps, check if they are identical
        return s1 == s2;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string n, k;

    // Assuming input format: k, n, then array
    if (cin >> n >> k)
    {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.canBeEqual(n, k) << endl;
    }

    return 0;
}