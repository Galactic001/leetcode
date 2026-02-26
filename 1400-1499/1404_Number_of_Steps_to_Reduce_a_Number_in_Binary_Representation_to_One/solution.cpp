#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int steps = 0;
        int carry = 0;

        // Loop from the rightmost bit up to the second bit (index 1)
        for (int i = s.length() - 1; i > 0; --i)
        {
            int current_bit = (s[i] - '0') + carry;

            if (current_bit == 1)
            {
                // Odd number: requires +1 and /2 (2 steps total)
                steps += 2;
                carry = 1; // Adding 1 generates a carry
            }
            else
            {
                // Even number (0 or 2): requires only /2 (1 step)
                steps += 1;
                // Carry remains unchanged:
                // if it was 0, it stays 0. If it was 2 (1 + carry), carry stays 1.
            }
        }

        // If there's a carry left over at the MSB, it adds one final division step
        return steps + carry;
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
        cout << "Value: " << sol.numSteps(str) << endl;
    }

    return 0;
}