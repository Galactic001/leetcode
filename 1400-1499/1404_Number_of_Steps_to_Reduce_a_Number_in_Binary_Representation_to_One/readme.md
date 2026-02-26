# 1404. Number of Steps to Reduce a Number in Binary Representation to One

## Problem Description

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

* If the current number is even, you have to divide it by `2`.
* If the current number is odd, you have to add `1` to it.

It is guaranteed that you can always reach one for all valid input strings.

**Example 1:**
* **Input:** `s = "1101"`
* **Output:** `6`
* **Explanation:** "1101" corresponds to number 13 in decimal.
    1.  13 is odd, add 1 -> 14 (binary "1110")
    2.  14 is even, divide by 2 -> 7 (binary "111")
    3.  7 is odd, add 1 -> 8 (binary "1000")
    4.  8 is even, divide by 2 -> 4 (binary "100")
    5.  4 is even, divide by 2 -> 2 (binary "10")
    6.  2 is even, divide by 2 -> 1 (binary "1")

**Example 2:**
* **Input:** `s = "10"`
* **Output:** `1`
* **Explanation:** "10" is 2 in decimal. 2 is even, divide by 2 -> 1.

---

## Approach: Right-to-Left Traversal with Carry

Instead of simulating the actual string modifications (which would take $O(N^2)$ time due to string shifting/insertions), we can simulate the mathematical process by reading the bits from right to left (Least Significant Bit to Most Significant Bit) and maintaining a `carry` variable.



### The Logic
1.  **Iterate Backwards:** Start from the last character (`s.length() - 1`) and go down to `1`. We stop at `1` because the first character `s[0]` is always `'1'` (no leading zeros), and we handle it at the very end.
2.  **Evaluate Current Bit:** For each bit, its actual value is `(s[i] - '0') + carry`.
    * **Case 1: Value is 1 (Odd Number)**
        * We must add 1 (which turns the bit into a 0 and generates a carry of 1) and *then* divide by 2 (which is 1 shift step). 
        * This requires **2 steps**. We update `carry = 1`.
    * **Case 2: Value is 0 or 2 (Even Number)**
        * If the value is `0` (was 0, no carry), it's even. We divide by 2 (1 shift step). Carry remains `0`.
        * If the value is `2` (was 1, plus a carry of 1), it effectively becomes a `0` with a carry passed to the next bit. We divide by 2 (1 shift step). Carry remains `1`.
        * In both even scenarios, it takes exactly **1 step**, and the `carry` remains unchanged.
3.  **Final Bit:** After the loop, if we have a leftover `carry` of `1`, it means our most significant bit (`'1'`) became `'2'` (effectively `10` in binary). This requires exactly **1 more step** to divide by 2.