# 241. Different Ways to Add Parentheses

## Problem Description

Given a string `expression` of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in **any order**.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed $10^4$.

**Example 1:**
* **Input:** `expression = "2-1-1"`
* **Output:** `[0, 2]`
* **Explanation:**
  * `((2-1)-1) = 0`
  * `(2-(1-1)) = 2`

**Example 2:**
* **Input:** `expression = "2*3-4*5"`
* **Output:** `[-34, -14, -10, -10, 10]`
* **Explanation:**
  * `(2*(3-(4*5))) = -34`
  * `((2*3)-(4*5)) = -14`
  * `((2*(3-4))*5) = -10`
  * `(2*((3-4)*5)) = -10`
  * `(((2*3)-4)*5) = 10`

---

## Approach: Divide and Conquer

Whenever we see an operator in the string (`+`, `-`, or `*`), we can split the string into two parts: a "left" expression and a "right" expression. The core idea is to recursively find all possible evaluations for the left part, all possible evaluations for the right part, and then combine every left result with every right result using that operator.

### The Logic
1.  **Iterate:** Loop through every character in the `expression` string.
2.  **Split on Operators:** If the current character is `+`, `-`, or `*`:
    * Extract the substring to the left of the operator.
    * Extract the substring to the right of the operator.
3.  **Conquer (Recursion):** * Recursively call the function on the left substring to get a list of all its possible integer results.
    * Recursively call the function on the right substring to get a list of all its possible integer results.
4.  **Combine:** For every result in the left list and every result in the right list, perform the current mathematical operation and add the computed value to our final `results` array.
5.  **Base Case:** If the input string has no operators at all, it is just a pure number. We parse it as an integer, put it into a list, and return it.