# 3740. Minimum Distance Between Three Equal Elements I

## Problem Description

You are given an integer array `nums`. A tuple `(i, j, k)` of 3 distinct indices is **good** if `nums[i] == nums[j] == nums[k]`. 

The distance of a good tuple is `abs(i - j) + abs(j - k) + abs(k - i)`, where `abs(x)` denotes the absolute value of `x`. 

Return an integer denoting the **minimum** possible distance of a good tuple. If no good tuples exist, return `-1`.

**Example 1:**
* **Input:** `nums = [1,2,1,1,3]`
* **Output:** `6`
* **Explanation:** The minimum distance is achieved by the good tuple `(0, 2, 3)`. It is a good tuple because `nums[0] == nums[2] == nums[3] == 1`. Its distance is `abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6`.

**Example 2:**
* **Input:** `nums = [1,1,2,3,2,1,2]`
* **Output:** `8`
* **Explanation:** The minimum distance is achieved by the good tuple `(2, 4, 6)`. It is a good tuple because `nums[2] == nums[4] == nums[6] == 2`. Its distance is `abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8`.

**Example 3:**
* **Input:** `nums = [1]`
* **Output:** `-1`
* **Explanation:** There are no good tuples. Therefore, the answer is `-1`.

---

## Approach: Hash Map and Mathematical Simplification (Optimal)

At first glance, calculating `abs(i - j) + abs(j - k) + abs(k - i)` feels tedious. However, if we assume our three indices are sorted such that $i < j < k$, we can drop the absolute values!

[Image of a number line demonstrating that the distance between three points simplifies to twice the distance of the outer points]

### The Logic (The "Aha!" Moment)
If $i < j < k$:
* `abs(i - j)` becomes `j - i`
* `abs(j - k)` becomes `k - j`
* `abs(k - i)` becomes `k - i`

Let's add them together:
`Distance = (j - i) + (k - j) + (k - i)`

Notice that the positive `j` and negative `j` cancel each other out entirely!
`Distance = -i + k + k - i`
`Distance = 2k - 2i`
`Distance = 2 * (k - i)`

**Conclusion:** The distance of a good tuple depends *only* on the distance between the first index and the third index. The middle index does not affect the total distance at all! Therefore, to find the minimum distance, we just need to group the indices of identical elements and look at every sliding window of 3 consecutive indices.