#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        // We need to find the end of the k-th word.
        // Words are separated by spaces.
        // So, the end of the k-th word is located exactly at the k-th space.
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                k--; // Found a word boundary
            }
            
            // If k reaches 0, we have found all the words we need.
            // We cut the string right at this position.
            if (k == 0) {
                return s.substr(0, i);
            }
        }
        
        // Edge Case: If k equals the total number of words, 
        // the loop finishes without k reaching 0 (because there is no trailing space).
        // In this case, return the entire string.
        return s;
    }
};

int main() {
    string s;
    int k;

    cout << "Enter sentence (use getline logic usually, but here cin stops at space):" << endl;
    cout << "NOTE: For testing, hardcode or use getline." << endl;
    
    // Hardcoding test case for simplicity in main, 
    // because standard cin >> stops at whitespace.
    s = "Hello how are you Contestant";
    k = 4;
    
    Solution sol;
    cout << "Original: " << s << endl;
    cout << "Truncated: " << sol.truncateSentence(s, k) << endl;

    return 0;
}