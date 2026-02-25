# 1356. Sort Integers by The Number of 1 Bits

## Problem Description

You are given an integer array `arr`. Sort the integers in the array in ascending order by the number of `1`'s in their binary representation. In case two or more integers have the same number of `1`'s, you have to sort them in ascending order of their actual numerical value.

Return the sorted array.

**Example 1:**
* **Input:** `arr = [0,1,2,3,4,5,6,7,8]`
* **Output:** `[0,1,2,4,8,3,5,6,7]`
* **Explanation:** * 0 -> 0 (0 bits)
    * 1 -> 1 (1 bit)
    * 2 -> 10 (1 bit)
    * 4 -> 100 (1 bit)
    * 8 -> 1000 (1 bit)
    * 3 -> 11 (2 bits)
    * 5 -> 101 (2 bits)
    * 6 -> 110 (2 bits)
    * 7 -> 111 (3 bits)
    * Grouped by bits and then sorted by value: `[0, 1, 2, 4, 8, 3, 5, 6, 7]`

---

## Approach: Custom Comparator & Built-in Popcount

To solve this, we can use the standard `std::sort` function in C++, but we need to provide it with custom logic on *how* to compare two numbers.



### The Logic
1.  **Count the Bits:** For any two numbers `a` and `b`, we first need to know how many set bits (1s) they have. We can use the highly optimized GCC built-in function `__builtin_popcount(n)` which we used in problem 762.
2.  **Define the Sorting Rules:**
    * **Rule 1:** If the number of bits in `a` is different from `b`, the one with fewer bits comes first (`countA < countB`).
    * **Rule 2:** If the number of bits is exactly the same, the smaller actual number comes first (`a < b`).
3.  **Apply via Lambda:** We can pass this logic directly into `std::sort` using a lambda function.

---