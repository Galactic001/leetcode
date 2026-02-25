#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Use sort with a custom lambda comparator
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            // 1. Get the number of set bits for both numbers
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // 2. If bit counts are identical, sort by numerical value
            if (countA == countB) {
                return a < b;
            }
            
            // 3. Otherwise, sort by the number of set bits
            return countA < countB;
        });
        
        return arr;
    }
};

int main() {
    // File I/O setup for local testing
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    vector<int> arr;
    int val;
    
    // Read array elements from input.txt
    while (cin >> val) {
        arr.push_back(val);
    }

    if (!arr.empty()) {
        Solution sol;
        vector<int> result = sol.sortByBits(arr);
        
        cout << "Sorted Array: [";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i == result.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }

    return 0;
}