# Решение с DFS (Depth-First Search)
# Рекурсивно обхождаме дървото и събираме сумите за всяко ниво

def dfs(node, level, total_sum):
    if not node:
        return
    
    # Ако нивото е четно, добавяме стойността
    if level % 2 == 0:
        total_sum[0] += node.val
    
    # Рекурсивно обхождаме лявото и дясното поддърво
    dfs(node.left, level + 1, total_sum)
    dfs(node.right, level + 1, total_sum)

def sumOfEvenLevels(root):
    total_sum = [0]  # Използваме list за да можем да променяме стойността в рекурсията
    dfs(root, 0, total_sum)
    return total_sum[0]
