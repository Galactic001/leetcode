# Solution Explanation: Maximum Product of Two Digits (LeetCode 3536)

## 1. The Goal
We are given a positive integer `n` (e.g., `525`). We need to pick **two** digits from it such that their product is maximized.
* Example `525`: Digits are `5, 2, 5`.
* Pairs: `5*2=10`, `5*5=25`, `2*5=10`.
* Max is **25**.

## 2. Intuition
To get the largest product, we simply need to multiply the **Largest Digit** by the **Second Largest Digit**.
* If `n = 9239`, the digits are `9, 2, 3, 9`.
* Largest is `9`. Second largest is `9`.
* Result: `81`.

## 3. Algorithm: One Pass
We don't need to store all digits or sort them ($O(D \log D)$). We can just iterate through the number once ($O(D)$) and keep track of the top two distinct "seats" for the largest values.

1.  Initialize `max1` and `max2` to -1.
2.  Extract the last digit `d = n % 10`.
3.  **Update Logic:**
    * If `d > max1`: The old king becomes the prince (`max2 = max1`), and `d` becomes the new king (`max1 = d`).
    * Else If `d > max2`: `d` becomes the new prince (`max2 = d`).
4.  Remove the last digit `n /= 10`.
5.  Repeat until `n` is 0.
6.  Return `max1 * max2`.

## 4. Complexity Analysis

* **Time Complexity:** $O(D)$ (where $D$ is the number of digits, i.e., $\log_{10} n$).
    * We visit every digit exactly once.
* **Space Complexity:** $O(1)$
    * We only use two variables to store the maximums.