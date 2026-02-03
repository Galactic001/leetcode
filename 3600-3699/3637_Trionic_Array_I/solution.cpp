#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        // Climb up to first peak p
        int p = 0;

        while ( p < n - 1 && nums[p] < nums[p + 1])
        {
            p++;
        }

        // Must have started increasing (p > 0)
        // Must not have reached the end already (p < n - 1)
        if (p == 0 || p == n - 1) return false;


        // Climb down the valley q
        int q = p;
        while ( q < n - 1 && nums[q] > nums[q + 1])
        {
            q++;
        }

        // Must have decreased (q > p)
        // Must not be at the very end (q < n - 1)
        if (q == p || q == n - 1) return false;


        // Climb up to the end
        while (q < n - 1 && nums[q] < nums[q + 1])
        {
            q++;
        }

        // Did we reach end ?
        return q == n - 1;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Assuming input format: k, dist, n, then array
    if (cin >> n) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Minimum Cost: " << sol.isTrionic(nums) << endl;
    }

    return 0;
}