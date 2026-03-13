# 191. Number of 1 Bits

## Problem Description

Write a function that takes the binary representation of a positive integer and returns the number of set bits it has (also known as the Hamming weight).

**Example 1:**
* **Input:** `n = 11` (binary `1011`)
* **Output:** `3`
* **Explanation:** The input binary string `1011` has a total of three set bits.

**Example 2:**
* **Input:** `n = 128` (binary `10000000`)
* **Output:** `1`
* **Explanation:** The input binary string `10000000` has a total of one set bit.

**Example 3:**
* **Input:** `n = 2147483645` (binary `11111111111111111111111111111101`)
* **Output:** `31`
* **Explanation:** The input binary string has a total of thirty-one set bits.

---

## Approach 1: Bit Shift and Mask

The most straightforward way to count bits is to check them one by one. 

### The Logic
1.  Initialize a `count` to 0.
2.  Loop while `n > 0`.
3.  Check the least significant bit (rightmost bit) using bitwise AND: `n & 1`. If it's `1`, increment the `count`.
4.  Shift `n` to the right by 1 bit (`n >>= 1`) to position the next bit for evaluation.

### Code (C++)
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1); // Add 1 if the lowest bit is set
            n >>= 1;          // Shift right to check the next bit
        }
        return count;
    }
};
```

## Approach 2: C++ STL `std::bitset`

If you want to leverage the C++ Standard Template Library (STL), you can use the `std::bitset` container. This class is designed specifically to manage fixed-size sequences of bits and provides highly optimized built-in methods for bit manipulation.

### The Logic
1.  **Construct:** Create a `bitset` of size 32 (since the problem specifies a 32-bit unsigned integer) and initialize it with your number `n`.
2.  **Count:** Call the `.count()` method, which simply returns the number of bits that are set to `1`.

### Code (C++)
```cpp
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Convert the integer to a 32-bit bitset and count the 1s
        return bitset<32>(n).count();
    }
};