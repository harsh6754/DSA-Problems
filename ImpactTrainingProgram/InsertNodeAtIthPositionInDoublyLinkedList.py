class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def insert_node_at_ith_position(head, i, value):
    new_node = Node(value)

    if i == 0:
       
        new_node.next = head
        if head:
            head.prev = new_node
        return new_node
    else:
        current = head
        count = 0

        
        while count < i - 1 and current.next is not None:
            current = current.next
            count += 1

    
        new_node.next = current.next
        new_node.prev = current
        if current.next:
            current.next.prev = new_node
        current.next = new_node

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


i = int(input("Enter the position (i) to insert the node: "))
value = int(input("Enter the value to insert: "))


head = create_doubly_linked_list()


print("\nOriginal Doubly Linked List:")
print_doubly_linked_list(head)

head = insert_node_at_ith_position(head, i, value)


print("\nDoubly Linked List after inserting at position {}:".format(i))
print_doubly_linked_list(head)
