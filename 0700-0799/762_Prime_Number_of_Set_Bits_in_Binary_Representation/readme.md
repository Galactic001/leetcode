# 762. Prime Number of Set Bits in Binary Representation

## Problem Description

Given two integers `left` and `right`, return the count of numbers in the inclusive range `[left, right]` having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of `1`'s present when written in binary.
* For example, `21` written in binary is `10101`, which has `3` set bits.

**Example 1:**
* **Input:** `left = 6, right = 10`
* **Output:** `4`
* **Explanation:**
  * 6  -> 110 (2 set bits, 2 is prime)
  * 7  -> 111 (3 set bits, 3 is prime)
  * 8  -> 1000 (1 set bit, 1 is not prime)
  * 9  -> 1001 (2 set bits, 2 is prime)
  * 10 -> 1010 (2 set bits, 2 is prime)
  * 4 numbers have a prime number of set bits.

---

## Approach 1: Modular Calculation

This approach iterates through every number in the range, calculates its set bits, and then verifies if that count is a prime number.

### The Logic
1.  **Count Set Bits:** Uses Brian Kernighan's algorithm (`n &= (n - 1)`), which efficiently clears the lowest set bit. The number of times this operation executes is exactly equal to the number of set bits.
2.  **Check Primality:** Uses a standard $O(\sqrt{V})$ loop to check for divisors up to the square root of the number.