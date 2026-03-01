#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;
        
        // 1. Skip any trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // 2. Count the characters of the last word until we hit a space
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str;

    // Assuming input format: k, n, then array
    if (cin >> str) {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.lengthOfLastWord(str) << endl;
    }

    return 0;
}