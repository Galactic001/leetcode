# 58. Length of Last Word

## Problem Description

Given a string `s` consisting of words and spaces, return the length of the **last** word in the string.

A **word** is a maximal substring consisting of non-space characters only.

**Example 1:**
* **Input:** `s = "Hello World"`
* **Output:** `5`
* **Explanation:** The last word is "World" with length 5.

**Example 2:**
* **Input:** `s = "   fly me   to   the moon  "`
* **Output:** `4`
* **Explanation:** The last word is "moon" with length 4.

**Example 3:**
* **Input:** `s = "luffy is still joyboy"`
* **Output:** `6`
* **Explanation:** The last word is "joyboy" with length 6.

---

## Approach: Reverse Iteration

Instead of splitting the entire string into an array of words (which requires extra memory and time), the most efficient approach is to start from the very end of the string and read backwards.



### The Logic
1.  **Initialize Pointers:** Start an index `i` at the last character of the string (`s.length() - 1`). Initialize a `length` counter to `0`.
2.  **Trim Trailing Spaces:** It's possible the string ends with multiple spaces (like Example 2). We use a `while` loop to decrement `i` as long as `s[i]` is a space `' '`.
3.  **Count the Word:** Once we hit a non-space character, we've found the end of the last word. We use another `while` loop to count the characters, decrementing `i` and incrementing `length` until we either hit another space (the start of the word) or reach the beginning of the string (`i < 0`).
4.  **Return:** Return the final `length`.