# Упражнение 14

# Минимално покриващо дърво

## Днес ще разгледаме

- Минимално покриващо дърво (Minimum spanning tree)
- Алгоритъм на Прим (Prim)
- Disjoint-set
- Алгоритъм на Крускал (Kruskal)
  
## Покриващо дърво (Spanning tree) на граф

- Дърво е свързан ацикличен насочен граф.
- Покриващо дърво на граф е дърво, подграф на дадения граф, което свързва всички възли на графа.
- Покриващото дърво на граф *G(V, E)* съдържа *V* на брой върха и *V - 1* ребра.
- Добавянето на ребро към покриващо дърво, ще създаде граф с цикъл.
- Премахването на ребро от покриващо дърво, ще създаде граф с две несвързани компоненти.

![Spanning trees of a graph example](media/spanning_trees.png)

По-рядко срещано - В случай на несвързан граф имаме гора от покриващи дървета. (Spanning forest)

## Минимално покриващо дърво (Minimum spanning tree)

- Минимално покриващо дърво на претеглен ненасочен граф е покриващото дърво на графa с минимална сума на ребрата.
- Възможно е да съществува повече от 1 МПД (MST) за даден граф.
  
![Multiple Minimum spanning trees of a graph example](media/minimum_spanning_trees.png)

## Алгоритъм на Прим (Prim's algorithm)

- Намира минимално покриващо дърво на граф.
- Започва от даден връх и добавя реброто с най-малка тежест до съседен връх, който все още не е част от дървото.
- Сложността по време зависи от структурата за извличане на реброто с най-малка тежест.
- При използването на *Binary Heap* сложността е *O(E\*logV)*.

<details>
  <summary>Python code</summary>

```python
from heapq import heappush, heappop

def prim(start, V, graph):
    visited = set()
    pq = [(0, start)]
    mst_weight = 0
    
    while len(visited) != V:
        current_weight, current_vertex = heappop(pq)
        
        if current_vertex in visited:
            continue
        
        visited.add(current_vertex)
        mst_weight += current_weight
        
        for neighb, weight in graph[current_vertex]:
            if neighb in visited:
                continue
                            
            heappush(pq, (weight, neighb))
    
    return mst_weight

prim(5, 5, graph) # 13
```

</details>


<details>
  <summary>C++ code</summary>

```c++
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};
// we assume that the graph is represented as an adjacency list
std::vector<Edge> prim(int n, int start, std::unordered_map<int, std::vector<Edge>>& graph) {
    std::priority_queue<Edge> pq;
    std::unordered_set<int> visited;
    pq.push({ start, start, 0 });

    std::vector<Edge> mstEdges;

    while (!pq.empty() && visited.size() < n) { // visited.size() < n to stop earlier if the mst is ready
        auto current = pq.top();
        pq.pop();
        if (visited.count(current.to)) {
            continue;
        }

        visited.insert(current.to);
        mstEdges.push_back(current);
        for (auto& adj : graph[current.to]) {
            pq.push(adj);
        }
    }

    return mstEdges;
}

// if we are not if the graph is connected
void test() {
        auto mstEdges = prim(n, 1, graph);
        // if the graph is not connected we will have less than n - 1 edges
        // mstEdges.size() - 1 because of the extra edge
        if(mstEdges.size() - 1 < n - 1 ) {
            return -1;
        }

        int result = 0;
        for(size_t i = 1 ; i < mstEdges.size(); i++) {
            result += mstEdges[i].weight;
        }
        return result;
}


// if we are sure that the graph is connected, we can directly do the calculations inside the algorithm
int prim2(int n, int start, std::unordered_map<int, std::vector<Edge>>& graph) {
    std::priority_queue<Edge> pq;
    std::unordered_set<int> visited;
    pq.push({ start, start, 0 }); // fake edge to start the algorithm

    int totalWeight = 0;

    while (!pq.empty() && visited.size() < n) {  // visited.size() < n to stop earlier if the mst is ready
        auto current = pq.top();
        pq.pop();
        if (visited.count(current.to)) {
            continue;
        }

        visited.insert(current.to);
        totalWeight += current.weight;
        for (auto& adj : graph[current.to]) {
            pq.push(adj);
        }
    }

    return totalWeight;
}
```

</details>

Пример при започване от *връх 5*:

![Prim's algorithm creating a MST of a graph, step by step example.](media/prims_algorithm_example.png)

Имплементацията наподобява тази на алгоритъма на Дийкстра с разликата, че приоритетната опашка държи ребра, а не двойка връх и изминат път от началото до него.

## Алгоритъм на Крускал (Kruskal's algorithm)

- Намира минимално покриващо дърво на граф.
- Сортира ребрата по минимална тежест, като на всяка стъпка добавя реброто с най-малка тежест, което няма да създаде цикъл в графа.
- Използва структурата *Disjoint set* за оптимална проверка за цикличност.
- Сложност по време *O(E\*logE)* заради сортирането на всички ребра.
- При *dense* граф, когато *Е = V<sup>2</sup>*, *O(ElogE) = O(ElogV<sup>2</sup>) = O(2ElogV) = O(ElogV)*

<details>
  <summary>Python code</summary>

```python
def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents, rank):
    x_root = find(x, parents)
    y_root = find(y, parents)

    if rank[x_root] < rank[y_root]:
        parents[x_root] = y_root
    elif rank[x_root] > rank[y_root]:
        parents[y_root] = x_root
    else:
        parents[x_root] = y_root
        rank[y_root] += 1

def kruskal(V, edges):
    edges.sort(key=lambda x: x[2])
    parents = [i for i in range(V + 1)]
    rank = [0] * (V + 1)
    mst_weight = 0

    for x, y, w in edges:
        if find(x, parents) != find(y, parents):
            mst_weight += w
            union(x, y, parents, rank)

    return mst_weight

kruskal(5 , graph_list_of_edges) # 13
```

</details>


<details>
  <summary>C++ code</summary>


</details>

![Kruskal's algorithm creating a MST of a graph, step by step example.](media/kruskals_algorithm_example.png)

Подробно описание как работи Disjoint-set (Union-find) структурата в [playground-а](playground_14.ipynb).

## Задачи за упражнение

- [Prim's (MST) : Special Subtree](https://www.hackerrank.com/challenges/primsmstsub/problem)
- [Kruskal (MST): Really Special Subtree](https://www.hackerrank.com/challenges/kruskalmstrsub/problem)

Решения на задачите: [тук](/Tasks/tasks_14)
