"""Solution with example implementation of stack"""

class Node:
    def __init__(self, data=0, next_=None):
        self.data = data
        self.next_ = next_


class Stack:
    def __init__(self):
        self.top = None 
        self.size = 0
    
    def push(self, data):
        new_node = Node(data)
        self.size += 1

        if not self.top:
            self.top = new_node
        else:
            new_node.next_ = self.top
            self.top = new_node

    def pop(self):
        if self.top:
            self.top = self.top.next_ 
            self.size -= 1

    def peek(self):
        if self.top:
            return self.top.data
        
    def print_stack(self):
        current = self.top

        while current:
            print(current.data, end=' ')
            current = current.next_

        print()

    def is_empty(self):
        return self.size == 0

    def __eq__(self, stack):
        if self.size != stack.size:
            return False
            
        left = self.top
        right = stack.top

        while left and right:
            if left.data != right.data:
                return False
            
            left = left.next_
            right = right.next_
            
        return True 


class Solution:
    def fill_stack(self, text):
        stack = Stack()

        for el in text:
            if el != '#':
                stack.push(el)
            elif not stack.is_empty():
                stack.pop()             
            
        return stack

    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack = self.fill_stack(s)
        t_stack = self.fill_stack(t)

        return s_stack == t_stack
            