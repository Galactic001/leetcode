#include <bits/stdc++.h>
using namespace std;

    class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> counts;
        
        // 1. First pass: Count the frequencies of all strings
        for (const string& s : arr) {
            counts[s]++;
        }
        
        // 2. Second pass: Iterate through the original array to maintain order
        for (const string& s : arr) {
            // Check if the current string is distinct
            if (counts[s] == 1) {
                k--; // We found a distinct string, decrement our target tracker
                
                // If we've reached the k-th distinct string, return it
                if (k == 0) {
                    return s;
                }
            }
        }
        
        // 3. If there are fewer than k distinct strings, return empty
        return "";
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n, k;

    // Assuming input format: n, k, then array
    if (cin >> n >> k) {
        vector<string> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.kthDistinct(nums, k) << endl;
    }

    return 0;
}