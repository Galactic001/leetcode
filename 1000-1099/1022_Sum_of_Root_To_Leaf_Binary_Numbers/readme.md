# 1022. Sum of Root To Leaf Binary Numbers

## Problem Description

You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the most significant bit.

* For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

**Example 1:**

* **Input:** `root = [1,0,1,0,1,0,1]`
* **Output:** `22`
* **Explanation:** (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

---

## Approach: Depth-First Search (Preorder Traversal)

We can traverse the tree from root to leaf, passing the accumulated value down to the children. 

### The Logic
1.  **Bitwise Shift:** Every time we move down a level in the tree, we shift our current accumulated number to the left by 1 bit (which is equivalent to multiplying by 2) and add the current node's value. 
    * *Example:* If we have `1` and move down to a `0`, we do `(1 << 1) | 0` which equals `2` (binary `10`).
2.  **Base Case:** If the current node is `nullptr`, return `0`.
3.  **Leaf Check:** If a node has no left or right children, it's a leaf. Return the calculated path value.
4.  **Recursive Step:** If it's not a leaf, recursively call the DFS function on both the left and right children and return their sum.

---