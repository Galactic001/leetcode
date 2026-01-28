#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int result = 0;

        while (head != nullptr)
        {
            // Method 1: Arithmetic way
            // Shift current value to the left (multiply by 2) and add new bit
            result = result * 2 + head->val;

            // Method 2: Bitwise way (Same thing, slightly faster on some CPUs)
            // result = (result << 1) | head->val;

            head = head->next;
        }

        return result;
    }
};

// Helper to create list
void createList(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        head = new ListNode(val);
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = new ListNode(val);
}

int main()
{
    int n, val;
    ListNode *head = nullptr;

    cout << "Enter number of bits (nodes): ";
    if (!(cin >> n))
        return 0;

    cout << "Enter bits (0 or 1): ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        createList(head, val);
    }

    Solution sol;
    cout << "Decimal Value: " << sol.getDecimalValue(head) << endl;

    return 0;
}