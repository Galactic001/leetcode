# Solution Explanation: Reverse Only Letters (LeetCode 917)

## 1. The Challenge
We need to reverse the string, but symbols (like `-`, `!`, `?`, numbers) must stay in their original positions. Only the English letters (`a-z`, `A-Z`) should move.

**Example:**
* Input: `a-bC-dEf-ghIj`
* Output: `j-Ih-gfE-dCba`

## 2. Approach: Two Pointers (Collision)
We use the standard "start and end" pointer strategy.

1.  **Initialize:** `left` at 0, `right` at `n-1`.
2.  **Loop:** While `left < right`:
    * **Check Left:** Is `s[left]` a letter? If not, `left++` (skip it).
    * **Check Right:** Is `s[right]` a letter? If not, `right--` (skip it).
    * **Swap:** If **both** are letters, swap them and move both pointers inward.

## 3. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We process every character at most once.
* **Space Complexity:**
    * **C++:** $O(1)$ (We modify the string in-place).
    * **C# / Java:** $O(N)$ (Strings are immutable, so we must create a character array first).