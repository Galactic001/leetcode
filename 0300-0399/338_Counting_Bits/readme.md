# 338. Counting Bits

## Problem Description

Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the **number of `1`'s** in the binary representation of `i`.

**Example 1:**
* **Input:** `n = 2`
* **Output:** `[0,1,1]`
* **Explanation:**
  * 0 --> 0 (0 bits)
  * 1 --> 1 (1 bit)
  * 2 --> 10 (1 bit)

**Example 2:**
* **Input:** `n = 5`
* **Output:** `[0,1,1,2,1,2]`
* **Explanation:**
  * 0 --> 0 (0 bits)
  * 1 --> 1 (1 bit)
  * 2 --> 10 (1 bit)
  * 3 --> 11 (2 bits)
  * 4 --> 100 (1 bit)
  * 5 --> 101 (2 bits)

---

## Approach 1: Popcount in a Loop (Brute Force)

The easiest way to solve this is to simply loop from `0` to `n` and use C++'s built-in `__builtin_popcount` function (or Brian Kernighan's algorithm) for every single number. 

### Code (C++)
```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};
```

## Approach 2: Dynamic Programming (Even & Odd Pattern)

This is the optimal $O(N)$ solution that interviewers are looking for. Instead of counting the bits for every single number from scratch, we can use the results of previously calculated numbers to find the answer for the current number in $O(1)$ time.



### The Logic (The "Aha!" Moment)
If we look closely at how binary numbers increment, there is a direct relationship between a number `i` and `i / 2`. We can break this down into Evens and Odds:

1.  **Even Numbers:**
    * Think about multiplying a number by 2 in binary. It simply shifts all bits to the left and adds a `0` to the right end.
    * `2` is `10` ... `4` is `100` ... `8` is `1000`.
    * `3` is `11` ... `6` is `110` ... `12` is `1100`.
    * **Rule:** An even number `i` has the exact same number of 1s as `i / 2`.
2.  **Odd Numbers:**
    * An odd number is just the previous even number plus 1. In binary, that means changing the rightmost `0` to a `1`.
    * `2` is `10` (1 bit) -> `3` is `11` (2 bits).
    * `6` is `110` (2 bits) -> `7` is `111` (3 bits).
    * **Rule:** An odd number `i` has one more 1 than `i / 2`.

We can combine these two rules into a single, elegant bitwise formula:
`ans[i] = ans[i >> 1] + (i & 1)`
* `i >> 1` is exactly the same as `i / 2`.
* `i & 1` checks if the number is odd (adds 1) or even (adds 0).

### Code (C++)

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // Initialize an array of size n + 1 with zeros
        vector<int> ans(n + 1, 0);
        
        // Compute the bits for each number using previously calculated results
        for (int i = 1; i <= n; i++) {
            // ans[i / 2] + (1 if i is odd, 0 if i is even)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};

int main() {
    // File I/O setup for local testing
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    int n;

    // Read the integer n from input.txt
    if (cin >> n) {
        Solution sol;
        vector<int> result = sol.countBits(n);
        
        cout << "Bits count array: [";
        for (int i = 0; i <= n; i++) {
            cout << result[i] << (i == n ? "" : ", ");
        }
        cout << "]" << endl;
    }

    return 0;
}