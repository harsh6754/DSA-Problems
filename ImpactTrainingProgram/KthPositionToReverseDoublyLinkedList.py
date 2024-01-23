class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def reverse_k_group(head, k):
    if not head or k == 0 or k == 1:
        return head

    # Function to get the length of the linked list
    def get_length(node):
        length = 0
        while node:
            length += 1
            node = node.next
        return length

    # Function to reverse a linked list within the given range
    def reverse_in_range(start, end):
        prev, current = None, start
        while current and current != end:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev

    length = get_length(head)
    dummy = ListNode(0)
    dummy.next = head
    prev_group_end = dummy

    for _ in range(length // k):
        group_start = prev_group_end.next
        group_end = group_start

        for _ in range(k - 1):
            group_end = group_end.next

        next_group_start = group_end.next
        group_end.next = None

        prev_group_end.next = reverse_in_range(group_start, next_group_start)
        group_start.next = next_group_start

        prev_group_end = group_start

    return dummy.next

# Function to print the linked list
def print_linked_list(head):
    while head:
        print(head.value, end=" ")
        head = head.next
    print()

# Input the linked list
elements = list(map(int, input().split()))
k = int(input())

# Create the linked list from input
head = ListNode(elements[0])
current = head
for value in elements[1:]:
    if value == -1:
        break
    current.next = ListNode(value)
    current = current.next

# Reverse the linked list in groups of size 'k'
head = reverse_k_group(head, k)

# Print the modified linked list
print_linked_list(head)
