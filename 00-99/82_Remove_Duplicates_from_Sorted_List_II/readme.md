# Solution Explanation: Remove All Duplicates (Distinct Values Only)

## 1. The Challenge
Unlike the previous problem (which kept one copy), this version requires us to remove **all** nodes that have duplicate values.
* Input: `1 -> 1 -> 2 -> 3`
* Output: `2 -> 3`

This introduces a specific edge case: **What if the Head itself needs to be deleted?** If `head` is `1`, we cannot simply return `head` because the `1`s must be removed.

## 2. Key Concept: The "Dummy" Node
To solve the edge case where the head might change or be deleted, we create a temporary **Dummy Node** (often with value `0`) that points to the current `head`.
* **Before:** `1 -> 1 -> 2`
* **With Dummy:** `0 -> 1 -> 1 -> 2`

We hold a pointer to `0`. No matter what happens to the `1`s, the `0` remains stable. At the end, we return `dummy->next`.

## 3. Algorithm Logic (Two Pointers)
We use two pointers:
1.  **`prev` (The Anchor):** Points to the last known "safe" node (initially the Dummy).
2.  **`current` (The Scout):** Scans ahead to check for duplicates.

### Steps:
1.  **Initialize:** `prev` = dummy, `current` = head.
2.  **Traverse:** Loop while `current` is valid.
3.  **Check for Duplicates:** Compare `current` with `current->next`.
    * **If Match Found (Duplicate sequence starts):**
        * Enter a sub-loop: Keep moving `current` forward until the value changes (skip all `1`s).
        * **Relink:** Connect `prev->next` to `current->next`. This effectively "snips" out the entire block of duplicates from the chain.
        * *Note:* Do not move `prev` yet! The new neighbor might *also* be a duplicate.
    * **If No Match (Unique Node):**
        * The node is safe. Move `prev` forward to `prev->next`.
4.  **Advance Scout:** Always move `current` forward to continue scanning.
5.  **Return:** `dummy->next`.

## 4. Complexity Analysis

* **Time Complexity:** $O(n)$
    * We traverse the list exactly once. The "scout" pointer visits every node.
* **Space Complexity:** $O(1)$
    * We only create one extra node (the dummy) and two pointers, regardless of list size.