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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr) return head;

        ListNode *current = head;

        while (current->next != nullptr)
        {

            if (current->val == current->next->val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};

// Helper function to print Linked List
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int num;
    cout << "Enter number of nodes: ";
    if (!(cin >> num))
        return 0;

    if (num == 0)
    {
        // Handle empty list case
        Solution ob;
        ListNode *head = nullptr;
        head = ob.deleteDuplicates(head);
        printList(head);
        return 0;
    }

    int val;
    cout << "Enter values (sorted): ";
    cin >> val;

    // Create the head of the list
    ListNode *head = new ListNode(val);
    ListNode *tail = head;

    // Create the rest of the nodes
    for (int i = 1; i < num; ++i)
    {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    Solution ob;
    head = ob.deleteDuplicates(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}