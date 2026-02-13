#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            // Check if the character is uppercase
            if (c >= 'A' && c <= 'Z') {
                // Convert to lowercase by adding 32 (or using bitwise OR: c | 32)
                c = c + 32; 
            }
        }
        return s;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str;

    // Assuming input format: k, dist, n, then array
    if (cin >> str) {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.toLowerCase(str) << endl;
    }

    return 0;
}