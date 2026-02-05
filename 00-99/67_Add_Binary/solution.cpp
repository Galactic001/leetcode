#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop until both strings are exhausted AND there is no remaining carry
        while (i >= 0 || j >= 0 || carry == 1)
        {

            // Start with the carry from the previous position
            int sum = carry;

            // If we still have digits in 'a', add the current digit
            if (i >= 0)
            {
                sum += a[i] - '0'; // Convert char '1' to int 1
                i--;
            }

            // If we still have digits in 'b', add the current digit
            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            // Compute the new bit and the new carry
            // sum can be:
            // 0 (0+0) -> bit 0, carry 0
            // 1 (1+0) -> bit 1, carry 0
            // 2 (1+1) -> bit 0, carry 1
            // 3 (1+1+1) -> bit 1, carry 1 (happens if previous carry existed)

            carry = sum / 2;              // Integer division: 2/2=1, 3/2=1
            result += to_string(sum % 2); // Remainder: 2%2=0, 3%2=1
        }

        // We appended digits backwards (LSB first), so reverse the final string
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str1, str2;

    // Assuming input format: k, dist, n, then array
    if (cin >> str1 >> str2)
    {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.addBinary(str1, str2) << endl;
    }

    return 0;
}