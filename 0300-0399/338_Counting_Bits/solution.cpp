#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
         vector<int> ans(n + 1, 0);
        
        // Compute the bits for each number using previously calculated results
        for (int i = 1; i <= n; i++) {
            // ans[i / 2] + (1 if i is odd, 0 if i is even)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};

int main()
{
    int x;
    cin >> x;

    Solution solution;
    vector<int> val = solution.countBits(x);

    cout << endl
         << "Final Array: ";

    for (int i = 0; i < val.size(); i++)
    {
        cout << val[i] << " ";
    }
    return 0;
}