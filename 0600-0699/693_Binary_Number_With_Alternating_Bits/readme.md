# 693. Binary Number with Alternating Bits

## Problem Description

Given a positive integer `n`, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

**Example 1:**
* **Input:** `n = 5`
* **Output:** `true`
* **Explanation:** The binary representation of 5 is: `101`

**Example 2:**
* **Input:** `n = 7`
* **Output:** `false`
* **Explanation:** The binary representation of 7 is: `111`

**Example 3:**
* **Input:** `n = 11`
* **Output:** `false`
* **Explanation:** The binary representation of 11 is: `1011`

---

## Approach 1: Bitwise XOR Trick

This is the most elegant and efficient way to solve the problem without iterating through bits.

### The Logic
1.  **XOR with Shift:**
    * If `n` has alternating bits (e.g., `10101`), then shifting it right by 1 gives `01010`.
    * If we XOR `n` and `n >> 1`, all the alternating bits will align to produce a stream of **only 1s**.
    * Example:
        `n      = 10101`
        `n >> 1 = 01010`
        `XOR    = 11111`
2.  **Verify All 1s:**
    * Now we just need to check if the result (`temp`) consists *only* of 1s.
    * A number with all 1s (like `11111`) has a special property: `temp & (temp + 1) == 0`.
    * Example: `11111` (31) + 1 = `100000` (32). `31 & 32` is `0`.