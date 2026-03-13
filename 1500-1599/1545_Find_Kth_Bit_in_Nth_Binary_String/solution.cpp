#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    char findKthBit(int n, int k) {

        string str = "0";

        for (int i = 1; i < n; i++)
        {
            string reversed = str;
            reverse(reversed.begin(), reversed.end());
            
            // Flip bits in reversed string
            for (char &c : reversed) {
                c = (c == '0') ? '1' : '0';
            }
            
            str = str + "1" + reversed;

            cout << "str: " << str << endl;
        }

        return str[k-1];
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n, k;

    // Assuming input format: k, n, then array
    if (cin >> n >> k) {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.findKthBit(n, k) << endl;
    }

    return 0;
}