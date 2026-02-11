#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> strs;

        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                strs.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                strs.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                strs.push_back("Buzz");
            }
            else
            {
                strs.push_back(to_string(i));
            }
        }

        return strs;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Assuming input format: k, dist, n, then array
    if (cin >> n)
    {
        Solution sol;
        vector<string> result = sol.fizzBuzz(n);
        for (const string& s : result)
        {
            cout << s << endl;
        }
    }

    return 0;
}