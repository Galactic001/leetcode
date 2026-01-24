# Solution Explanation: Search Insert Position (LeetCode 35)

## 1. The Requirement: $O(\log n)$
The problem asks us to find a target in a **sorted** array. If we just scanned the array one by one, it would be $O(n)$. To achieve $O(\log n)$, we must use **Binary Search**.

## 2. The Logic (Binary Search)
We maintain two pointers, `left` and `right`, defining the current search range.

1.  Calculate `mid`.
2.  **Match:** If `nums[mid] == target`, we found it! Return `mid`.
3.  **Too Small:** If `nums[mid] < target`, the target must be in the right half. We move `left` to `mid + 1`.
4.  **Too Big:** If `nums[mid] > target`, the target must be in the left half. We move `right` to `mid - 1`.

## 3. The "Insertion" Trick
The tricky part is what happens when the number **isn't** found.
* The loop runs while `left <= right`.
* When the loop breaks (because `left > right`), the `left` pointer will always end up exactly at the index where the target **should** be.
* **Example:** `[1, 3, 5, 6]`, target `2`.
    * `mid` is `3`. `3 > 2`, so `right` moves left.
    * `mid` becomes `1`. `1 < 2`, so `left` moves right.
    * `left` is now pointing at index 1 (value 3). This is exactly where `2` belongs.

## 4. Complexity Analysis

* **Time Complexity:** $O(\log n)$
    * We cut the search space in half during every iteration.
* **Space Complexity:** $O(1)$
    * We only use 3 variables (`left`, `right`, `mid`).