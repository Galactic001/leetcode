#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalWaviness(int num1, int num2)
    {
        int total_waviness = 0;

        for (int i = num1; i <= num2; ++i)
        {
            string s = to_string(i);
            int len = s.length();

            // Numbers with less than 3 digits have 0 waviness
            if (len < 3)
                continue;

            // Start at 1 and end at len - 2 to avoid checking first and last digits
            for (int j = 1; j < len - 1; ++j)
            {
                if (s[j] > s[j - 1] && s[j] > s[j + 1])
                {
                    total_waviness++; // Peak
                }
                else if (s[j] < s[j - 1] && s[j] < s[j + 1])
                {
                    total_waviness++; // Valley
                }
            }
        }

        return total_waviness;
    }
};

int main()
{
    int x, y;
    cin >> x >> y;

    Solution solution;
    int val = solution.totalWaviness(x, y);
    cout << endl
         << val;
    return 0;
}