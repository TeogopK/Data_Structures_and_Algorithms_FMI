class Node:
    def __init__(self, data):
        self.data = data
        self.leftNode = None
        self.rightNode = None

    def __str__(self):
        return str(self.data)


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def create(self, val):
        self.root = self.createHelper(val, self.root)

    def createHelper(self, val, node):
        if node is None:
            return Node(val)
        if node.data < val:
            node.rightNode = self.createHelper(val, node.rightNode)
        elif node.data > val:
            node.leftNode = self.createHelper(val, node.leftNode)
        return node

    def dfs(self, current, val):
        if current is None:
            return

        if current.data % val == 0 and not (current.leftNode is None and current.rightNode is None):
            print(current.data, end=" ")

        self.dfs(current.leftNode, val)
        self.dfs(current.rightNode, val)

    def printSpecific(self, val):
        self.dfs(self.root, val)


tree = BinarySearchTree()
t = int(input())
arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

devidedBy = int(input())

tree.printSpecific(devidedBy)
