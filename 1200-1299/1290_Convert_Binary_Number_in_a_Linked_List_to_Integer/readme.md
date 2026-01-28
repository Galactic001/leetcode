# Solution Explanation: Convert Binary Linked List to Integer (LeetCode 1290)

## 1. The Concept (Bitwise Accumulation)
We need to traverse the linked list from **most significant bit** (head) to **least significant bit** (tail). This is the exact opposite of how we usually do math by hand (right to left), but it's actually easier for code.

### Logic
Imagine the number is binary `101` (decimal 5).
1.  **Start:** `sum = 0`
2.  **Read '1':** `sum` becomes `0 * 2 + 1 = 1`
3.  **Read '0':** `sum` shifts left (doubles). `1 * 2 + 0 = 2`
4.  **Read '1':** `sum` shifts left (doubles). `2 * 2 + 1 = 5`

**Formula:** `current_total = (previous_total * 2) + current_node_val`

## 2. Approach: Iteration
We traverse the linked list once. At every step, we "make room" for the new bit by shifting the existing number to the left (multiplying by 2).

* **Bitwise Alternative:** instead of `num * 2 + val`, you can use `(num << 1) | val`. It does the exact same thing but operates directly on bits.

## 3. Complexity Analysis

* **Time Complexity:** $O(N)$
    * We visit each node exactly once.
* **Space Complexity:** $O(1)$
    * We only use a single integer variable to store the result.