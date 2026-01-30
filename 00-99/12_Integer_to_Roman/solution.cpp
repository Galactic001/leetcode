#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // 1. Define the mapping of values to symbols.
        // We MUST include the subtraction cases (like 900, 400, 90, 40) explicitly
        // to make the greedy logic simple.
        // We use a vector of pairs to ensure the order is maintained (Largest to Smallest).
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        // 2. Iterate through the map
        for (const auto& pair : romanMap) {
            // While the current number is large enough to contain this Roman value...
            while (num >= pair.first) {
                result += pair.second; // Add the symbol
                num -= pair.first;     // Subtract the value
            }
        }

        return result;
    }
};

int main() {
    int num;
    cout << "Enter integer (1 - 3999): ";
    if (!(cin >> num)) return 0;

    Solution sol;
    cout << "Roman Numeral: " << sol.intToRoman(num) << endl;

    return 0;
}