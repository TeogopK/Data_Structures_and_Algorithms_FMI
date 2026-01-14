# Упражнение 13

# Минимално покриващо дърво

## Днес ще разгледаме

- Минимално покриващо дърво (Minimum spanning tree)
- Алгоритъм на Прим (Prim)
- Disjoint-set
- Алгоритъм на Крускал (Kruskal)

## Покриващо дърво (Spanning tree) на граф

- Дърво е свързан ацикличен ненасочен граф.
- Покриващо дърво на граф е дърво, подграф на дадения граф, което свързва всички възли на графа.
- Покриващото дърво на граф _G(V, E)_ съдържа _V_ на брой върха и _V - 1_ ребра.
- Добавянето на ребро към покриващо дърво, ще създаде граф с цикъл.
- Премахването на ребро от покриващо дърво, ще създаде граф с две несвързани компоненти.

![Spanning trees of a graph example](media/spanning_trees.png)

По-рядко срещано - В случай на несвързан граф имаме гора от покриващи дървета. (Spanning forest)

## Минимално покриващо дърво (Minimum spanning tree)

- Минимално покриващо дърво на претеглен ненасочен граф е покриващото дърво на графa с минимална сума на ребрата.
- Възможно е да съществува повече от 1 МПД (MST) за даден граф.

![Multiple Minimum spanning trees of a graph example](media/minimum_spanning_trees.png)

## Свойство на минималния разрез (Cut property)

- Нека имаме граф $G(V, E)$ и някакво разделяне на върховете му на две непразни множества $S$ и $V \setminus S$.
- Нека $e$ да е реброто с най-малка тежест, което свързва върховете от $S$ с върховете от $V \setminus S$.
- Тогава съществува минимално покриващо дърво, което съдържа реброто $e$.

## Алгоритъм на Прим (Prim's algorithm)

- Намира минимално покриващо дърво на граф.
- Започва от даден връх и добавя реброто с най-малка тежест до съседен връх, който все още не е част от дървото.
- Сложността по време зависи от структурата за извличане на реброто с най-малка тежест.
- При използването на _Binary Heap_ сложността е _O(E\*logE)_. (При използване на друг вид heap може да достигне до _O(E\*logV)_)

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
            if(visited.count(adj.to)) {
                continue;
            }
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
            if(visited.count(adj.to)) {
                continue;
            }
            pq.push(adj);
        }
    }

    return totalWeight;
}
```

</details>

Пример при започване от _връх 5_:

![Prim's algorithm creating a MST of a graph, step by step example.](media/prims_algorithm_example.png)

- Имплементацията наподобява тази на алгоритъма на Дийкстра с разликата, че приоритетната опашка държи ребра, а не двойка връх и изминат път от началото до него.
- В случай, че искаме да поддържаме гора от MST трябва да променим имплементацията

### Eager vs Lazy Prim

- Имплементацията по-горе е Lazy Prim, тъй като в приоритетната опашка се добавят всички съседни ребра на текущия връх, без значение дали върховете, към които водят, са вече посетени.
- Eager Prim поддържа за всеки връх най-късото ребро, чрез което може да бъде достигнат от вече посетените върхове. Следователно се използва друг тип приоритетна опашка, която позволява актуализация на приоритетите. Следователно тя използва най-много O(V) памет, вместо O(E) при Lazy Prim.

Още за Прим може да прочетете [тук](https://en.wikipedia.org/wiki/Prim%27s_algorithm).

## Disjoint-set структура от данни (Union find data structure)

Структура от данни предназначена за работа с несвързани множества. Две множества са несвързани, ако нямат общи елементи ({1, 2} и {3, 4}).
Относно структурата - първоначално инициализира всеки елемент да бъде в свое собствено множество.
Поддържа две основни операции:

- Проверка дали два елемента са в едно множество,
- Обединяване на множествата на два елемента;

Пример от реалния живот - редене на пъзел.

Структурата е удобна за използване в алгоритъм на Крускал. Сложността за обединяване на N елемента е О(N\*α(N)), където _α_ е обратната функцията на Акерман.

Подробно описание как работи Disjoint-set (Union-find) структурата в [playground-а](playground_13.ipynb). (Имплементацията в playground-а е на Python)
Аналогична C++ имплементация има в съответната папка.

На следния линк можете да експериментирате с това как се променя масив с родители на база кои оптимизации са включени и изключени: [Disjoint-set visualization](https://www.cs.usfca.edu/~galles/visualization/DisjointSets.html)

## Алгоритъм на Крускал (Kruskal's algorithm)

- Намира минимално покриващо дърво на граф.
- Сортира ребрата по минимална тежест, като на всяка стъпка добавя реброто с най-малка тежест, което няма да създаде цикъл в графа.
- Използва структурата _Disjoint set_ за оптимална проверка за цикличност.
- Сложност по време _O(E\*logE)_ заради сортирането на всички ребра.
- При _dense_ граф, когато _Е = V<sup>2</sup>_, _O(ElogE) = O(ElogV<sup>2</sup>) = O(2ElogV) = O(ElogV)_

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

```c++
struct Edge {
    int from;
    int to;
    int weight;
};

// we use the interface
class UnionFind {
public:
    UnionFind(size_t vertices);

    bool areInOneSet(size_t first, size_t second);
    void unionVertices(size_t first, size_t second);
};

std::vector<Edge> kruskal(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    UnionFind uf(n);
    std::vector<Edge> mstEdges;
    for (size_t i = 0; i < edges.size(); i++) {
        if (uf.areInOneSet(edges[i].from, edges[i].to)) {
            continue;
        }

        uf.unionVertices(edges[i].from, edges[i].to);
        mstEdges.push_back(edges[i]);
        if (mstEdges.size() == n - 1) {
            break;
        }
    }

    return mstEdges;
}
```

</details>

![Kruskal's algorithm creating a MST of a graph, step by step example.](media/kruskals_algorithm_example.png)

Крускал поддържа гора от покриващи дървета с леки промени в имплементацията.

## Задачи за упражнение

### Medium
- [Prim's (MST) : Special Subtree](https://www.hackerrank.com/challenges/primsmstsub/problem)
- [Kruskal (MST): Really Special Subtree](https://www.hackerrank.com/challenges/kruskalmstrsub/problem)
- [Min cost to connect all points](https://leetcode.com/problems/min-cost-to-connect-all-points/description/)
- [Clusters](https://www.hackerrank.com/contests/2024-2025-2/challenges/clusterstask)

### Hard
- [Optimize water supply](https://github.com/azl397985856/leetcode/blob/master/problems/1168.optimize-water-distribution-in-a-village-en.md)
  - като цяло в този гитхъб има условия и на други premium задачи от leetcode
- [Find critical and pseudo critical edges in MST](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/)

### Задачи, които може да режите и с материал от предишните седмици
- [Number of provinces](https://leetcode.com/problems/number-of-provinces/description/)
- [Tree Validator](https://www.hackerrank.com/contests/2024-2025-2/challenges/treevalidator)

## Бонус
- [Find duplicate subtrees](https://leetcode.com/problems/find-duplicate-subtrees/)
  - не е свързано с покриващи дървета
  - [Hash/Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)
