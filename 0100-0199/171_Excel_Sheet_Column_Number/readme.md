# 171. Excel Sheet Column Number

## Problem Description

Given a string `columnTitle` that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:
* A -> 1
* B -> 2
* C -> 3
* ...
* Z -> 26
* AA -> 27
* AB -> 28 
* ...

**Example 1:**
* **Input:** `columnTitle = "A"`
* **Output:** `1`

**Example 2:**
* **Input:** `columnTitle = "AB"`
* **Output:** `28`

**Example 3:**
* **Input:** `columnTitle = "ZY"`
* **Output:** `701`

---

## Approach: Base-26 to Base-10 Conversion

Think about how a standard base-10 number works. The number `135` is calculated as:
`(1 * 10^2) + (3 * 10^1) + (5 * 10^0)`

Or, evaluated sequentially from left to right using a running total:
1. Start with `0`
2. `0 * 10 + 1 = 1`
3. `1 * 10 + 3 = 13`
4. `13 * 10 + 5 = 135`

We can apply this exact same logic to our base-26 string, using `26` as our multiplier instead of `10`.

### The Logic
1.  **Initialize:** Start with a `result` variable set to `0`.
2.  **Iterate:** Loop through each character in the `columnTitle` string from left to right.
3.  **Get the Value:** Convert the current character to its numerical value. Since 'A' is 1, 'B' is 2, etc., we can get this by subtracting the ASCII value of 'A' and adding 1: `(c - 'A' + 1)`.
4.  **Accumulate:** Multiply the current `result` by 26 (to shift the existing values over by one "place") and add the new character's value.
5.  **Return:** Once the loop finishes, `result` holds the final column number.