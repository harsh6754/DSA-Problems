
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void deleteNode(struct Node **head_ref, struct Node *del)
{

    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void removeDuplicates(struct Node **head_ref)
{

    if ((*head_ref) == NULL ||
        (*head_ref)->next == NULL)
        return;

    struct Node *ptr1, *ptr2;

    for (ptr1 = *head_ref; ptr1 != NULL; ptr1 = ptr1->next)
    {
        ptr2 = ptr1->next;

        while (ptr2 != NULL)
        {

            if (ptr1->data == ptr2->data)
            {

                struct Node *next = ptr2->next;

                deleteNode(head_ref, ptr2);

                ptr2 = next;
            }

            else
                ptr2 = ptr2->next;
        }
    }
}

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node *head)
{

    if (head == NULL)
        cout << "Doubly Linked list empty";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct Node *head = NULL;

    push(&head, 12);
    push(&head, 12);
    push(&head, 10);
    push(&head, 4);
    push(&head, 8);
    push(&head, 4);
    push(&head, 6);
    push(&head, 4);
    push(&head, 4);
    push(&head, 8);

    cout << "Original Doubly linked list:\n";
    printList(head);

    removeDuplicates(&head);

    cout << "\nDoubly linked list after "
            "removing duplicates:\n";
    printList(head);

    return 0;
}
