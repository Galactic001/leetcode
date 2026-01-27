# Solution Explanation: Minimize Maximum Pair Sum (LeetCode 1877)

## 1. The Goal
We need to divide an array of $2n$ numbers into $n$ pairs such that the **largest sum among the pairs is as small as possible**.

## 2. The Strategy: Greedy (Smallest + Largest)
Imagine we have the numbers `[2, 3, 5, 3]`.
Sorted: `[2, 3, 3, 5]`.

If we pair small numbers with small numbers (`2+3`) and big with big (`3+5`), we get sums **5** and **8**. The maximum is **8**.
This is bad because the big numbers make the sum huge if they aren't "dampened" by a small number.

**Optimal Strategy:**
Pair the **smallest** number with the **largest** number.
* Pair `2` (Smallest) with `5` (Largest) -> Sum: 7
* Pair `3` (Next Smallest) with `3` (Next Largest) -> Sum: 6
* Max Sum is **7**. (7 < 8, so this is better).



## 3. Algorithm
1.  **Sort** the array in ascending order.
2.  Initialize two pointers: `left` (start) and `right` (end).
3.  Loop while `left < right`:
    * Calculate `sum = nums[left] + nums[right]`.
    * Update `maxSum` if this new sum is larger.
    * Move `left` forward and `right` backward.
4.  Return `maxSum`.

## 4. Complexity Analysis

* **Time Complexity:** $O(N \log N)$
    * Sorting the array is the most expensive operation. The pairing loop is only $O(N)$.
* **Space Complexity:** $O(1)$ (or $O(\log N)$ for sorting stack)
    * We perform the operations in-place on the sorted array.