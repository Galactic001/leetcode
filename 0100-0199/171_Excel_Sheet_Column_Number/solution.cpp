#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;

        for (char c : columnTitle)
        {
            // Convert character to its corresponding value (A=1, B=2 ... Z=26)
            int digitValue = c - 'A' + 1;

            // Multiply the running total by the base (26) and add the new value
            result = result * 26 + digitValue;
        }

        return result;
    }
};

int main()
{
    string x;
    cin >> x;

    Solution solution;
    int val = solution.titleToNumber(x);
    cout << endl
         << val;
    return 0;
}