# Solution Explanation: Balanced Binary Tree (LeetCode 110)

## 1. The Concept: Bottom-Up Recursion
To check if a tree is balanced, we need to know the height of the left subtree and the right subtree for *every single node*.

A naive approach would be to write a `height()` function and call it for every node. However, calculating height is $O(N)$, and doing it for $N$ nodes results in $O(N^2)$ complexity.

**Better Approach (Bottom-Up DFS):**
We can compute the height and check for balance in the **same pass**.
* As we return from the recursion (moving up from leaves to root), we pass the height of the current subtree.
* If we detect an imbalance at any point (i.e., `|left - right| > 1`), we return a special error code (like `-1`) that propagates all the way to the top.



## 2. Algorithm Steps
1.  **Base Case:** If node is `null`, height is `0`.
2.  **Recursive Step (Left):** Get height of left child. If it returns `-1`, immediately return `-1` (fail fast).
3.  **Recursive Step (Right):** Get height of right child. If it returns `-1`, immediately return `-1` (fail fast).
4.  **Check Balance:** If `abs(leftHeight - rightHeight) > 1`, return `-1`.
5.  **Return Height:** If balanced, return `max(left, right) + 1`.

## 3. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We visit every node exactly once using Post-Order Traversal.
* **Space Complexity:** $O(H)$
    * $H$ is the height of the tree. This is the stack space used by recursion. In the worst case (skewed tree), it is $O(N)$. In a balanced tree, it is $O(\log N)$.