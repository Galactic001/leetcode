#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        // 1. Insert all jewels into a HashSet for O(1) lookups
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());

        int count = 0;
        // 2. Iterate through stones only once
        for (char stone : stones)
        {
            // Check if stone exists in the jewel set
            if (jewelSet.count(stone))
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str1, str2;

    // Assuming input format: k, dist, n, then array
    if (cin >> str1 >> str2)
    {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.numJewelsInStones(str1, str2) << endl;
    }

    return 0;
}