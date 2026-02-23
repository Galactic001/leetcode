#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int max_gap = 0;
        int last_pos = -1; // -1 means no '1' has been encountered yet
        int current_pos = 0;

        while (n > 0)
        {
            // Check if the current rightmost bit is 1
            if (n & 1)
            {
                // If we've seen a 1 before, calculate the gap
                if (last_pos != -1)
                {
                    max_gap = std::max(max_gap, current_pos - last_pos);
                }
                // Update the position of the last seen 1
                last_pos = current_pos;
            }

            // Shift n to the right by 1 bit
            n >>= 1;
            // Move to the next bit position
            current_pos++;
        }

        return max_gap;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int k;

    // Assuming input format: k, n, then array
    if (cin >> k)
    {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.binaryGap(k) << endl;
    }

    return 0;
}