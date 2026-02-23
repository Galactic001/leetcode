# 868. Binary Gap

## Problem Description

Given a positive integer `n`, find and return the **longest distance** between any two adjacent `1`'s in the binary representation of `n`. If there are no two adjacent `1`'s, return `0`.

Two `1`'s are adjacent if there are only `0`'s separating them (possibly no `0`'s). The distance between two `1`'s is the absolute difference between their bit positions.

**Example 1:**
* **Input:** `n = 22`
* **Output:** `2`
* **Explanation:** 22 in binary is `10110`.
  The first adjacent pair of 1's is `10110` (from right to left, index 1 and 2). Distance = 2 - 1 = 1.
  The second adjacent pair of 1's is `10110` (index 2 and 4). Distance = 4 - 2 = 2.
  The maximum distance is 2.

**Example 2:**
* **Input:** `n = 8`
* **Output:** `0`
* **Explanation:** 8 in binary is `1000`. There are not enough 1's to form a pair.

**Example 3:**
* **Input:** `n = 5`
* **Output:** `2`
* **Explanation:** 5 in binary is `101`. Distance between the 1 at index 0 and the 1 at index 2 is 2 - 0 = 2.

---

## Approach: One-Pass Bit Shift

We can find the distance by iterating through the bits of `n` one by one, keeping track of the position of the *most recently seen* `1`. 



### The Logic
1.  **State Variables:** * `last_pos`: To store the index of the last `1` we saw. Initialize it to `-1` to indicate we haven't seen any `1`s yet.
    * `current_pos`: To track our current bit index (starting at 0).
    * `max_gap`: To keep a running maximum of the distances found.
2.  **Iterate:** Loop while `n > 0`.
3.  **Check the Last Bit:** Use `n & 1` to check if the current rightmost bit is `1`.
    * If it is a `1`, check if `last_pos` is not `-1` (meaning we've found a pair).
    * Calculate the distance: `current_pos - last_pos`.
    * Update `max_gap` using `max()`.
    * Update `last_pos` to the `current_pos` (since this `1` will be the "last seen" for the next `1` we find).
4.  **Shift & Increment:** Shift `n` to the right (`n >>= 1`) to process the next bit, and increment `current_pos`.