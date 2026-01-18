# Solution Explanation: Climbing Stairs (LeetCode 70)

## 1. The Pattern (Fibonacci)
The problem asks for the number of distinct ways to reach the top. To understand the pattern, we look at where the last step came from:
* **Option A:** We arrived from **Step `n-1`** by taking a single **1-step**.
* **Option B:** We arrived from **Step `n-2`** by taking a single **2-step**.

Therefore, the set of ways to reach `n` is simply combining the sets of `n-1` and `n-2`.

| Stairs (n) | Combinations | Derivation (Origin) | Total Ways |
| :--- | :--- | :--- | :--- |
| **1** | `[1]` | Base Case | **1** |
| **2** | `[1,1]`<br>`[2]` | Base Case | **2** |
| **3** | `[1,1, 1]`, `[2, 1]`<br>`[1, 2]` | From **n=2** (append 1)<br>From **n=1** (append 2) | **3** |
| **4** | `[1,1,1, 1]`, `[2,1, 1]`, `[1,2, 1]`<br>`[1,1, 2]`, `[2, 2]` | From **n=3** (append 1)<br>From **n=2** (append 2) | **5** |
| **5** | `[1,1,1,1,1]`, `[2,1,1,1]`, `[1,2,1,1]`, `[1,1,2,1]`, `[2,2,1]`<br>`[1,1,1,2]`, `[2,1,2]`, `[1,2,2]` | From **n=4** (append 1)<br>From **n=3** (append 2) | **8** |



## 2. Approach: Dynamic Programming (Space Optimized)
Since `Ways(n)` only depends on `Ways(n-1)` and `Ways(n-2)`, we don't need to store the entire history (like an array). We only need to remember the **last two** counts.

* `prev2` stores `Ways(i-2)`
* `prev1` stores `Ways(i-1)`
* `current` becomes `prev1 + prev2`

## 3. Complexity Analysis

* **Time Complexity:** $O(n)$
    * We iterate from 1 to `n` exactly once.
* **Space Complexity:** $O(1)$
    * We only store 3 integer variables (`prev1`, `prev2`, `current`) regardless of how many stairs there are.