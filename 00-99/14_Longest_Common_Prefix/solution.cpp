#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // 1. Sort the array of strings
        // Sorting helps because the longest common prefix must be shared 
        // between the "smallest" string (lexicographically) and the "largest" string.
        sort(strs.begin(), strs.end());

        // 2. Grab the first and last strings
        string first = strs[0];
        string last = strs[strs.size() - 1];

        // 3. Compare them character by character
        int i = 0;
        while (i < first.length() && i < last.length()) {
            if (first[i] == last[i]) {
                i++;
            } else {
                break; // Stop at the first mismatch
            }
        }

        // Return the substring from 0 to i
        return first.substr(0, i);
    }
};

int main() {
    int n;
    cout << "Enter number of strings: ";
    if (!(cin >> n)) return 0;

    vector<string> strs(n);
    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution sol;
    string result = sol.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: \"" << result << "\"" << endl;

    return 0;
}   