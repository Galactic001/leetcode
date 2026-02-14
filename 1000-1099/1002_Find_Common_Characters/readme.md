# 1002. Find Common Characters

## Problem Description

Given a string array `words`, return an array of all characters that show up in all strings within the list (including duplicates). You may return the answer in any order.

**Example 1:**
* **Input:** `words = ["bella","label","roller"]`
* **Output:** `["e","l","l"]`
* **Explanation:**
    * 'e' appears in all three strings.
    * 'l' appears twice in "bella", twice in "label", and twice in "roller". So we include it twice.

**Example 2:**
* **Input:** `words = ["cool","lock","cook"]`
* **Output:** `["c","o"]`

---

## Approach: Frequency Intersection

To find characters common to *all* strings, we need to find the **minimum frequency** of each character across every string.

### The Logic
1.  **Initialize:** Create a `min_freq` array of size 26 (for a-z) initialized with infinity (or the counts of the first word). This array will store the maximum possible count of each character that is valid so far.
2.  **Iterate:** Loop through every remaining string in the input array.
3.  **Count & Compare:**
    * For the current string, calculate its own character frequency (let's call it `char_count`).
    * Update the `min_freq` array: `min_freq[i] = min(min_freq[i], char_count[i])`.
    * If a character doesn't appear in the current string, its count is 0, so the minimum becomes 0 (eliminating it from the result).
4.  **Construct Result:** Loop through the final `min_freq` array. If `min_freq[i]` is 2, add that character to the result list 2 times.

### Visual Example
* **Word 1: "bella"** -> `min_freq` = {b:1, e:1, l:2, a:1, ...others:0}
* **Word 2: "roller"** -> `current_counts` = {r:2, o:1, l:2, e:1}
    * Update `min_freq`:
    * 'b': min(1, 0) -> 0
    * 'e': min(1, 1) -> 1
    * 'l': min(2, 2) -> 2
    * 'a': min(1, 0) -> 0
* **Result:** 'e' (1 time), 'l' (2 times).

---