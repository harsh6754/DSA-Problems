# class node:
#     def _init_(self):
#         self.data = data
#         self.next = 'none'


# class link:
#     def _init_(self):
#         self.head = 'none'

#     def append(self,data):
#         new_node = node(data)
#         if self.head is none:
#             self.head = new_node
#             self.last_node = new_node
#         else:
#             self.last_node.next = new_node
#             self.last_node = new_node
#     def display(self):
#         temp = self.head
#         while temp is not none:
#             print(temp.data)
#             temp = temp.next



# l = link()
# n = int(input("enter no. of elements : "))
# for i in range(n):
#     data = int(input("enter value : "))
#     l.append(data)

# l.display()


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None 

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node 
        else:
            self.tail.next = new_node
            self.tail = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data)
            current = current.next

l = LinkedList()
n = int(input("Enter number of elements: "))
for i in range(n):
    data = int(input("Enter value: "))
    l.append(data)

l.display()
