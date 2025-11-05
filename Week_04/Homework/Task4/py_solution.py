class Node:
    def __init__(self, data=0, next_=None, prev=None):
        self.data = data
        self.next_ = next_
        self.prev = prev


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def push_front(self, data):
        new_node = Node(data)
        self.size += 1

        if not self.head:
            self.head = self.tail = new_node
        else:
            new_node.next_ = self.head
            self.head.prev = new_node
            self.head = new_node

        return self.head

    def pop_front(self):
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next_
            self.head.prev = None

        if self.size > 0:
            self.size -= 1

    def pop_back(self):
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next_ = None

        if self.size > 0:
            self.size -= 1

    def pop_at(self, node):
        if node == self.head:
            self.pop_front()
        elif node == self.tail:
            self.pop_back()
        else:
            node.prev.next_ = node.next_
            node.next_.prev = node.prev

            self.size -= 1

    def back(self):
        if self.tail:
            return self.tail.data

    def print(self):
        current = self.head

        while current:
            print(current.data, end=" ")
            current = current.next_

        print()


def burn_last(dlist, pointers):
    last_key = dlist.back()[0]
    dlist.pop_back()

    pointers[last_key] = None


def get_value_on_key(x, dlist, pointers):
    if pointers[x] == None:
        print(-1)
    else:
        node_to_del = pointers[x]
        node_data = node_to_del.data

        print(node_data[1])

        dlist.pop_at(node_to_del)
        pointers[x] = dlist.push_front(node_data)


def put_key(x, y, max_size, dlist, pointers):
    if pointers[x] == None:
        pointers[x] = dlist.push_front((x, y))

        if dlist.size > max_size:
            burn_last(dlist, pointers)
    else:
        dlist.pop_at(pointers[x])
        pointers[x] = dlist.push_front((x, y))


N, Q, K = map(int, input().split())
MAX_X = 10_001

dlist = DoublyLinkedList()
pointers = [None] * MAX_X

for q in range(1, Q + 1):
    args = input().split()

    if args[0] == "put":
        x = int(args[1])
        y = int(args[2])

        put_key(x, y, N, dlist, pointers)

    elif args[0] == "get":
        x = int(args[1])
        get_value_on_key(x, dlist, pointers)

    if q % K == 0:
        burn_last(dlist, pointers)

    # print(args[0], "------------------")
    # dlist.print()
