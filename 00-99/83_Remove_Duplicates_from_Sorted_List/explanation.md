# Solution Explanation: Remove Duplicates from Sorted List

## 1. Algorithm Logic
The problem asks us to delete duplicates from a **sorted** linked list. Since the list is sorted, all duplicate values are grouped together (consecutive).

We traverse the list using a single pointer (`current`) and compare values of adjacent nodes.

### Steps:
1.  **Edge Case:** If `head` is `nullptr`, return immediately.
2.  **Initialize:** Create a pointer `current` pointing to `head`.
3.  **Traverse:** Loop while `current` and `current->next` are valid.
4.  **Compare:** Check if `current->val == current->next->val`.
    * **If Match (Duplicate Found):**
        * Modify the `next` pointer of `current` to skip the immediate next node.
        * Logic: `current->next = current->next->next;`
        * *Note:* We do **not** advance `current` here because the new next node might also be a duplicate.
    * **If No Match:**
        * Advance the iterator normally.
        * Logic: `current = current->next;`
5.  **Return:** Return the original `head` pointer.

## 2. Why modifying 'current' changes 'head'
This relies on the distinction between **stack variables** and **heap memory**.

* **`head` and `current` (Stack Pointers):** These are local variables storing memory addresses.
* **`ListNode` objects (Heap Memory):** The actual nodes exist in the heap. Both `head` and `current` point to this same shared structure.

### The Mechanism
1.  **`current = current->next`**:
    * This modifies the **local pointer variable**. It changes *where* `current` is looking. It does **not** alter the list structure.
2.  **`current->next = ...`**:
    * This dereferences the pointer to access the **actual object** in memory.
    * It mutates the `next` field of the node.
    * Since `head` points to the start of this chain, any structural change made via `current` is visible when traversing from `head`.

## 3. Complexity Analysis

* **Time Complexity:** $O(n)$
    * We traverse the linked list exactly once.
* **Space Complexity:** $O(1)$
    * We operate in-place and only use a single iterator pointer.