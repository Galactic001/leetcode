# 905. Sort Array By Parity

## Problem Description

Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return **any array** that satisfies this condition.

**Example 1:**
* **Input:** `nums = [3,1,2,4]`
* **Output:** `[2,4,3,1]`
* **Explanation:** The outputs `[4,2,3,1]`, `[2,4,1,3]`, and `[4,2,1,3]` would also be accepted.

**Example 2:**
* **Input:** `nums = [0]`
* **Output:** `[0]`

---

## Approach 1: Two-Pass Appending (Extra Space)

This is the most straightforward approach. Since we need evens first and odds second, we can simply scan the array twice and push the elements into a new result array in the correct order.

### The Logic
1.  **First Pass:** Iterate through the original array. If a number is even (`nums[n] % 2 == 0`), push it to the `result` array.
2.  **Second Pass:** Iterate through the original array again. If a number is odd (`nums[n] % 2 != 0`), push it to the `result` array.
3.  **Return:** Return the newly constructed `result` array.

### Code (C++)

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;

        // 1. Push all even numbers first
        for (int n = 0; n < nums.size(); n++) {
            if (nums[n] % 2 == 0) {
                result.push_back(nums[n]);
            }
        }

        // 2. Push all odd numbers next
        for (int n = 0; n < nums.size(); n++) {
            if (nums[n] % 2 != 0) {
                result.push_back(nums[n]);
            }
        }

        return result;
    }
};
```

## Approach 2: Two Pointers (In-Place Optimization)

To optimize the space complexity to $O(1)$, we can modify the array directly. By placing one pointer at the start and one at the end, we can swap elements that are on the "wrong" side without needing to allocate a new array.



### The Logic
1.  **Initialize Pointers:** Set a `left` pointer to `0` and a `right` pointer to the last index of the array (`nums.size() - 1`).
2.  **Check and Swap:** Loop as long as `left < right`:
    * If `nums[left]` is odd AND `nums[right]` is even, they are both on the wrong sides! Swap them using `std::swap`.
    * If `nums[left]` is even, it is already in the correct half of the array. Increment `left` to check the next element.
    * If `nums[right]` is odd, it is already in the correct half of the array. Decrement `right` to check the previous element.
3.  **Return:** Once the pointers meet or cross, the array is successfully partitioned. Return the modified original array.

### Code (C++)

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // If left is odd and right is even, swap them
            if (nums[left] % 2 != 0 && nums[right] % 2 == 0) {
                swap(nums[left], nums[right]);
            }
            
            // If left is even, it's in the right place, move forward
            if (nums[left] % 2 == 0) {
                left++;
            }
            
            // If right is odd, it's in the right place, move backward
            if (nums[right] % 2 != 0) {
                right--;
            }
        }
        
        return nums;
    }
};
```