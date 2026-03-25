# 349. Intersection of Two Arrays

## Problem Description

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be **unique** and you may return the result in **any order**.

**Example 1:**
* **Input:** `nums1 = [1,2,2,1]`, `nums2 = [2,2]`
* **Output:** `[2]`

**Example 2:**
* **Input:** `nums1 = [4,9,5]`, `nums2 = [9,4,9,8,4]`
* **Output:** `[9,4]`
* **Explanation:** `[4,9]` is also accepted.

---

## Approach 1: Hash Sets (Optimal Time)

The most direct way to find common elements is to use a Hash Set. Hash Sets provide $O(1)$ average time complexity for lookups and automatically handle duplicate values for us.



### The Logic
1.  **Convert to Set:** Put all the elements of `nums1` into an `unordered_set`. This removes any duplicates within `nums1` and allows for instant lookups.
2.  **Find Intersections:** Iterate through `nums2`. For each number, check if it exists in our `nums1` set.
3.  **Store Unique Results:** If it exists, add it to a `resultSet`. We use a second set for the results to ensure that if `nums2` has duplicate intersecting numbers (like `[2,2]` in Example 1), we only record the intersection once.
4.  **Convert and Return:** Finally, convert the `resultSet` back into a standard `vector` to match the required return type.