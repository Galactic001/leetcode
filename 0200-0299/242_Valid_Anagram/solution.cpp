#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string n, k;

    // Assuming input format: k, n, then array
    if (cin >> n >> k) {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.isAnagram(n, k) << endl;
    }

    return 0;
}