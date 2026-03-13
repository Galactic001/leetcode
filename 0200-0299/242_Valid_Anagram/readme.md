# 242. Valid Anagram

## Problem Description

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
* **Input:** `s = "anagram"`, `t = "nagaram"`
* **Output:** `true`

**Example 2:**
* **Input:** `s = "rat"`, `t = "car"`
* **Output:** `false`

---

## Approach 1: Sorting

If the two strings are true anagrams, they must contain the exact same characters in the exact same frequencies. Therefore, sorting them alphabetically will always produce two perfectly identical strings.

### The Logic
1.  **Length Check:** If the strings are of different lengths, they cannot be anagrams. Return `false` immediately to save time.
2.  **Sort:** Use the built-in `std::sort` function to rearrange the characters of both `s` and `t` in alphabetical order.
3.  **Compare:** Return the result of the direct string comparison `s == t`.