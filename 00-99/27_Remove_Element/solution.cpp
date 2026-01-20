#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // "Writer" pointer: keeps track of the position for the next valid element
        int writer = 0; 

        // "Reader" loop: scans every element
        for (int i = 0; i < nums.size(); i++) {
            // If the current number is NOT the one we want to remove...
            if (nums[i] != val) {
                // ...write it down at the "writer" position
                nums[writer] = nums[i];
                writer++;
            }
            // If it IS the value, we just ignore it (do nothing), effectively deleting it
        }

        // 'writer' is now the count of valid elements
        return writer;
    }
};

int main()
{
    int val, n, input;
    vector<int> nums;

    cout << "Enter value to remove: ";
    cin >> val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    int k = solution.removeElement(nums, val);

    cout << "New Length: " << k << endl;
    cout << "Modified Array: ";
    // Only print up to 'k', because the leftover data at the end doesn't matter
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}