# class node:
#     def _init_(self,data):
#         self.data=data
#         self.next=None

# class link:
#     def _init_(self):
#         self.head=None
        
#     def begin(self,data):
#         new_node=node(data)
#         new_node.next=self.head
#         self.head=new_node

#     def deletebegin(self):
#         if self.head:
#             self.head=self.head.next

#     def deleteend(self):
#         if self.head:
#             temp=self.head
#             pre=0
#             while temp.next:
                
#                 pre=temp
#                 temp=temp.next
#             if pre:
#                 pre.next=None
#             else:
#                 self.head=None
                
#     def appen(self,data):
#         new_node= node(data)
#         if self.head is None:
#             self.head=new_node
#             self.last_node = new_node
#         else:
#             self.last_node.next = new_node
#             self.last_node = new_node
#     def display(self):
#         temp=self.head
#         while temp is not None:
#             print(temp.data)
#             temp=temp.next

        

# l = link()
# n=int(input("Enter no.:"))
# for i in range (n):
#     data=int(input("Enter n.:"))
#     l.appen(data)
# l.display()

# a=int(input("Enter begin:"))
# l.begin(a)
# l.display()

# l.deletebegin()
# l.display()

# l.deleteend()
# l.display()


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

    def delete_begin(self):
        if self.head:
            self.head = self.head.next

    def delete_end(self):
        if self.head:
            temp = self.head
            prev = None
            while temp.next:
                prev = temp
                temp = temp.next
            if prev:
                prev.next = None
            else:
                self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.last_node = new_node
        else:
            self.last_node.next = new_node
            self.last_node = new_node

    def display(self):
        temp = self.head
        while temp:
            print(temp.data)
            temp = temp.next

l = LinkedList()

n = int(input("Enter the number of elements: "))
for i in range(n):
    data = int(input("Enter element {}: ".format(i + 1)))
    l.append(data)

print("Linked List:")
l.display()

a = int(input("Enter element to add at the beginning: "))
l.begin(a)
print("Linked List after adding at the beginning:")
l.display()

l.delete_begin()
print("Linked List after deleting from the beginning:")
l.display()

l.delete_end()
print("Linked List after deleting from the end:")
l.display()
