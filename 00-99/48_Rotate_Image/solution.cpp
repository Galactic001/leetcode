#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // 1. Transpose the matrix
        // We only loop through the top-right triangle to avoid swapping back
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. Reverse each row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n, k;

    // Assuming input format: k, n, then array
    if (cin >> k >> n)
    {
        vector<vector<int>> nums(n, vector<int>(k));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> nums[i][j];
            }
        }

        Solution sol;
        // Ensure method name matches your Solution class
        sol.rotate(nums);
        cout << "Result: ";

        for (int l = 0; l < n; l++)
        {
            for (int m = 0; m < k; m++)
            {
                cout << nums[l][m] << " ";
            }
            cout << "| ";
        }
    }

    return 0;
}