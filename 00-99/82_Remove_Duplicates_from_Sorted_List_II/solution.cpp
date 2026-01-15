#include <bits/stdc++.h>

using namespace std;

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
        if (!head || !head->next) return head;

        // In case actual head needs to be deleted
        ListNode *dummy = new ListNode(0, head);

        ListNode *prev = dummy;
        ListNode *current = head;

        while (current != nullptr)
        {
            if (current->next != nullptr && current->val == current->next->val)
            {
                // Loop while next value is same
                while (current->next != nullptr && current->val == current->next->val) 
                {
                    current = current->next;
                }

                // change prev to skip all duplicates
                prev->next = current->next;
            }
            else 
            {
                prev = prev->next;
            }

            current = current->next;
        }

        return dummy->next; // new head (skipping the dummy)
    }
};

// helper function to print Linked List
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
        // handle empty list case
        Solution sol;
        ListNode *head = nullptr;
        head = sol.deleteDuplicates(head);
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

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}