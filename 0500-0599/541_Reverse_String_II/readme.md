# Solution Explanation: Reverse String II (LeetCode 541)

## 1. The Logic
The problem asks us to reverse the first `k` characters for every `2k` characters. 
* **Range [0 to k]:** Reverse
* **Range [k to 2k]:** Skip
* **Range [2k to 3k]:** Reverse
* **Range [3k to 4k]:** Skip
* ... and so on.

The easiest way to implement this is to write a loop that increments by `2 * k` in every step. Inside that loop, we simply reverse the next `k` characters.

## 2. Handling Edge Cases
The problem states:
1.  If fewer than `k` characters match, reverse them all.
2.  If less than `2k` but greater than `k` remain, reverse the first `k` and leave the rest.

We handle both cases automatically using the `min` function:
`End Index = min(CurrentIndex + k, StringLength)`

* If `CurrentIndex + k` is smaller than the length, we swap `k` items.
* If `CurrentIndex + k` is larger (overflow), `min` selects `StringLength`, so we only swap what is left.

## 3. Complexity Analysis

* **Time Complexity:** $O(n)$
    * We iterate through the string once. Reversing a segment is linear time, and the segments do not overlap.
* **Space Complexity:** * **C++:** $O(1)$ (In-place mutation).
    * **C#:** $O(n)$ (Because strings are immutable, we must create a character array).