#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        
        // Iterate through each character in the string
        for (char c : n) {
            // Convert char to int and update max_digit
            max_digit = max(max_digit, c - '0');
            
            // Optimization: Since 9 is the highest possible digit, 
            // if we find a 9, we can immediately return it.
            if (max_digit == 9) {
                return 9;
            }
        }
        
        return max_digit;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str;

    // Assuming input format: k, n, then array
    if (cin >> str)
    {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.minPartitions(str) << endl;
    }

    return 0;
}