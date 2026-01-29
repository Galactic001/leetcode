# Solution Explanation: Truncate Sentence (LeetCode 1816)

## 1. The Logic
We want to keep the first `k` words.
In a sentence, words are separated by spaces.
* `1` space separates `2` words.
* `2` spaces separate `3` words.
* Generally, the boundary after the `k`-th word is simply the **`k`-th space** in the string.

**Example:**
`s = "Hello how are you Contestant", k = 4`

1.  Scan string... found space after "Hello" (`k` becomes 3).
2.  Scan string... found space after "how" (`k` becomes 2).
3.  Scan string... found space after "are" (`k` becomes 1).
4.  Scan string... found space after "you" (`k` becomes 0). -> **STOP!**

Return the substring from index `0` up to the current index.

## 2. Why Manual Scanning?
You might think to use `split()` to chop the sentence into an array of words, pick the first `k`, and `join()` them back.
* **Split approach:** Works well, but creates a new array of strings (extra memory).
* **Scanning approach:** iterating through the string once ($O(N)$) and returning the substring is faster and uses less memory ($O(1)$ extra space).

## 3. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We iterate through the string at most once.
* **Space Complexity:** $O(1)$
    * We don't create any intermediate data structures like arrays or vectors.