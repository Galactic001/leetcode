# 1980. Find Unique Binary String

## Problem Description

Given an array of strings `nums` containing `n` **unique** binary strings each of length `n`, return a binary string of length `n` that **does not appear** in `nums`. If there are multiple answers, you may return **any** of them.

**Example 1:**
* **Input:** `nums = ["01","10"]`
* **Output:** `"11"`
* **Explanation:** "11" does not appear in nums. "00" would also be correct.

**Example 2:**
* **Input:** `nums = ["00","01"]`
* **Output:** `"11"`
* **Explanation:** "11" does not appear in nums. "10" would also be correct.

**Example 3:**
* **Input:** `nums = ["111","011","001"]`
* **Output:** `"101"`
* **Explanation:** "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

---

## Approach: Cantor's Diagonalization

Georg Cantor famously used a diagonal argument to prove that there are different sizes of infinity. We can borrow his exact logic to build a string that is mathematically guaranteed to be missing from the array.


### The Logic (The "Aha!" Moment)
We need to build a new string of length `n` that is different from every string currently in the array. 

1.  Look at the **1st string** at index `0`. Take its **1st character** (at index `0`), and flip it. Put this flipped character in the `0` index of our new string. Now, our new string is guaranteed to be different from the 1st string.
2.  Look at the **2nd string** at index `1`. Take its **2nd character** (at index `1`), and flip it. Put this flipped character in the `1` index of our new string. Now, our new string is guaranteed to be different from the 2nd string.
3.  **Generalizing:** For every string `nums[i]`, we look at character `nums[i][i]`. If it is a `'0'`, we append a `'1'` to our result. If it is a `'1'`, we append a `'0'`.
4.  Because our result string differs from the $i$-th string at the $i$-th position, it is impossible for our result string to match *any* string in the input array.