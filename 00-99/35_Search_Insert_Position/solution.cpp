#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
                cout << "left: " << left;
            } else
            {
                right = mid - 1;
                cout << "right: " << right;
            }
        }

        return left;

    }
};

int main()
{
    int target;
    cout << "Enter target value";
    cin >> target;

    int n, num;
    vector<int> nums;

    cout << "Enter size of array: ";
    if (!(cin >> n))
        return 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;
    int val = solution.searchInsert(nums, target);
    cout << "Final Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Output: " + val;

    return 0;
}