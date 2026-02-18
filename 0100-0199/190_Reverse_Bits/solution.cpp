#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        // Iterate exactly 32 times for a 32-bit integer
        for (int i = 0; i < 32; i++) {
            // 1. Shift result to the left to open a spot for the new bit
            ans = ans << 1;
            
            // 2. Get the last bit of n and add it to ans
            // (OR logic works like addition here since the last bit is 0)
            ans = ans | (n & 1);
            
            // 3. Shift n to the right to process the next bit
            n = n >> 1;
        }
        
        return ans;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    uint32_t n;

    // Assuming input format: k, dist, n, then array
    if (cin >> n)
    {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.reverseBits(n) << endl;
    }

    return 0;
}