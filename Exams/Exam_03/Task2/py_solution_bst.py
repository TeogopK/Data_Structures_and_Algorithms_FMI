# Решение 3: Построяване на собствено BST
# Строим BST и търсим най-малкото число строго по-голямо от X

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Не трябва да се пише, идва наготово
def insert(node, val):
    if not node:
        return TreeNode(val)
    
    if val < node.val:
        node.left = insert(node.left, val)
    elif val > node.val:
        node.right = insert(node.right, val)
    
    return node

# Търсене на най-малкото число строго по-голямо от target
def find_successor(node, target, result):
    if not node:
        return
    
    if node.val > target:
        # Възможен кандидат, търсим по-наляво
        result[0] = min(result[0], node.val)
        find_successor(node.left, target, result)
    else:
        # Търсим вдясно
        find_successor(node.right, target, result)

# Четене на входа
n = int(input())
nums = list(map(int, input().split()))
target = int(input())

# Построяване на BST
bst = None
for num in nums:
    bst = insert(bst, num)

# Търсене на отговора
result = [float('inf')]
find_successor(bst, target, result)

if result[0] == float('inf'):
    print("NO")
else:
    print(result[0])

# Сложност:
# Време: O(N*H) за вмъкване на N елемента, където H е височината на дървото
#        + O(H) за търсене = O(N*H)
#        В най-лошия случай H = N (дегенерирано дърво), в среден случай H = logN
# Памет: O(N) за дървото
