# Solution Explanation: Single Number (LeetCode 136)

## 1. The Challenge
We are given an array where **every element appears twice**, except for **one** element which appears only once.
* Constraints: We must solve it in **Linear Time $O(N)$** and use **Constant Space $O(1)$**.

## 2. Naive Approaches (Too much memory)
* **HashSet:** Add numbers to a set. If it's already there, remove it. The one left remaining is the answer.
    * *Problem:* Uses $O(N)$ space.
* **Sorting:** Sort the array and check if `nums[i] == nums[i+1]`.
    * *Problem:* Uses $O(N \log N)$ time.

## 3. Optimal Approach: Bitwise XOR
We use the unique properties of the XOR (`^`) operation to make the duplicates destroy each other.

### XOR Rules
1.  **Identity:** $a \oplus 0 = a$
2.  **Self-Inverse:** $a \oplus a = 0$ (This is the magic!)
3.  **Commutative:** $a \oplus b \oplus c = a \oplus c \oplus b$

### Walkthrough
Input: `[4, 1, 2, 1, 2]`

Initialize `result = 0`.
1.  `0 ^ 4` -> `4`
2.  `4 ^ 1` -> `5` (binary `100 ^ 001 = 101`)
3.  `5 ^ 2` -> `7`
4.  `7 ^ 1` -> `6` (Notice: this cancels out the previous `1`)
5.  `6 ^ 2` -> `4` (Notice: this cancels out the previous `2`)

Mathematically: `4 ^ (1 ^ 1) ^ (2 ^ 2)  =>  4 ^ 0 ^ 0  =>  4`.

## 4. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We iterate through the array exactly once.
* **Space Complexity:** $O(1)$
    * We only use a single integer variable `result`.