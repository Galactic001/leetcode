# 657. Robot Return to Origin

## Problem Description

There is a robot starting at the position `(0, 0)`, the origin, on a 2D plane. Given a sequence of its moves, judge if this robot **ends up at `(0, 0)`** after it completes its moves.

You are given a string `moves` that represents the move sequence of the robot where `moves[i]` represents its `i`-th move. Valid moves are `'R'` (right), `'L'` (left), `'U'` (up), and `'D'` (down).

Return `true` if the robot returns to the origin after it finishes all of its moves, or `false` otherwise.

**Note**: The way that the robot is "facing" is irrelevant. `'R'` will always make the robot move to the right once, `'U'` will always make it move up once, etc.

**Example 1:**
* **Input:** `moves = "UD"`
* **Output:** `true`
* **Explanation:** The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started.

**Example 2:**
* **Input:** `moves = "LL"`
* **Output:** `false`
* **Explanation:** The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.

---

## Approach: 2D Coordinate Simulation

To solve this, we can simulate the robot's position on an X-Y coordinate plane. 
* Moving **Up/Down** only affects the **Y-axis**.
* Moving **Left/Right** only affects the **X-axis**.



### The Logic
1.  **Initialize Variables:** Start with two integers, `x = 0` and `y = 0`, representing the robot's starting position at the origin.
2.  **Iterate Through Moves:** Loop through each character in the `moves` string.
    * If the move is `'U'` (Up), increment `y` by 1.
    * If the move is `'D'` (Down), decrement `y` by 1.
    * If the move is `'R'` (Right), increment `x` by 1.
    * If the move is `'L'` (Left), decrement `x` by 1.
3.  **Check Final Position:** For the robot to be back at the origin, the Up/Down moves must have perfectly canceled each other out, and the Left/Right moves must have perfectly canceled each other out. Return `true` if *both* `x == 0` and `y == 0`, otherwise return `false`.