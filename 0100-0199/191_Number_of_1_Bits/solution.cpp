#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        return bitset<32>(n).count();
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
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.hammingWeight(n) << endl;
    }

    return 0;
}