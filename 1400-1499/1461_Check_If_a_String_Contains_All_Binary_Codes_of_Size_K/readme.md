# 1461. Check If a String Contains All Size K Binary Codes

## Problem Description

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

**Example 1:**
* **Input:** `s = "00110110"`, `k = 2`
* **Output:** `true`
* **Explanation:** The binary codes of length 2 are `"00"`, `"01"`, `"10"`, and `"11"`. They can be all found as substrings at indices 0, 1, 3, and 2 respectively.

**Example 2:**
* **Input:** `s = "0110"`, `k = 1`
* **Output:** `true`
* **Explanation:** The binary codes of length 1 are `"0"` and `"1"`, which are both substrings.

**Example 3:**
* **Input:** `s = "0110"`, `k = 2`
* **Output:** `false`
* **Explanation:** The binary code `"00"` is of length 2, but it doesn't exist in `s`.

---

## Approach 1: Hash Set (Sliding Window)

The total number of unique binary codes of length `k` is exactly $2^k$. 
Instead of generating all $2^k$ possible codes and searching the string for them, we can do the reverse: extract all substrings of length `k` from `s`, put them into a Set, and check if the Set size reaches $2^k$.



### The Logic
1.  **Early Exit:** If the string is shorter than $2^k$, it's impossible for it to contain all $2^k$ codes. We can return `false` immediately. Note: `1 << k` is a fast bitwise way to calculate $2^k$.
2.  **Slide a Window:** Loop through the string, extracting substrings of length `k`.
3.  **Hash Set:** Insert each extracted substring into an `unordered_set`. The set automatically handles duplicates.
4.  **Final Check:** Return `true` if the size of the set is exactly $2^k$.