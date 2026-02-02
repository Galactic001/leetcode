# Solution Explanation: Divide Array Into Subarrays With Minimum Cost II (LeetCode 3013)

## 1. The difference from "Minimum Cost I"
In the easy version (Q3010), we just picked the 2 smallest numbers from the *entire* array.
In this hard version, we have a constraint: **`dist`**.

* We must choose `k-1` additional numbers to start new subarrays.
* The index difference between the first chosen number and the last chosen number must be $\le dist$.
* **Translation:** We need to find a window of size `dist + 1` somewhere in the array where the **sum of the smallest `k-1` numbers** is minimized.

## 2. The Strategy: Sliding Window with Two Sets
We cannot simply re-sort the window every time we move it (that would be too slow, $O(N \cdot K \log K)$). instead, we use a smart data structure to maintain the "Top `k-1` Smallest" dynamically.

We maintain two `multisets` (Sorted Lists):
1.  **Set L (The "Active" Team):** Contains the **smallest `k-1`** numbers in the current window. We track the sum of these.
2.  **Set R (The "Reserve" Team):** Contains all other numbers in the current window that are too big to be in the top `k-1`.

[Image of sliding window with two sets logic]

## 3. The Algorithm Steps
As we slide the window one step to the right:

1.  **Remove Old