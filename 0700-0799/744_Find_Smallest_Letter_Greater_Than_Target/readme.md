# Solution Explanation: Find Smallest Letter Greater Than Target (LeetCode 744)

## 1. The Goal
We need to find the smallest character in the array that is **strictly larger** than the `target`.
* If the array is `['a', 'b']` and target is `'z'`, there is no letter larger than 'z'.
* **Wrap Around Rule:** If no letter is larger, return the **first** letter (`'a'`).

## 2. Approach: Binary Search ($O(\log N)$)
Since the array is **sorted**, we should not scan it linearly ($O(N)$). We use Binary Search.

We are looking for the "Upper Bound":
* If `letters[mid] > target`: This is a possible answer. But maybe there is a smaller valid answer to the left? Move `right` to `mid - 1`.
* If `letters[mid] <= target`: This is useless. We need something bigger. Move `left` to `mid + 1`.

## 3. The Wrap-Around Trick
At the end of the loop, the `left` pointer will be exactly at the index of the answer.
However, if `target` was larger than everything in the list, `left` will equal `letters.size()`.

Instead of writing an `if` statement:
```cpp
if (left == letters.size()) return letters[0];
return letters[left];