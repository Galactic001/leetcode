# 46. Permutations

## Problem Description

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in **any order**.

**Example 1:**
* **Input:** `nums = [1,2,3]`
* **Output:** `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

**Example 2:**
* **Input:** `nums = [0,1]`
* **Output:** `[[0,1],[1,0]]`

**Example 3:**
* **Input:** `nums = [1]`
* **Output:** `[[1]]`

---

## Approach: Backtracking (In-Place Swapping)

The goal is to build permutations one element at a time. We can think of the array as having two parts: the "fixed" part (elements we've already chosen for the current permutation) and the "unexplored" part.



### The Logic
We use a recursive function `backtrack(start)` where `start` is the index separating the fixed part from the unexplored part.

1.  **Base Case:** If `start` reaches the end of the array (`start == nums.size()`), it means we have fixed all positions. We've found a complete permutation, so we add the current state of `nums` to our results.
2.  **Recursive Step:** Iterate through the unexplored elements (from `i = start` to the end).
    * **Choose:** Swap the element at `start` with the element at `i`. This puts a new element at the current position we are trying to fill.
    * **Explore:** Recursively call `backtrack(start + 1)` to fill the *next* position.
    * **Un-choose (Backtrack):** Once the recursive call returns, we must undo the swap (`swap(nums[start], nums[i])`) to restore the array to its previous state. This allows us to explore the next sibling branch in the recursion tree cleanly.