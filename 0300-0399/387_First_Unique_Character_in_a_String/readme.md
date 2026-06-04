# 387. First Unique Character in a String

## Problem Description

Given a string `s`, find the first non-repeating character in it and return its index. If it does not exist, return `-1`.

**Example 1:**
* **Input:** `s = "leetcode"`
* **Output:** `0`
* **Explanation:** The character 'l' appears only once and is at index 0.

**Example 2:**
* **Input:** `s = "loveleetcode"`
* **Output:** `2`
* **Explanation:** The characters 'l', 'o', and 'e' repeat. The first non-repeating character is 'v' at index 2.

**Example 3:**
* **Input:** `s = "aabb"`
* **Output:** `-1`
* **Explanation:** All characters repeat, so there are no unique characters.

---

## Approach 1: Hash Map

The most straightforward way to track frequencies of elements without worrying about the underlying character set is to use a Hash Map. We can count the occurrences in one pass, and then find the first character with a count of exactly 1 in a second pass.

### The Logic
1.  **Count Frequencies:** Iterate through the string `s`. For every character, increment its frequency count in an `unordered_map`.
2.  **Find the First Unique:** Iterate through the original string `s` a second time. Because we iterate through the string and not the map, we are guaranteed to evaluate the characters in their original order.
3.  **Return:** If we find a character where `freq[s[i]] == 1`, we immediately return that index `i`. If the loop finishes without returning, we return `-1`.