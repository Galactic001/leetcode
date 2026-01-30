# Solution Explanation: Integer to Roman (LeetCode 12)

## 1. The Challenge
We need to convert a number (e.g., `1994`) into Roman numerals (`MCMXCIV`).
Roman numerals are usually additive (`VII` = 5 + 1 + 1 = 7), but sometimes subtractive (`IV` = 5 - 1 = 4).

## 2. Approach: Greedy Algorithm
The most straightforward way to solve this is to always act "Greedily."
* If we have `1994`, we want to get rid of the biggest chunk possible immediately.
* Can we take out `1000` (M)? Yes. Remainder: `994`.
* Can we take out another `1000`? No.
* Can we take out `900` (CM)? Yes. Remainder: `94`.
* ...and so on.

By explicitly defining the "Subtractive Instances" (`CM`, `CD`, `XC`, `XL`, `IX`, `IV`) as their own valid values in our list, we eliminate the need for any complex "look-ahead" logic. We treat `900` just like we treat `1000`—it's just a value we can subtract.


## 3. The Lookup Table
Order is critical. We must check from **Largest** to **Smallest**.

| Value | Symbol |
| :--- | :--- |
| 1000 | M |
| 900 | CM |
| 500 | D |
| 400 | CD |
| 100 | C |
| ... | ... |
| 1 | I |

## 4. Complexity Analysis

* **Time Complexity:** $O(1)$
    * Wait, isn't it dependent on the number? Technically yes, but since the input is limited to 3999, the maximum number of iterations is fixed and small (the longest standard Roman numeral is roughly 15 characters).
* **Space Complexity:** $O(1)$
    * We use a fixed-size table for the mappings.