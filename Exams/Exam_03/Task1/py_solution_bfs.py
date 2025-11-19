from collections import deque

# Решение с BFS (Breadth-First Search)
# Обхождаме дървото ниво по ниво и събираме сумите на четните нива
def sumOfEvenLevels(root):
    if not root:
        return 0
    
    q = deque([root])
    level = 0
    total_sum = 0
    
    while q:
        level_size = len(q)
        level_sum = 0
        
        # Обхождаме всички възли на текущото ниво
        for _ in range(level_size):
            node = q.popleft()
            
            # Ако нивото е четно, добавяме стойността
            if level % 2 == 0:
                level_sum += node.val
            
            # Добавяме децата в опашката за следващото ниво
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        
        total_sum += level_sum
        level += 1
    
    return total_sum
