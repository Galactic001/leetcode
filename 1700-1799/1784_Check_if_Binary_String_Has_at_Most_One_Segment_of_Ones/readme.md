# 1784. Check if Binary String Has at Most One Segment of Ones

## Problem Description

Given a binary string `s` **without leading zeros**, return `true` if `s` contains **at most one contiguous segment of ones**. Otherwise, return `false`.

**Example 1:**
* **Input:** `s = "1001"`
* **Output:** `false`
* **Explanation:** The ones do not form a contiguous segment. There are two segments of ones: one at the beginning and one at the end.

**Example 2:**
* **Input:** `s = "110"`
* **Output:** `true`

---

## Approach: The "01" Transition Logic

This problem can be solved in a single pass by looking for a very specific transition in the characters.


### Why looking for "01" works:
1.  **The Guarantee:** The problem states that the string has *no leading zeros*. This means every valid input string will always start with `'1'`.
2.  **The First Segment:** Because it starts with `'1'`, we know our first segment of ones begins immediately at index 0.
3.  **The Transition:** If the string only has one segment of ones, the characters can eventually turn to `'0'` (e.g., `"111000"`), but they can **never** turn back to `'1'`. 
4.  **The "01" Trigger:** The only way a *second* segment of ones can start is if the string transitions from a zero back to a one. That exact moment of transition is the substring `"01"`. 
5.  **Conclusion:** If we find `"01"` anywhere in the string, it proves there is a gap of zeros followed by a new segment of ones. If we scan the whole string and never see `"01"`, it means all the ones were bunched together at the front.