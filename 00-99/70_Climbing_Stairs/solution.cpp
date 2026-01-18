#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        if (n <= 1) return n;

        int s1 = 0;
        int s2 = 1;
        int result = 0;

        for (int i = 1; i <= n; i++)
        {
            result = s1 + s2;
            s1 = s2;
            s2 = result;
        }

        return result;
    }
};

int main()
{
    int x;
    cin >> x;
    Solution solution;
    int val = solution.climbStairs(x);
    cout << endl
         << val;
}