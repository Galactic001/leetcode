#include <iostream>
#include <string>
#include <algorithm> // for swap
#include <cctype>    // for isalpha

using namespace std;

class Solution {
public:
    string reverseByType(string s) {
        int len = s.length();
        int left = 0;
        int right = len - 1;

        // Pass 1: Reverse only the Letters
        // We skip non-letters and swap the letters we find
        while (left < right) {
            if (!isalpha(s[left])) {
                left++;
            } else if (!isalpha(s[right])) {
                right--;
            } else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        // Pass 2: Reverse only the Non-Letters (Specials/Numbers)
        // We skip letters and swap the non-letters we find
        left = 0;
        right = len - 1;
        while (left < right) {
            if (isalpha(s[left])) {
                left++;
            } else if (isalpha(s[right])) {
                right--;
            } else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution sol;
    cout << "Result: " << sol.reverseByType(s) << endl;
    return 0;
}