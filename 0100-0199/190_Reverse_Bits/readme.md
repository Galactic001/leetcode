# 190. Reverse Bits

## Problem Description

Reverse the bits of a given 32-bit unsigned integer.

**Note:**
* Input is a binary string of length 32.
* Output should be the unsigned integer value of the reversed binary string.

### Example 1
**Input:** `n = 00000010100101000001111010011100` (43261596)
**Output:** `964176192` (`00111001011110000010100101000000`)
**Explanation:** The input binary string is reversed.

---

## Approach: Bitwise Iteration

We need to build the reversed number bit by bit, from left to right.

### The Logic
Think of this like reversing a string, but with bits:
1.  **Initialize:** `ans = 0`.
2.  **Iterate:** Loop 32 times (since it's a 32-bit integer).
3.  **Extract & Append:**
    * Take the last bit of `n` (using `n & 1`).
    * Shift `ans` to the left to make room (`ans << 1`).
    * Add the extracted bit to the new empty spot in `ans`.
    * Shift `n` to the right to discard the used bit (`n >> 1`).

### Visual Trace
Input: `n = ...0011` (3), Loop 1:
1.  Last bit of `n` is `1`.
2.  `ans` shifts left (0 becomes 0), add `1` -> `ans = 1`.
3.  `n` shifts right -> `...001`.

Loop 2:
1.  Last bit of `n` is `1`.
2.  `ans` shifts left (`1` becomes `10`), add `1` -> `ans = 11` (3 in decimal).
3.  `n` shifts right -> `...000`.

... After 32 loops, the bits are fully reversed.

---