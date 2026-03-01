# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

## Problem Description

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros. For example, `101` and `1100` are deci-binary, while `112` and `3001` are not.

Given a string `n` that represents a positive decimal integer, return the *minimum* number of positive deci-binary numbers needed so that they sum up to `n`.

**Example 1:**
* **Input:** `n = "32"`
* **Output:** `3`
* **Explanation:** `10 + 11 + 11 = 32`

**Example 2:**
* **Input:** `n = "82734"`
* **Output:** `8`

**Example 3:**
* **Input:** `n = "27346209830709182346"`
* **Output:** `9`

---

## Approach: Find the Maximum Digit

The problem asks for the minimum number of deci-binary numbers (numbers made only of `1`s and `0`s) needed to sum to our target string. 


### The Logic (The "Aha!" Moment)
1.  Look at any single digit in the target number. Let's say we have the number `n = "32"`.
2.  The tens place is `3`. To get a `3` by adding only `1`s and `0`s, we absolutely *must* use at least three `1`s in the tens column. 
3.  The ones place is `2`. We need two `1`s in the ones column. 
4.  Because we can freely place a `1` or a `0` in any column of our deci-binary numbers, the column that requires the *most* `1`s dictates how many numbers we need in total.
5.  Therefore, the answer is simply the **maximum digit** present in the string. If the string contains a `'9'`, we need 9 numbers. If the highest digit is `'7'`, we need 7 numbers.