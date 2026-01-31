"""
Solution idea:
Start from the bottom of the tree.
1. Mark all leaves as to be painted. There is no need to paint them.
    We can paint their parents.`
2. Paint all parents of the leaves.
3. Mark all parents of the painted nodes as already painted.
4. Consider the parents of the nodes in step 3 as the ones to be painted next.
    Meaning that the 4th parents can be considered as leaves from step 1."""

TO_BE_PAINTED = 0
IS_PAINTER = 1
ALREADY_PAINTED = 2

class Node:
    def __init__(self, left, right):
        self.left = left
        self.right = right


def dfs(indx, marked, tree):
    if indx == -1:
        return ALREADY_PAINTED
    
    l = dfs(tree[indx].left, marked, tree)
    r = dfs(tree[indx].right, marked, tree)
    
    if l == ALREADY_PAINTED and r == ALREADY_PAINTED:
        return TO_BE_PAINTED
    
    if l == TO_BE_PAINTED or r == TO_BE_PAINTED:
        marked.append(indx)
        return IS_PAINTER
    
    if l == IS_PAINTER or r == IS_PAINTER:
        return ALREADY_PAINTED
    
    return TO_BE_PAINTED

def solve(tree):
    root_indx = 0
    marked = []

    root_type = dfs(root_indx, marked, tree)
    
    # Edge case: If root element is waiting to be painted from above.
    if root_type == TO_BE_PAINTED:
        marked.append(root_indx)
    
    return len(marked)  

N = int(input())
tree = [Node(*map(int, input().split())) for _ in range(N)]

print(solve(tree))
