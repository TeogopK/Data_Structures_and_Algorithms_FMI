class Node:
    def __init__(self, value, children=None):
        self.value = value
        self.children = children or []


# root -> корен на вече построено дърво
#     - стойностите са уникални в интервала от 1 до n
# queries са двойки (descendant, ancestor) със стойности от 1 до n
def answer_queries(root, queries, n):
    entry = [0] * (n + 1)
    exit_time = [0] * (n + 1)
    timer = 0

    # Попълваме entry и exit time с едно DFS обхождане
    def dfs(node):
        nonlocal timer
        timer += 1
        entry[node.value] = timer
        for child in node.children:
            dfs(child)
        timer += 1
        exit_time[node.value] = timer

    dfs(root)

    # x е наследник на y, ако entry[y] < entry[x] и exit[x] < exit[y]
    return [
        entry[ancestor] < entry[descendant] and exit_time[descendant] < exit_time[ancestor]
        for descendant, ancestor in queries
    ]
