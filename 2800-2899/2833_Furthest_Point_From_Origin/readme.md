# 2833. Furthest Point From Origin

## Problem Description

You are given a string `moves` of length `n` consisting only of characters `'L'`, `'R'`, and `'_'`. The string represents your movement on a number line starting from the origin `0`.

* `'L'` means you move to the left by 1 step.
* `'R'` means you move to the right by 1 step.
* `'_'` means you can choose to move to the **left** or to the **right** by 1 step.

Return the **distance from the origin** of the furthest point you can reach after `n` moves.

**Example 1:**
* **Input:** `moves = "L_RL__R"`
* **Output:** `3`
* **Explanation:** The furthest point we can reach from the origin `0` is index `-3` through the moves `"LLRLLLR"`. The distance is `3`.

**Example 2:**
* **Input:** `moves = "_R__LL_"`
* **Output:** `5`
* **Explanation:** The furthest point we can reach from the origin `0` is index `-5` through the moves `"LLLLLLL"`. The distance is `5`.

**Example 3:**
* **Input:** `moves = "_______"`
* **Output:** `7`
* **Explanation:** The furthest point we can reach from the origin `0` is index `7` through the moves `"RRRRRRR"`. The distance is `7`.

---

## Approach: Greedy Counting

To maximize our distance from the origin, we want to travel as far as possible in a single direction. The underscores (`'_'`) represent free choices. 

To get the furthest point, we should look at our required moves (`'L'` and `'R'`) and see which direction they are naturally pulling us. Once we know our "dominant" direction, we can greedily convert every single `'_'` into a move in that dominant direction.

### The Logic
1.  **Count the Moves:** Iterate through the string and count exactly how many `'L'`s, `'R'`s, and `'_'`s there are.
2.  **Find the Baseline Distance:** The fixed distance we travel is simply the difference between the left and right moves. Since distance is always positive, we take the absolute value: `abs(L_count - R_count)`.
3.  **Maximize with Wildcards:** Since we want to go as far as possible, we take all of our wildcard `'_'` moves and add them directly to our baseline distance.

**Formula:** `Total Distance = abs(L_count - R_count) + wildcards`