# Solution Explanation: Minimum Pair Removal to Sort Array I (LeetCode 3507)

## 1. The Logic
The problem asks us to make the array sorted (non-decreasing) by repeatedly merging adjacent pairs.
**Constraint:** We *must* choose the adjacent pair with the **minimum sum**. If there's a tie, choose the **leftmost** one.

Since the input size is very small ($N \le 50$), we can simply **simulate** the process exactly as described without needing complex data structures like Heaps or Linked Lists (which might be needed for the "Hard" version of this problem).

### Algorithm Steps
1.  **Check Sorted:** If the array is already sorted, return 0.
2.  **Find Pair:** Loop through the array from `i = 0` to `Length - 2`. Calculate `sum = nums[i] + nums[i+1]`.
3.  **Identify Min:** Track the smallest sum found. Since we loop from left to right and only update on strictly smaller values (`<`), we naturally keep the leftmost pair in case of ties.
4.  **Merge:**
    * Set `nums[i]` to `sum`.
    * Remove `nums[i+1]`.
5.  **Repeat:** Increment the operation count and go back to Step 1.

## 2. Example Walkthrough
Input: `[5, 2, 3, 1]`

**Iteration 1:**
* Pairs: `(5,2)=7`, `(2,3)=5`, `(3,1)=4`.
* Min Sum is `4` at index 2 (values 3 and 1).
* Merge: `[5, 2, 4]`. Operations = 1.

**Iteration 2:**
* Pairs: `(5,2)=7`, `(2,4)=6`.
* Min Sum is `6` at index 1 (values 2 and 4).
* Merge: `[5, 6]`. Operations = 2.

**Check:** `[5, 6]` is sorted. Return 2.

## 3. Complexity Analysis

* **Time Complexity:** $O(N^2)$
    * In the worst case, we might reduce the array size from $N$ down to 1.
    * This takes $N$ operations.
    * In each operation, we scan the array ($O(N)$) and remove an element ($O(N)$).
    * Total: $N \times N = O(N^2)$. Since $N=50$, this is roughly 2,500 operations, which is instant.
* **Space Complexity:** $O(N)$
    * We store the array (or a list in C#).