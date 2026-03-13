# 48. Rotate Image

## Problem Description

You are given an $n \times n$ 2D `matrix` representing an image, rotate the image by **90 degrees (clockwise)**.

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:**
* **Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
* **Output:** `[[7,4,1],[8,5,2],[9,6,3]]`

**Example 2:**
* **Input:** `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]`
* **Output:** `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`

---

## Approach: Transpose and Reverse

Rotating a square matrix by 90 degrees clockwise can be broken down into two simpler, standard matrix operations.



### The Logic
1.  **Transpose the Matrix:** * Turn the rows into columns (and vice versa).
    * Mathematically, you swap the element at `matrix[i][j]` with the element at `matrix[j][i]`. 
    * To avoid double-swapping (which would put elements back where they started), you only iterate through the upper triangle of the matrix (where `i < j`).
    * *Example (3x3):*
        ```text
        1 2 3       1 4 7
        4 5 6  -->  2 5 8
        7 8 9       3 6 9
        ```
2.  **Reverse Each Row:**
    * Iterate through each row individually and reverse its elements.
    * You can do this using a two-pointer approach or the built-in `std::reverse` function.
    * *Example (from transposed to final):*
        ```text
        1 4 7       7 4 1
        2 5 8  -->  8 5 2
        3 6 9       9 6 3
        ```