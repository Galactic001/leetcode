# 75. Sort Colors

## Problem Description

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**
* **Input:** `nums = [2,0,2,1,1,0]`
* **Output:** `[0,0,1,1,2,2]`

**Example 2:**
* **Input:** `nums = [2,0,1]`
* **Output:** `[0,1,2]`

---

## Approach: Dutch National Flag Algorithm (Three Pointers)

To do this in a single pass, we can use three pointers to divide the array into four conceptual regions:
1.  **0s (Red):** At the beginning of the array.
2.  **1s (White):** In the middle of the array.
3.  **Unexplored:** Elements we haven't looked at yet.
4.  **2s (Blue):** At the end of the array.



### The Logic
We initialize three pointers: `low = 0`, `mid = 0`, and `high = nums.size() - 1`. We iterate using the `mid` pointer until it crosses the `high` pointer (`mid <= high`).

At each step, we check the value of `nums[mid]`:
* **Case 0 (nums[mid] == 0):** This belongs on the left side. Swap `nums[low]` and `nums[mid]`. Because we know the swapped element from `low` is a `1` (or a `0` if `low == mid`), we can safely move both `low` and `mid` forward.
* **Case 1 (nums[mid] == 1):** This is exactly where it belongs (in the middle). We just leave it there and move `mid` forward to check the next element.
* **Case 2 (nums[mid] == 2):** This belongs on the right side. Swap `nums[mid]` and `nums[high]`. We decrement `high` to expand the 2s section. **Crucially**, we *do not* increment `mid` here. The element we just swapped from the `high` index is unexplored, so we must evaluate it on the next loop iteration.