# 3751. Total Waviness of Numbers in Range I

## Problem Description

You are given two integers `num1` and `num2` representing an inclusive range `[num1, num2]`.

The **waviness** of a number is defined as the total count of its peaks and valleys:
* A digit is a **peak** if it is strictly greater than both of its immediate neighbors.
* A digit is a **valley** if it is strictly less than both of its immediate neighbors.

The first and last digits of a number cannot be peaks or valleys. Any number with fewer than 3 digits has a waviness of 0.

Return the total sum of waviness for all numbers in the range `[num1, num2]`.

**Example 1:**
* **Input:** `num1 = 120`, `num2 = 130`
* **Output:** `3`
* **Explanation:** * 120: middle digit 2 is a peak, waviness = 1.
  * 121: middle digit 2 is a peak, waviness = 1.
  * 130: middle digit 3 is a peak, waviness = 1.
  * All other numbers have a waviness of 0. 
  * Total = 1 + 1 + 1 = 3.

---

## Approach 1: String Conversion (Intuitive)

The most readable way to process digits is to convert each number into a string and iterate through the characters. We can simply check if the character at index `i` is strictly greater or strictly less than its neighbors at `i-1` and `i+1`.