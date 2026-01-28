#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse
#include <cmath>     // Required for std::min

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        // Loop through the string in chunks of 2*k
        for (int i = 0; i < n; i += 2 * k) {
            
            // We want to reverse k characters, but we must not go past the end.
            // std::min ensures we don't access memory outside the string.
            // Logic: Reverse from 'i' to 'i+k' (or end of string)
            int end = min(i + k, n);
            
            reverse(s.begin() + i, s.begin() + end);
        }
        
        return s;
    }
};

int main()
{
    string s;
    int k;
    
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    Solution solution;
    string result = solution.reverseStr(s, k);
    
    cout << "Result: " << result << endl;
    return 0;
}