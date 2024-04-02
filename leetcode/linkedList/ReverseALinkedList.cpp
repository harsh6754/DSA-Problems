#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }

        ListNode *temp = head->next;
        ListNode *temp1 = reverseList(temp);
        ListNode *temp2 = temp1;

        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        temp2->next = head;
        head->next = NULL;

        return temp1;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int val;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        ListNode *newNode = new ListNode(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    Solution solution;
    head = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
