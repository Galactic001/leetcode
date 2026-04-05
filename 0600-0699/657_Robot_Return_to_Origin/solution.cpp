#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;
        
        // Simulate the movements along the X and Y axes
        for (char move : moves) {
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'R') {
                x++;
            } else if (move == 'L') {
                x--;
            }
        }
        
        // The robot is back at the origin if both x and y are exactly 0
        return (x == 0 && y == 0);
    }
};

int main()
{
    string x;
    cin >> x;

    Solution solution;
    bool val = solution.judgeCircle(x);
    cout << endl
         << val;
    return 0;
}