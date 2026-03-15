# 1415. The k-th Lexicographical String of All Happy Strings of Length n

## Problem Description

A **happy string** is a string that:
* Consists only of letters of the set `['a', 'b', 'c']`.
* `s[i] != s[i + 1]` for all values of `i` from `1` to `s.length - 1` (string is 1-indexed).

For example, strings `"abc"`, `"ac"`, `"b"` and `"abcbabcbcb"` are all happy strings, while strings `"aa"`, `"baa"` and `"ababbc"` are not.

Given two integers `n` and `k`, consider a list of all happy strings of length `n` sorted in lexicographical order. 

Return the `k`-th string of this list or return an **empty string** if there are less than `k` happy strings of length `n`.

**Example 1:**
* **Input:** `n = 1`, `k = 3`
* **Output:** `"c"`
* **Explanation:** The list `["a", "b", "c"]` contains all happy strings of length 1. The 3rd string is `"c"`.

**Example 2:**
* **Input:** `n = 3`, `k = 9`
* **Output:** `"cab"`
* **Explanation:** There are 12 different happy string of length 3. The lexicographical sorted list is: 
`["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]`. The 9th string is `"cab"`.

---

## Approach: Backtracking (Depth-First Search)

Since the maximum value for `n` is `10`, the total number of happy strings is relatively small ($3 \times 2^{n-1}$, which is at most $3 \times 512 = 1536$). This makes generating them via backtracking very efficient.

### The Logic
1.  **State Variables:** We need a string `current` to build our current permutation, an integer `count` to track how many valid strings we've formed, and a `result` string to store the final answer.
2.  **Recursive Function:** Create a `backtrack` function that tries to append `'a'`, `'b'`, and `'c'` to the `current` string.
3.  **Validity Check:** Before appending a character, ensure the `current` string is either empty, or the last character is different from the one we are about to append.
4.  **Base Case:** When `current.length() == n`, we have successfully formed a valid happy string. We increment our `count`.
    * If `count == k`, we have found our target! We save it to `result` and can stop exploring further.
5.  **Early Exit Optimization:** After the recursive call returns, check if `result` is already filled. If it is, immediately return out of all recursive calls to save time.