# 451. Sort Characters By Frequency

## Problem Description

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

**Example 1:**
* **Input:** `s = "tree"`
* **Output:** `"eert"`
* **Explanation:** 'e' appears twice while 'r' and 't' both appear once. So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

**Example 2:**
* **Input:** `s = "cccaaa"`
* **Output:** `"aaaccc"`
* **Explanation:** Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers. Note that "cacaca" is incorrect, as the same characters must be together.

**Example 3:**
* **Input:** `s = "Aabb"`
* **Output:** `"bbAa"`
* **Explanation:** `"bbaA"` is also a valid answer, but `"Aabb"` is incorrect. Note that 'A' and 'a' are treated as two different characters.

---

## Approach 1: Hash Map and Sorting (Standard)

The most intuitive way to solve this is to count the occurrences of each character, store them in a list of pairs, and sort that list based on the frequency.

### The Logic
1.  **Count Frequencies:** Use an integer array of size 128 (to cover all ASCII characters) to count how many times each character appears in the string.
2.  **Store Pairs:** Create a `vector<pair<int, char>>` and push only the characters that actually appeared, along with their frequencies.
3.  **Sort:** Sort the vector in descending order based on the frequency (the first element of the pair).
4.  **Build Result:** Iterate through the sorted vector and append the character to the result string `frequency` times.
