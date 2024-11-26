class Node:
    def __init__(self):
        self.is_cafe = -1
        self.children = []
        
def dfs(root = 1, count = 0):
    visited.add(root)
    total = count + 1 if cafes[root].is_cafe == 1 else 0
    
    if total > M:
        return 0
    
    has_children = False
    result = 0
    
    for child in cafes[root].children:
        if child not in visited:
            has_children = True
            result += dfs(child, total)
            
    if not has_children:
        return 1
    
    return result
    
    
N, M = map(int, input().split())
cafes = [Node() for _ in range(N + 1)]

is_cafe_arr =  [-1] + list(map(int, input().split()))
for i in range(1, N + 1):
    cafes[i].is_cafe = is_cafe_arr[i]
    
for i in range(N - 1):
    parent, child = map(int, input().split())
    cafes[parent].children.append(child)
    cafes[child].children.append(parent)
       
visited = set()
print(dfs())
