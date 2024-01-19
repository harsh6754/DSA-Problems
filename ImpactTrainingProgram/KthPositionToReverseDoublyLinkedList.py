class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def reverse_doubly_linked_list_up_to_k(head, k):
    if not head or k <= 0:
        return head

    current = head
    count = 1

    while count < k and current.next is not None:
        current = current.next
        count += 1

    temp_head = head
    temp_tail = current
    while temp_head != temp_tail:
        temp_head.data, temp_tail.data = temp_tail.data, temp_head.data
        temp_head = temp_head.next
        temp_tail = temp_tail.prev

    return head

def print_doubly_linked_list(head):
    current = head
    while current is not None:
        print(current.data, end=" <-> ")
        current = current.next
    print("None")


def create_doubly_linked_list():
    elements = input("Enter the elements of the doubly linked list separated by spaces: ").split()
    head = None
    tail = None
    for element in elements:
        new_node = Node(int(element))
        if head is None:
            head = new_node
            tail = head
        else:
            tail.next = new_node
            new_node.prev = tail
            tail = new_node
    return head


k = int(input("Enter the value of k: "))


head = create_doubly_linked_list()


print("\nOriginal Doubly Linked List:")
print_doubly_linked_list(head)


head = reverse_doubly_linked_list_up_to_k(head, k)

print("\nReversed Doubly Linked List (up to {}th index):".format(k))
print_doubly_linked_list(head)
