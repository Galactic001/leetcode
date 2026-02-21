#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int val = 0;
        int count = 0;

        while (left <= right)
        {
            val = countSetBits(left);
            left++;

            if (isPrime(val))
            {
                count++;
            }
        }

        return count;
    }

private:
    int countSetBits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            // n & (n - 1) unsets the rightmost set bit
            n &= (n - 1);
            count++;
        }
        return count;
    }

private:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        // Count the divisors of n
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

int main()
{
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n, k;

    // Assuming input format: k, dist, n, then array
    if (cin >> n >> k)
    {
        Solution sol;
        // Ensure method name matches your Solution class
        cout << "Total Set Bits: " << sol.countPrimeSetBits(n, k) << endl;
    }

    return 0;
}