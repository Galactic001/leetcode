# 2053. Kth Distinct String in an Array

## Problem Description

A **distinct string** is a string that is present only **once** in an array.

Given an array of strings `arr`, and an integer `k`, return the $k^{th}$ **distinct string** present in `arr`. If there are **fewer** than `k` distinct strings, return an **empty string** `""`.

Note that the strings are considered in the **order in which they appear** in the array.

**Example 1:**
* **Input:** `arr = ["d","b","c","b","c","a"], k = 2`
* **Output:** `"a"`
* **Explanation:**
  The only distinct strings in `arr` are `"d"` and `"a"`.
  `"d"` appears 1st, so it is the 1st distinct string.
  `"a"` appears 2nd, so it is the 2nd distinct string.
  Since `k == 2`, `"a"` is returned. 

**Example 2:**
* **Input:** `arr = ["aaa","aa","a"], k = 1`
* **Output:** `"aaa"`
* **Explanation:**
  All strings in `arr` are distinct, so the 1st string `"aaa"` is returned.

**Example 3:**
* **Input:** `arr = ["a","b","a"], k = 3`
* **Output:** `""`
* **Explanation:**
  The only distinct string is `"b"`. Since there are fewer than 3 distinct strings, we return an empty string `""`.

---

## Approach: Two-Pass Hash Map

To solve this efficiently, we need to know the frequency of every string, but we also need to respect the original order of the array. We can accomplish this by using a Hash Map (`unordered_map` in C++) and taking two separate passes through the data.

### The Logic
1.  **First Pass (Counting):** Iterate through the original array `arr`. For every string you encounter, increment its count in the Hash Map.
2.  **Second Pass (Ordering):** Iterate through the original array `arr` *again*. Because we are looping through the array (and not the Hash Map), we are guaranteed to evaluate the strings in their original sequence.
3.  **Evaluate:** For each string, check its frequency in the Hash Map. If the frequency is exactly `1`, it is a distinct string. 
4.  **Count Down:** Decrement `k`. If `k` reaches `0`, we have found our target! Return that string immediately.
5.  **Default:** If the second loop finishes and we haven't returned anything, it means there were fewer than `k` distinct strings. Return `""`.