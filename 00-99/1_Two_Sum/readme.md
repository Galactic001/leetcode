# Solution Explanation: Two Sum (LeetCode 1)

## 1. The Brute Force Approach ($O(n^2)$)
The most intuitive way is to check every possible pair of numbers to see if they add up to the target.

* **Logic:**
    * Pick the first number `nums[i]`.
    * Loop through all *subsequent* numbers `nums[j]` (where `j > i`).
    * Check `nums[i] + nums[j] == target`.
* **Why `j = i + 1`?**
    * We must not use the same element twice (e.g., index `0` and `0`).
    * We avoid duplicate work (checking `0` and `1` is the same as checking `1` and `0`).

## 2. The Optimized Approach: Hash Map ($O(n)$)
We can solve this in one pass by "remembering" the numbers we have seen so far.

* **Logic:**
    * We iterate through the array.
    * For every number `x`, we calculate `needed = target - x`.
    * We ask the map: **"Have I seen `needed` before?"**
        * **Yes:** We found the pair! Return the index of `needed` and current index `i`.
        * **No:** Store `x` and its index `i` in the map and continue.



## 3. Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Brute Force** | $O(n^2)$ | $O(1)$ | Slow for large lists. No extra memory needed. |
| **Hash Map** | $O(n)$ | $O(n)$ | Very fast. Uses memory to store the map. |