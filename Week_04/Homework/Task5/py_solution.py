class Node:
    def __init__(self, data=0, next_=None, prev=None):
        self.data = data
        self.next_ = next_
        self.prev = prev


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

        self.middle_node = None
        self.size = 0

    def push_back(self, data):
        self.size += 1
        new_node = Node(data)

        if not self.head:
            self.middle_node = self.head = self.tail = new_node
        else:
            self.tail.next_ = new_node
            new_node.prev = self.tail
            self.tail = new_node

        if self.size % 2 == 0:
            self.middle_node = self.middle_node.next_

    def pop_back(self):
        self.size -= 1

        if self.head == self.tail:
            self.middle_node = self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next_ = None

        if self.size % 2 == 1:
            self.middle_node = self.middle_node.prev

    def print(self):
        current = self.head

        while current:
            print(current.data, end=" ")
            current = current.next_

        print()

    def move_sequence(self):
        if self.size <= 1:
            return

        new_middle_node = self.head if self.size % 2 == 0 else self.tail

        # Connecting the list
        self.tail.next_ = self.head
        self.head.prev = self.tail

        # Setting the new head and tail
        self.tail = self.middle_node.prev
        self.head = self.middle_node

        # Disconnecting the loop
        self.head.prev = None
        self.tail.next_ = None

        self.middle_node = new_middle_node


N = int(input())
dlist = DoublyLinkedList()

for _ in range(N):
    args = input().split()

    if args[0] == "add":
        x = int(args[1])
        dlist.push_back(x)

    elif args[0] == "gun":
        dlist.pop_back()

    elif args[0] == "milen":
        dlist.move_sequence()

print(dlist.size)
dlist.print()
