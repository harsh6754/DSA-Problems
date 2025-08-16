#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {};
};

ListNode *buildLists(int n)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *curr = new ListNode(x);
        if (!head)
            head = tail = curr;
        else
        {
            tail->next = curr;
            tail = curr;
        }
    }
    return head;
}

void printlist(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << "->";
        head = head->next;
    }
    cout << "\n";
}

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return nullptr;

    unordered_map<int, int> freq;
    ListNode *curr = head;

    while (curr)
    {
        freq[curr->val]++;
        curr = curr->next;
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;
    curr = head;

    while (curr)
    {
        if (freq[curr->val] == 1)
        {
            tail->next = new ListNode(curr->val);
            tail = tail->next;
        }
        curr = curr->next;
    }
    return dummy.next;
}

int main()
{
    int n;
    cin >> n;

    ListNode *list = buildLists(n);
    printlist(list);

    ListNode* result = deleteDuplicates(list);
    printlist(result);

    return 0;
}