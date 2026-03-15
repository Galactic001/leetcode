# 28. Find the Index of the First Occurrence in a String

## Problem Description

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**
* **Input:** `haystack = "sadbutsad"`, `needle = "sad"`
* **Output:** `0`
* **Explanation:** `"sad"` occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.

**Example 2:**
* **Input:** `haystack = "leetcode"`, `needle = "leeto"`
* **Output:** `-1`
* **Explanation:** `"leeto"` did not occur in `"leetcode"`, so we return -1.

---

## Approach 1: Sliding Window (Two Pointers)

Instead of creating new substrings (which takes extra memory and time), we can slide a "window" the exact size of the `needle` across the `haystack` and compare characters one by one.



### The Logic
1.  **Determine Boundaries:** We don't need to check all the way to the end of the `haystack`. We can stop when the remaining characters are fewer than the length of the `needle` (specifically, at `haystack.length() - needle.length()`).
2.  **Outer Loop:** Iterate a pointer `i` through the valid starting positions in the `haystack`.
3.  **Inner Loop:** For each starting position `i`, use a second pointer `j` to iterate through the `needle`.
    * If `haystack[i + j] == needle[j]`, keep going.
    * If the characters don't match, break the inner loop immediately.
4.  **Match Found:** If the inner loop finishes and `j` is equal to the length of the `needle`, it means every single character matched. Return the starting index `i`.
5.  **No Match:** If the outer loop finishes without finding a match, return `-1`.