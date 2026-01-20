# Solution Explanation: Remove Element (LeetCode 27)

## 1. The Trap: Using `erase()`
Using `vector.erase()` inside a loop is dangerous and inefficient.
1.  **The Skip Bug:** If you have `[2, 2]` and erase the first `2`, the second `2` shifts left to index 0. But your loop performs `i++` and moves to index 1. Result: You skipped the second `2`.
2.  **Efficiency:** `erase()` forces all subsequent elements to shift. Doing this repeatedly makes the algorithm $O(N^2)$ (quadratic time).

## 2. The Solution: Two Pointers (Reader/Writer)
We use a **Writer Pointer** to overwrite the array in-place. We don't actually "delete" the bad numbers; we just overwrite them with the good numbers.

* **`i` (Reader):** Scans the array from start to finish.
* **`writer` (Writer):** Indicates where the next *valid* number should be placed.

### Walkthrough
Input: `[3, 2, 2, 3]`, remove `3`.

1.  **`i=0`, `val=3`**: It's a `3`. Ignore it. (`writer` stays at 0).
2.  **`i=1`, `val=2`**: It's good! Copy `2` to `nums[writer]` (index 0). Increment `writer` to 1.
    * *Array state:* `[2, 2, 2, 3]`
3.  **`i=2`, `val=2`**: It's good! Copy `2` to `nums[writer]` (index 1). Increment `writer` to 2.
    * *Array state:* `[2, 2, 2, 3]`
4.  **`i=3`, `val=3`**: It's a `3`. Ignore it.

**Result:** `writer` is 2. The first 2 elements are `[2, 2]`. We return 2.

## 3. Complexity Analysis

* **Time Complexity:** $O(n)$
    * We traverse the array exactly once.
* **Space Complexity:** $O(1)$
    * We modify the array in-place without using extra storage.