#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        // 1. XOR n with itself shifted right by 1
        long temp = n ^ (n >> 1);

        // 2. Check if the result contains only 1s
        // (temp + 1) should be a power of 2, so temp & (temp + 1) == 0
        return (temp & (temp + 1)) == 0;
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
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Solution: " << sol.hasAlternatingBits(n) << endl;
    }

    return 0;
}