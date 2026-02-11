#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 1. If left char is not a letter, move forward
            if (!isalpha(s[left])) {
                left++;
            }
            // 2. If right char is not a letter, move backward
            else if (!isalpha(s[right])) {
                right--;
            }
            // 3. Both are letters -> Swap them!
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string s;

    // Assuming input format: k, dist, n, then array
    if (cin >> s)
    {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.reverseOnlyLetters(s) << endl;
    }

    return 0;
}