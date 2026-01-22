# Solution Explanation: Merge Two Sorted Lists (LeetCode 21)

## 1. The Strategy: The "Zipper" Approach
Since both input lists are already sorted, we can merge them in a single pass, just like zipping up a jacket.
We look at the "head" (current node) of both lists and pick the smaller one to add to our result.

### Visualization
* **List A:** `[1] -> [2] -> [4]`
* **List B:** `[1] -> [3] -> [4]`
* **Action:**
    1.  Compare `A(1)` vs `B(1)`. Equal? Pick `A`.
    2.  Compare `A(2)` vs `B(1)`. Pick `B`.
    3.  Compare `A(2)` vs `B(3)`. Pick `A`.
    4.  ...and so on.

## 2. Key Concept: The Dummy Node
The code is much cleaner if we create a fake "Dummy" node (`-1`) at the start.
* **Without Dummy:** We have to write an `if` statement just to figure out who the *first* node of the new list is (`list1` or `list2`?).
* **With Dummy:** We always start at `dummy`, attach nodes to it, and finally return `dummy->next`.

## 3. Algorithm Steps
1.  **Initialize:** Create `dummy` and a `tail` pointer pointing to it.
2.  **Loop:** While `list1` AND `list2` are not null:
    * If `list1.val < list2.val`: Attach `list1` to `tail`. Move `list1` forward.
    * Else: Attach `list2` to `tail`. Move `list2` forward.
    * Always move `tail` forward.
3.  **Cleanup:** One list will finish before the other. Simply attach the *entire* remaining chain of the non-empty list to `tail`.
4.  **Return:** `dummy.next`.

## 4. Complexity Analysis

* **Time Complexity:** $O(n + m)$
    * Where $n$ and $m$ are the lengths of the two lists. We process each node exactly once.
* **Space Complexity:** $O(1)$
    * We are only changing pointers. We do not create a new data structure (other than the single dummy node).