#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int leftCount = 0;
        int rightCount = 0;
        int wildcards = 0;

        // 1. Count frequencies of each move type
        for (char move : moves)
        {
            if (move == 'L')
            {
                leftCount++;
            }
            else if (move == 'R')
            {
                rightCount++;
            }
            else
            {
                wildcards++;
            }
        }

        // 2. Calculate the maximum possible distance
        return abs(leftCount - rightCount) + wildcards;
    }
};

int main()
{
    string x;
    cin >> x;

    Solution solution;
    int val = solution.furthestDistanceFromOrigin(x);
    cout << endl
         << val;
    return 0;
}