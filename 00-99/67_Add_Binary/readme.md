# Solution Explanation: Add Binary (LeetCode 67)

## 1. The Challenge
We cannot simply convert the strings to Integers (`int` or `long`), add them, and convert back.
**Why?** The strings can be very long (e.g., 100 bits). A standard 64-bit integer can only hold values up to $\approx 1.8 \times 10^{19}$, which is not enough. We must perform the addition manually, bit by bit.

## 2. Algorithm: "Schoolbook Addition"
We process the strings from the end (Least Significant Bit) to the start (Most Significant Bit), just like adding numbers on paper.

### Variables
* `i`, `j`: Pointers to the current digit in string `a` and `b`.
* `carry`: Holds the overflow from the previous addition (0 or 1).

### Logic per position
At any position, the `sum` is: `digitA + digitB + previousCarry`.
Possible sums:
* **0:** (0+0+0) $\rightarrow$ Write **0**, Carry **0**.
* **1:** (1+0+0) $\rightarrow$ Write **1**, Carry **0**.
* **2:** (1+1+0) $\rightarrow$ Write **0**, Carry **1** (Because $2_{10} = 10_2$).
* **3:** (1+1+1) $\rightarrow$ Write **1**, Carry **1** (Because $3_{10} = 11_2$).

### Formula
* Current Digit to Append: `sum % 2`
* New Carry: `sum / 2`

## 3. Complexity Analysis

* **Time Complexity:** $O(\max(N, M))$
    * Where $N$ and $M$ are the lengths of the strings. We iterate once through the longer string.
* **Space Complexity:** $O(\max(N, M))$
    * To store the result string.