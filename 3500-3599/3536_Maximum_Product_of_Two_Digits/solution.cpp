#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1; // Largest digit
        int max2 = -1; // Second largest digit

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit > max1) {
                // Found a new largest, shift old largest to second place
                max2 = max1;
                max1 = digit;
            } else if (digit > max2) {
                // Found a new second largest
                max2 = digit;
            }
        }

        return max1 * max2;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n)) return 0;

    Solution sol;
    cout << "Maximum Product: " << sol.maxProduct(n) << endl;

    return 0;
}