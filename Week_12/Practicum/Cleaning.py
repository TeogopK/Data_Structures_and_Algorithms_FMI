def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents):
    x_root = find(x, parents)
    y_root = find(y, parents)

    if x_root != y_root:
        parents[x_root] = y_root
        return 1
        
    return 0
        
def is_connected(V, E):
    parents = [i for i in range(V)]
    count = 0

    for i in range(E):
        x1, x2 = [int(x) for x in input().split()]

        count += union(x1 - 1, x2 - 1, parents)

        if count == V - 1:
            return i + 1
        
    return -1

V, E = [int(x) for x in input().split()]

if V == 1:
    print(0)
else:
    print(is_connected(V, E))