#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string result = "";

        // Iterate diagonally through the matrix of strings
        for (int i = 0; i < nums.size(); i++)
        {
            // Flip the i-th character of the i-th string
            if (nums[i][i] == '0')
            {
                result += '1';
            }
            else
            {
                result += '0';
            }
        }

        return result;
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
        vector<string> strs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> strs[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.findDifferentBinaryString(strs) << endl;
    }

    return 0;
}