# Solution Explanation: Longest Common Prefix (LeetCode 14)

## 1. The Challenge
We need to find the string pattern that appears at the **beginning** of every single string in a list.
* Input: `["flower", "flow", "flight"]`
* Output: `"fl"`

## 2. Approach: Sort and Compare ($O(N \cdot \log N)$)
The most efficient way to solve this without checking every single pair is to **Sort** the array first.

### Why Sorting Works?
When strings are sorted alphabetically:
1.  `"flight"`
2.  `"flow"`
3.  `"flower"`

The string that is most different from the first string (`"flight"`) will be the last string (`"flower"`).
* If the **First** and **Last** string share a prefix, then **all** the strings in the middle must share it too.

### Steps
1.  **Sort** the array.
2.  Take `s1 = strs[0]` and `s2 = strs[last]`.
3.  Compare them character by character.
    * `f` == `f` (Match)
    * `l` == `l` (Match)
    * `i` != `o` (Stop!)
4.  Return `"fl"`.

## 3. Alternative Approach: Horizontal Scanning ($O(S)$)
* Take the first string as the "prefix".
* Compare it with the second string, update the prefix to match both.
* Compare the new prefix with the third string, update again.
* Repeat until the end.
* *Note: The Sorting approach is often preferred in interviews because the code is cleaner and handles edge cases (like very short strings) naturally.*

## 4. Complexity Analysis

* **Time Complexity:** $O(N \cdot \log N \cdot M)$
    * Where $N$ is the number of strings and $M$ is the length of the strings. The sorting dominates the complexity.
* **Space Complexity:** $O(1)$
    * We only store a few variables for iteration.