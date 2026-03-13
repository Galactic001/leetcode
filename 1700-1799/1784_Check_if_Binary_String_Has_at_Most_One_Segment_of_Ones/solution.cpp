#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            cout << "val : " << s[i] << " " << s[i+1] << endl;
            if (s[i] == '0' && s[i+1] == '1')
            {
                cout << "here :" << endl;
                return false;
            }
        }
        return true;
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
        cout << "Value: " << sol.checkOnesSegment(str) << endl;
    }

    return 0;
}