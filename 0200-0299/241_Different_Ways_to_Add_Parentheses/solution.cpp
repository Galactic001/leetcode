#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> results;

        // 1. Iterate through the string
        for (int i = 0; i < expression.length(); i++)
        {
            char c = expression[i];

            // 2. Split when we find an operator
            if (c == '+' || c == '-' || c == '*')
            {
                // 3. Conquer: recursively evaluate left and right parts
                vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

                // 4. Combine: compute all pairs of left and right results
                for (int leftVal : leftResults)
                {
                    for (int rightVal : rightResults)
                    {
                        if (c == '+')
                        {
                            results.push_back(leftVal + rightVal);
                        }
                        else if (c == '-')
                        {
                            results.push_back(leftVal - rightVal);
                        }
                        else if (c == '*')
                        {
                            results.push_back(leftVal * rightVal);
                        }
                    }
                }
            }
        }

        // 5. Base Case: if no operators were found, it's just a number
        if (results.empty())
        {
            results.push_back(stoi(expression));
        }

        return results;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    string str;

    // Assuming input format: k, n, then array
    if (cin >> str)
    {

        Solution sol;
        vector<int> result = sol.diffWaysToCompute(str);
        // Ensure method name matches your Solution class
        cout << "Values: ";
        for (int val : result)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}