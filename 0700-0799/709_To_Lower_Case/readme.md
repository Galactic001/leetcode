# 709. To Lower Case

## Problem Description

Given a string `s`, return the string after replacing every uppercase letter with the same lowercase letter.

### Example 1
**Input:** `s = "Hello"`
**Output:** `"hello"`

### Example 2
**Input:** `s = "here"`
**Output:** `"here"`

### Example 3
**Input:** `s = "LOVELY"`
**Output:** `"lovely"`

---

## Approach: ASCII Manipulation

While standard library functions like `tolower()` exist, the purpose of this problem is often to test understanding of character encoding.

### The Logic
1.  **ASCII Values:**
    * Uppercase `A-Z` ranges from **65** to **90**.
    * Lowercase `a-z` ranges from **97** to **122**.
2.  **The Offset:** The difference between a lowercase letter and its uppercase counterpart is exactly **32**.
    * `'a' - 'A' = 32`
3.  **Bitwise Trick:** * 32 in binary is `0010 0000`.
    * Setting the 5th bit (0-indexed) of an uppercase letter converts it to lowercase.
    * This can be done via addition (`c + 32`) or bitwise OR (`c | 32`).

### Complexity
* **Time Complexity:** $O(n)$ — We traverse the string exactly once.
* **Space Complexity:** $O(1)$ — We modify the string in-place (in C++).

---

## Solution (C++)

```cpp
class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            // Check if character is within Uppercase ASCII range (65-90)
            if (c >= 'A' && c <= 'Z') {
                // Add 32 to convert to lowercase
                c += 32;
            }
        }
        return s;
    }
};