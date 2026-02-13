# 771. Jewels and Stones

## Problem Description

You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

**Example:**
* **Input:** `jewels = "aA"`, `stones = "aAAbbbb"`
* **Output:** `3`

---

## Approach 1: Brute Force (Nested Loops)

This approach iterates through every single stone and compares it against every single jewel character.

### Logic
1.  Initialize a counter to 0.
2.  Loop through each character `s` in the `stones` string.
3.  Inside that loop, loop through each character `j` in the `jewels` string.
4.  If `s == j`, increment the counter.

### Code (C++)

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        // Outer loop: Iterate through every stone
        for (char c : stones) {
            // Inner loop: Check against every jewel
            for (char j : jewels) {
                if (j == c) {
                    count++;
                    // Note: If jewels contained duplicates, we should break here to avoid double counting.
                    // However, LeetCode guarantees unique characters in 'jewels'.
                }
            }
        }
        return count;
    }
};
```

## Approach 2: Optimized (Hash Set)

This approach trades a small amount of memory for significantly faster speed by using a Hash Set for $O(1)$ lookups.

### Logic
1.  **Pre-process:** Insert all characters from `jewels` into an `unordered_set`. This takes $O(m)$ time, where $m$ is the length of `jewels`.
2.  **Iterate:** Loop through `stones` exactly once.
3.  **Lookup:** For each stone, check if it exists in the set. This lookup takes $O(1)$ time on average.

### Code (C++)

```cpp
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // Pre-process jewels into a Hash Set for instant lookup
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());

        int count = 0;
        // Iterate through stones only once
        for (char s : stones) {
            // Check if stone exists in the set (O(1) average time)
            if (jewelSet.count(s)) {
                count++;
            }
        }
        return count;
    }
};
```

## Comparison Summary

| Feature | Brute Force (Nested Loop) | Optimized (Hash Set) |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n \times m)$ | $O(n + m)$ |
| **Space Complexity** | $O(1)$ | $O(m)$ |
| **Explanation** | For every stone, we scan the entire jewels list. If `stones` has 1000 chars and `jewels` has 50, that's 50,000 checks. | We scan `jewels` once to build a map, then scan `stones` once. That's only 1,050 checks for the same input. |
| **Best Used When** | Memory is extremely tight (e.g., embedded systems) or inputs are guaranteed to be very small. | Speed is the priority and standard memory is available (most software scenarios). |