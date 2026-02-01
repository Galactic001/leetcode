# Solution Explanation: Reverse by Type (LeetCode 3823)

## 1. The Problem
We need to reverse a string, but with a twist:
1.  **Letters** (`a-z`, `A-Z`) should be reversed **only among themselves**.
2.  **Non-Letters** (digits, symbols) should be reversed **only among themselves**.
3.  The positions (indices) that hold a "Letter" must always hold a "Letter," and positions holding a "Non-Letter" must always hold a "Non-Letter."

**Example:**
* Input: `a-1b`
* Reverse Letters (`a`...`b` -> `b`...`a`): `b-1a`
* Reverse Others (`-`...`1` -> `1`...`-`): `b1-a`
* Output: `b1-a`

## 2. Approach: Two-Pass Two-Pointer
Since the reversal of letters does not depend on the specific values of the numbers (and vice versa), we can solve this in **two separate passes** over the string.

### Pass 1: The Letter Swap
We use two pointers, `left` at the start and `right` at the end.
* If `s[left]` is NOT a letter, move `left` forward.
* If `s[right]` is NOT a letter, move `right` backward.
* If both are letters, **swap them** and move both pointers.
* *Result:* All alphabetic characters are now reversed relative to each other.

### Pass 2: The Special Char Swap
We reset the pointers and do the exact opposite.
* If `s[left]` IS a letter, move `left` forward (ignore it).
* If `s[right]` IS a letter, move `right` backward (ignore it).
* If both are non-letters, **swap them**.

## 3. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We iterate through the string exactly twice (once for letters, once for specials). $O(2N)$ simplifies to linear time $O(N)$.
* **Space Complexity:** $O(1)$
    * We modify the string in-place using only two integer pointers. We do not use any extra stack or array memory.