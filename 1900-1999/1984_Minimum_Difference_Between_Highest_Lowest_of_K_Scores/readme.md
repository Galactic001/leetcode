# Solution Explanation: Min Difference of K Scores (LeetCode 1984)

## 1. The Intuition
The problem asks us to pick any `k` students such that the gap between the best and worst student in that group is minimal.

If we have scores `[9, 4, 1, 7]` and `k=2`:
* If we pick `1` and `9`, the gap is `8`. (Bad)
* If we pick `4` and `7`, the gap is `3`. (Better)
* If we pick `7` and `9`, the gap is `2`. (Best)

**Key Realization:** The minimal difference will always be found between numbers that are **adjacent** in the sorted sequence. It never makes sense to pick `1` and `7` while skipping `4`.

## 2. The Algorithm (Sort + Sliding Window)
1.  **Sort** the array in ascending order.
    * Input: `[9, 4, 1, 7]` -> Sorted: `[1, 4, 7, 9]`
2.  **Slide** a window of size `k`.
    * Because the array is sorted, for any window starting at `i`:
        * **Lowest Score:** `nums[i]`
        * **Highest Score:** `nums[i + k - 1]`
    * We simply calculate `Highest - Lowest` for every possible window.

### Walkthrough (k=2)
Sorted: `[1, 4, 7, 9]`

1.  **Window 1:** `[1, 4]`. Diff = $4 - 1 = 3$. Min = 3.
2.  **Window 2:** `[4, 7]`. Diff = $7 - 4 = 3$. Min = 3.
3.  **Window 3:** `[7, 9]`. Diff = $9 - 7 = 2$. Min = 2.

Result: **2**.

## 3. Complexity Analysis

* **Time Complexity:** $O(n \log n)$
    * Sorting takes $O(n \log n)$. The sliding window pass takes $O(n)$. The sort dominates.
* **Space Complexity:** $O(1)$ (or $O(\log n)$ depending on sort implementation)
    * We process the array in-place (mostly).