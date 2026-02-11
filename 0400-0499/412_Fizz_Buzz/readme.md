# Solution Explanation: Fizz Buzz (LeetCode 412)

## 1. The Challenge
We need to generate a list of strings from 1 to `n`.
* If a number is divisible by **3**: Print "Fizz".
* If a number is divisible by **5**: Print "Buzz".
* If a number is divisible by **3 AND 5**: Print "FizzBuzz".
* Otherwise: Print the number itself.

## 2. The Logic: Order Matters
The most common mistake in this problem is checking `i % 3` first.
* If `i = 15`:
    * `15 % 3 == 0` is True. Code prints "Fizz". **WRONG**.
    * It should print "FizzBuzz".

**Correct Order (Your Solution):**
1.  **Check Heaviest Constraint First:** Is it divisible by 15? ( `i % 3 == 0 && i % 5 == 0` )
2.  **Check Smaller Constraints:** Is it divisible by 3?
3.  **Check Smaller Constraints:** Is it divisible by 5?
4.  **Default:** Print the number.



## 3. Alternative Approach: String Concatenation
Instead of using `else if`, we can build the string progressively.
* `string s = ""`
* `if (i % 3 == 0) s += "Fizz"`
* `if (i % 5 == 0) s += "Buzz"`
* `if (s == "") s = to_string(i)`

This avoids the double check for `15`, but your current `if-else` chain is perfectly valid and very readable.

## 4. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We iterate from 1 to `N` exactly once.
* **Space Complexity:** $O(1)$ (ignoring the output vector)
    * We don't use any auxiliary data structures.