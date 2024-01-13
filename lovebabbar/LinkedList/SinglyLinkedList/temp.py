class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.last_node = None

    def begin(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delbegin(self):
        if self.head:
            self.head = self.head.next

    def delend(self):
        if self.head:
            temp = self.head
            prev = None
            while temp.next:
                prev = temp
                temp = temp.next
            if prev:
                prev.next = None
                self.last_node = prev  # Update the last_node when deleting from the end
            else:
                self.head = None
                self.last_node = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.last_node = new_node
        else:
            self.last_node.next = new_node
            self.last_node = new_node

    def position(self, data, index):
        new_node = Node(data)
        cur_node = self.head
        pos = 0

        if pos == index:
            self.begin(data)
        else:
            while cur_node is not None and pos + 1 != index:
                pos += 1
                cur_node = cur_node.next
            if cur_node is not None:
                new_node.next = cur_node.next
                cur_node.next = new_node
            else:
                print("Invalid index")

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()


l = LinkedList()
n = 5
for i in range(n):
    data = int(input("Enter value: "))
    l.append(data)

print("Linked List:")
l.display()

b = 10
l.begin(b)
print("Linked List after inserting at the beginning:")
l.display()

print("After deleting the first element:")
l.delbegin()
l.display()

print("After deleting the last element:")
l.delend()
l.display()

pos_data = 45
pos_index = int(input("Enter the position to insert at: "))
l.position(pos_data, pos_index)
print("After inserting at position:")
l.display()
