#include <iostream>

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 1. Create a "Dummy" node to act as the start of our new list.
        // This saves us from writing edge cases for the very first node.
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        // 2. Iterate while BOTH lists have data
        while (list1 != nullptr && list2 != nullptr)
        {
            // Compare values and pick the smaller one
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            // Move our tail pointer forward
            tail = tail->next;
        }

        // 3. One list will be empty, the other might still have nodes.
        // Attach the remaining part of the non-empty list.
        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy->next;
    }
};

// Helper to create a list from user input
ListNode *createList(int n)
{
    if (n == 0)
        return nullptr;
    int val;
    cout << "Enter values (sorted): ";
    cin >> val;
    ListNode *head = new ListNode(val);
    ListNode *tail = head;
    for (int i = 1; i < n; ++i)
    {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n1, n2;

    cout << "--- List 1 ---" << endl;
    cout << "Number of nodes: ";
    cin >> n1;
    ListNode *list1 = createList(n1);

    cout << "--- List 2 ---" << endl;
    cout << "Number of nodes: ";
    cin >> n2;
    ListNode *list2 = createList(n2);

    Solution sol;
    ListNode *mergedHead = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}