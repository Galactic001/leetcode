# Solution Explanation: Minimum Absolute Difference (LeetCode 1200)

## 1. The Key Insight (Sorting)
If you have a set of numbers, the pair with the smallest difference **must** be adjacent if you sort the numbers.

* Example: `[4, 2, 1, 3]`
* Sorted: `[1, 2, 3, 4]`

The difference between `1` and `4` will always be larger than the difference between `1` and `2`. Therefore, we don't need to check every pair ($O(N^2)$). We only need to check neighbors ($O(N)$) after sorting.

## 2. Algorithm: The "Clean-Slate" Approach
We can solve this in a single pass over the sorted array. We maintain a `minDiff` variable.

* **If `currentDiff < minDiff`:**
    * We found a new "best" difference.
    * **Action:** Clear our entire result list (throw away the old pairs) and start a fresh list with this current pair. Update `minDiff`.
* **If `currentDiff == minDiff`:**
    * We found another pair just as good as the current best.
    * **Action:** Add this pair to the result list.
* **If `currentDiff > minDiff`:**
    * Ignore it.



## 3. Complexity Analysis

* **Time Complexity:** $O(N \log N)$
    * Sorting the array takes $O(N \log N)$. The subsequent linear scan takes $O(N)$.
* **Space Complexity:** $O(N)$ (or $O(\log N)$)
    * We need space to store the output pairs. The sorting algorithm may also take stack space ($O(\log N)$).