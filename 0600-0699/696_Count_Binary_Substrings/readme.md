# 696. Count Binary Substrings

## Problem Description

Given a binary string `s`, return the number of non-empty substrings that have the same number of `0`'s and `1`'s, and all the `0`'s and all the `1`'s in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

**Example 1:**
* **Input:** `s = "00110011"`
* **Output:** `6`
* **Explanation:** There are 6 substrings that have equal number of consecutive 1's and 0's: `"00"`, `"11"`, `"00"`, `"11"` (Wait, the actual valid ones are `"0011"`, `"01"`, `"1100"`, `"10"`, `"0011"`, and `"01"`).

**Example 2:**
* **Input:** `s = "10101"`
* **Output:** `4`
* **Explanation:** There are 4 substrings: `"10"`, `"01"`, `"10"`, `"01"` that have equal number of consecutive 1's and 0's.

---

## Approach: Optimized Linear Scan ($O(1)$ Space)

Instead of storing the lengths of all groups of contiguous `0`s and `1`s in an array, we can calculate the valid substrings "on-the-fly". We only ever need to know the length of the *current* group of identical characters and the length of the *immediately previous* group.


### The Logic
1.  **State Variables:** We maintain two variables:
    * `curr_len`: The length of the current streak of identical characters (starts at 1).
    * `prev_len`: The length of the previous streak of identical characters (starts at 0).
2.  **Iterate:** Walk through the string starting from the second character (`i = 1`).
3.  **Check for Changes:**
    * If the current character matches the previous one (`s[i] == s[i-1]`), our current streak continues. Increment `curr_len`.
    * If the character changes (e.g., from '0' to '1'), it means our current streak has ended. At this boundary, the number of valid alternating substrings we can form is exactly `min(prev_len, curr_len)`.
    * We add that minimum to our total `ans`.
    * Then, we prepare for the next group: the old `curr_len` becomes the new `prev_len`, and we reset `curr_len` to 1.
4.  **Final Group:** After the loop finishes, we must perform one last `min(prev_len, curr_len)` check to account for the transition into the very last group of characters.