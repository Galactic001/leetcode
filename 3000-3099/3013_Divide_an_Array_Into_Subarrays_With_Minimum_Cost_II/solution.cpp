#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // k subarrays means we need to pick (k-1) cut points.
        // The first cut point is fixed at nums[0].
        // We need to pick k-1 numbers from nums[1...end] such that 
        // they fit in a window of size dist+1.
        
        long long currentSum = 0;
        long long minSum = LLONG_MAX;
        
        // 'L' stores the smallest k-1 elements (active set)
        // 'R' stores the remaining elements in the window (reserve set)
        multiset<int> L, R;
        
        // Target size for L is k-1
        int needed = k - 1;

        // Helper to add a number
        auto add = [&](int val) {
            // Optimistically add to L
            L.insert(val);
            currentSum += val;
            
            // If L is too big, move largest element to R
            if (L.size() > needed) {
                int largestInL = *L.rbegin();
                L.erase(prev(L.end())); // Remove largest from L
                currentSum -= largestInL;
                R.insert(largestInL);   // Move to R
            }
        };

        // Helper to remove a number
        auto remove = [&](int val) {
            // Check if val is in L
            auto it = L.find(val);
            if (it != L.end()) {
                L.erase(it);
                currentSum -= val;
            } else {
                // It must be in R
                R.erase(R.find(val));
            }
            
            // If L shrank below needed size, refill it from R (if R has candidates)
            if (L.size() < needed && !R.empty()) {
                int smallestInR = *R.begin();
                R.erase(R.begin());
                L.insert(smallestInR);
                currentSum += smallestInR;
            }
        };

        // 1. Initialize the first window [1 ... dist+1]
        for (int i = 1; i <= dist + 1 && i < nums.size(); i++) {
            add(nums[i]);
        }
        
        // This is the cost for the first valid window
        if (L.size() == needed) {
            minSum = currentSum;
        }

        // 2. Slide the window
        // Start sliding from index dist + 2
        for (int i = dist + 2; i < nums.size(); i++) {
            // Remove element that is sliding out (index i - (dist + 1))
            remove(nums[i - (dist + 1)]);
            
            // Add new element sliding in (index i)
            add(nums[i]);
            
            minSum = min(minSum, currentSum);
        }

        return nums[0] + minSum;
    }
};

int main() {
    // File I/O setup
    freopen("D:\\Github\\leetcode\\input.txt", "r", stdin); 
    
    int n, k, dist;
    
    // Assuming input format: k, dist, n, then array
    if (cin >> k) {
        cin >> dist;
        cin >> n;
        
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution sol;
        cout << "Minimum Cost: " << sol.minimumCost(nums, k, dist) << endl;
    }
    
    return 0;
}