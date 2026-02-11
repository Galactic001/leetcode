# Solution Explanation: Missing Number (LeetCode 268)

## 1. The Mathematical Approach (Summation)
We know that the input contains distinct numbers from the range `[0, n]`.
Since one number is missing, the array length is `n`, but the range goes up to `n`.

**Gauss' Formula:**
The sum of a series of numbers from $0$ to $n$ is:
$$\text{Sum} = \frac{n \times (n + 1)}{2}$$

**Logic:**
1.  Calculate what the sum **should be** if every number was present.
2.  Calculate the **actual sum** of the array.
3.  Subtract: `Expected Sum - Actual Sum = Missing Number`.

**Example:** `[3, 0, 1]` ($n=3$)
* Expected Sum ($0+1+2+3$) = $6$.
* Actual Sum ($3+0+1$) = $4$.
* Missing: $6 - 4 = 2$.

## 2. The Hacker's Approach (XOR)
We can use the XOR (`^`) property: $A \oplus A = 0$.
If we XOR all the indices `[0...n]` against all the values in the array `nums`, every number that appears in both lists will cancel out (turn to 0).
The only number that remains is the one that appeared in the index list but **not** in the value list—the missing number.

## 3. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We iterate through the array once to calculate the sum (or XOR).
* **Space Complexity:** $O(1)$
    * We only use a few integer variables to store the sum.