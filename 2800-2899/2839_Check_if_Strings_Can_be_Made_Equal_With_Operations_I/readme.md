# 2839. Check if Strings Can be Made Equal With Operations I

## Problem Description

You are given two strings `s1` and `s2`, both of length `4`, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:
* Choose any two indices `i` and `j` such that `j - i = 2`, then swap the two characters at those indices in the string.

Return `true` if you can make the strings `s1` and `s2` equal, and `false` otherwise.

**Example 1:**
* **Input:** `s1 = "abcd"`, `s2 = "cdab"`
* **Output:** `true`
* **Explanation:** We can do the following operations on `s1`:
  - Choose the indices `0` and `2`. The resulting string is `s1 = "cbad"`.
  - Choose the indices `1` and `3`. The resulting string is `s1 = "cdab" = s2`.

**Example 2:**
* **Input:** `s1 = "abcd"`, `s2 = "dacb"`
* **Output:** `false`
* **Explanation:** It is not possible to make the two strings equal.

---

## Approach 1: Greedy Swapping (Your Approach)

Since the strings are exactly 4 characters long, the swapping rules dictate that:
* Index `0` can only ever swap with Index `2`.
* Index `1` can only ever swap with Index `3`.

Because of this strict limitation, we can simply look at the first two characters of `s1`. If they don't match the corresponding characters in `s2`, we are forced to swap them with their `i + 2` counterparts. After making these forced swaps, if the strings are still not equal, it's impossible.