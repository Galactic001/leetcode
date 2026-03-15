#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        string result = "";
        string current = "";
        int count = 0;

        backtrack(n, k, count, current, result);

        return result;
    }   

private:
    void backtrack(int n, int k, int &count, string &current, string &result)
    {
        // Base case: we built a string of length n
        if (current.length() == n)
        {
            count++;
            // If this is the k-th string, store it
            if (count == k)
            {
                result = current;
            }
            return;
        }

        // Try appending 'a', 'b', and 'c' in alphabetical order
        for (char c : {'a', 'b', 'c'})
        {
            // Check the happy string condition (no adjacent identical characters)
            if (current.empty() || current.back() != c)
            {

                // Choose
                current.push_back(c);

                // Explore
                backtrack(n, k, count, current, result);

                // Optimization: If we already found the answer, stop searching
                if (!result.empty())
                {
                    return;
                }

                // Un-choose (Backtrack)
                current.pop_back();
            }
        }
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n, k;

    // Assuming input format: k, n, then array
    if (cin >> n >> k)
    {

        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Value: " << sol.getHappyString(n, k) << endl;
    }

    return 0;
}