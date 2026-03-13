# 1545. Find Kth Bit in Nth Binary String

## Problem Description

Given two positive integers `n` and `k`, the binary string `S_n` is formed as follows:
* `S_1 = "0"`
* `S_i = S_{i - 1} + "1" + reverse(invert(S_{i - 1}))` for `i > 1`

Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string `x`, and `invert(x)` inverts all the bits in `x` (0 changes to 1 and 1 changes to 0).

Return the `k`-th bit in `S_n`. It is guaranteed that `k` is valid for the given `n`.

**Example 1:**
* **Input:** `n = 3`, `k = 1`
* **Output:** `"0"`
* **Explanation:** `S_1 = "0"`
  `S_2 = "011"`
  `S_3 = "0111001"`
  The 1st bit is "0".

---

## Approach 1: Iterative Simulation

This approach strictly follows the rules defined in the problem, generating each string sequence up to `n` and then simply picking the `k`-th character. 

### The Logic
1.  Start with `str = "0"`.
2.  Loop `n - 1` times.
3.  In each iteration, create a copy of the current string, reverse it, and invert its bits.
4.  Concatenate the original string, a `"1"`, and the modified copy.
5.  Return the character at index `k - 1`.