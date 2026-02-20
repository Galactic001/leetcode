# 283. Move Zeroes

## Problem Description

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

**Example 1:**
* **Input:** `nums = [0,1,0,3,12]`
* **Output:** `[1,3,12,0,0]`

**Example 2:**
* **Input:** `nums = [0]`
* **Output:** `[0]`

---

## Approach: Two Pointers (Slow and Fast)

To do this in-place (without creating a new array), we can use one pointer to iterate through the array and another pointer to keep track of where the next non-zero element should go.



### The Logic
1.  **Initialize a pointer:** Let `insertPos` = 0. This pointer represents the index where we will place the next non-zero number we find.
2.  **First Pass (Move non-zeroes):** Iterate through the array with a standard loop variable `i`.
    * If `nums[i]` is not `0`, we place it at `nums[insertPos]` and increment `insertPos`.
    * If `nums[i]` is `0`, we just keep going.
3.  **Second Pass (Fill with zeroes):** After the first loop finishes, all the non-zero elements are neatly packed at the front of the array. The `insertPos` variable now points to the index right after the last non-zero element. We just need a second loop to fill the rest of the array (from `insertPos` to the end) with `0`s.