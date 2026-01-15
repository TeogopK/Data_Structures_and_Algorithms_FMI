# Упражнение 12

# Най-кратък път в граф

## Днес ще разгледаме

- Претеглен граф (Weighted graph)
- Алгоритъм на Дейкстра (Dijkstra)
- Алгоритъм на Белман-Форд (Bellman-Ford)
- Най-кратък път в DAG
- Бонус

## Непретеглен граф

- Най-кратък път в непретеглен граф се намира чрез Breadth-first search (BFS).
- Не е нужно използването на по-сложни алгоритми като този на Дийкстра.
- Непретеглен граф може да се представи като претеглен такъв, където всички ребра са с равна тежест (единица).

## Претеглен граф

- Граф, при който всяко ребро има тежест.
- Тежестта може да представлява цена, разстояние, капацитет и т.н.
- Представянето може да се реализира по различни начини в зависимост какво трябва задачата. Един такъв начин е чрез списък на съседство. Всеки връх притежава списък от наредените двойки - съседен връх и тегло на реброто. Друг начин е с матрица на съседство.

<img src="media/dijkstra_undirected_graph.png" width="400px" />

```python
undirected_graph = {
    0: [(2, 7), (1, 1)],
    1: [(0, 1), (2, 8), (3, 7), (4, 2)],
    2: [(0, 7), (1, 8), (4, 3)],
    3: [(1, 7), (4, 6)],
    4: [(3, 6), (1, 2), (2, 3)]
}
```

### Релаксация

Релаксация е ключов процес в много алгоритми за намиране на най-къс път. Тя представлява стъпка, при която разстоянието до даден връх се актуализира, ако бъде намерен по-къс път до него.

## Dijkstra's algorithm (Алгоритъм на Дейкстра)

- [Greedy](https://en.wikipedia.org/wiki/Greedy_algorithm) алгоритъм, който пресмята най-кратък път от начален връх до всички останали в претеглен граф.
- Сложността по време зависи от използваната структура.
- При използването на _Binary Heap_ сложността е _O(E\*logE)_.
- Алгоритъмът не работи правилно при наличие на ребро с отрицателна тежест.

<details>
  <summary>Python code</summary>

```python
from heapq import heappop, heappush

INF = float('infinity')

def dijkstra(start, V, graph):
    distances = [INF] * V
    distances[start] = 0

    visited = set()

    pq = [(0, start)]

    while pq:
        total_weight, current = heappop(pq)

        if current in visited:
            continue
        visited.add(current)

        for neighb, added_weight in graph[current]:
            if neighb in visited:
                continue

            new_weight = total_weight + added_weight

            if distances[neighb] == INF or new_weight < distances[neighb]:
                distances[neighb] = new_weight
                heappush(pq, (new_weight, neighb))

    return distances

dijkstra(0, 5, undirected_graph) # [0, 1, 6, 8, 3]
```

</details>

<details>
  <summary>C++ code</summary>

```c++
struct Edge {
    int to, weight;
};

struct Node {
    int index, distance;

    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

std::vector<int> dijkstra(int start, int V, std::unordered_map<int, std::vector<Edge>>& graph) {
    std::vector<int> distances(V, INT_MAX);
    distances[start] = 0;

    std::priority_queue<Node> nextToProcess;
    nextToProcess.push({ start, 0 });

    while (!nextToProcess.empty()) {
        auto currentNode = nextToProcess.top();
        nextToProcess.pop();

        if (currentNode.distance > distances[currentNode.index]) {
            continue;
        }

        for (const auto& edge : graph[currentNode.index]) {
            int newWeight = currentNode.distance + edge.weight;
            if (newWeight < distances[edge.to]) {
                // relaxation
                distances[edge.to] = newWeight;
                nextToProcess.push({ edge.to, newWeight });
            }
        }
    }

    return distances;
}

```

</details>

Алгоритъм:

1. Отбелязваме всички върхове като недостижми (дистанцията до тях е безкрайност).
2. Започваме от началния връх, като дистанцията до него е 0. Маркираме го като посетен - най-кратката дистанция до него вече е намерена.
3. Изчисляваме дистанция до всеки непосетен връх, съседен на текущия, като сбор от текущата дистанция и тежестта на реброто свързваща двата върха.
4. Ако новата дистанция е по-малка от записаната за върха, обновяваме дистанцията. Добавяме в приоритетна опашка новата намерена дистанция до конкретния връх заедно с върха.
5. Взимаме върха с най-кратка дистанция от приоритетната опашка и повтаряме _стъпки 3, 4 и 5_ до изчерпване на върховете в опашката. При взимане на върха от приоритетната опашка,
   сме сигурни, че най-кратката дистанция до него е намерена и го бележим като посетен. Пропускаме итерация при взимането на вече посетен връх от приоритетната опашка, тъй като по-кратки пътища от него не можем да намерим.

Пример в [playground-а](./Examples/playground_11.ipynb).

### Как чрез алгоритъм на Дийкстра да открием минималния път между два върха?

- След като намерим най-кратките дистанции от началния връх до всички останали, можем да проследим пътя обратно от крайната точка до началната.
- За целта, при всяка релаксацията, трябва да запазваме и предшественика на всеки връх. т.е да имаме масив `predecessors`, където `predecessors[v]` ще съдържа върха, от който сме достигнали `v` с най-краткия път.
- След като приключим с алгоритъма, можем да използваме масива `predecessors`, за да проследим пътя от крайната точка обратно до началната, като започнем от крайната точка и последователно вземаме предшественика ѝ, докато не достигнем началната точка или -1.

<details>
  <summary>Python code</summary>

```python
from heapq import heappop, heappush

INF = float('infinity')

def dijkstra(start, V, graph):
    distances = [INF] * V
    # to store predecessors
    predecessors = [-1] * V
    distances[start] = 0

    visited = set()

    pq = [(0, start)]

    while pq:
        total_weight, current = heappop(pq)

        if current in visited:
            continue
        visited.add(current)

        for neighb, added_weight in graph[current]:
            if neighb in visited:
                continue

            new_weight = total_weight + added_weight

            if distances[neighb] == INF or new_weight < distances[neighb]:
                distances[neighb] = new_weight
                # update predecessor
                predecessors[neighb] = current
                heappush(pq, (new_weight, neighb))

    return distances

dijkstra(0, 5, undirected_graph) # [0, 1, 6, 8, 3]

def reconstruct_path(start, end, predecessors):
    path = []
    at = end
    while at != -1:
        path.append(at)
        at = predecessors[at]
    path.reverse()
    return path if path[0] == start else []  # return empty path if there is no path from start to end
```

</details>

<details>
  <summary>C++ code</summary>

```c++

std::vector<int> dijkstra(int start, int V, std::unordered_map<int, std::vector<Edge>>& graph) {
    std::vector<int> distances(V, INT_MAX);
    // to store predecessors
    std::vector<int> predecessors(V, -1);
    distances[start] = 0;

    std::priority_queue<Node> nextToProcess;
    nextToProcess.push({ start, 0 });

    while (!nextToProcess.empty()) {
        auto currentNode = nextToProcess.top();
        nextToProcess.pop();

        if (currentNode.distance > distances[currentNode.index]) {
            continue;
        }

        for (const auto& edge : graph[currentNode.index]) {
            int newWeight = currentNode.distance + edge.weight;
            if (newWeight < distances[edge.to]) {
                // relaxation
                distances[edge.to] = newWeight;
                // update predecessor
                predecessors[edge.to] = currentNode.index;
                nextToProcess.push({ edge.to, newWeight });
            }
        }
    }

    return distances;
}

vector<int> reconstructPath(int start, int end, const vector<int>& predecessors) {
    vector<int> path;
    for (int at = end; at != -1; at = predecessors[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path[0] == start ? std::vector<int>{} : path; // return empty path if there is no path from start to end
}

```

</details>

Още за Дийкстра може да прочетете [тук](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm).

## Bellman-Ford algorithm (Алгоритъм на Белман-Форд)

- Алгоритъм, който пресмята най-кратък път от начален връх до всички останали в **ориентиран** претеглен граф.
- Алгоритъмът **работи** правилно при наличие на ребро с отрицателна тежест.
- Използва подхода [Динамично оптимиране](https://en.wikipedia.org/wiki/Dynamic_programming) - свеждането на сложен проблем до набор от малки лесноразрешими проблеми.
- По-бавен алгоритъм от този на Дийкстра - сложността по време _O(VE)_
- Има свойството да открива наличие на цикъл с отрицателна дължина. При наличие на такъв цикъл в граф, не съществува най-кратък път.
- Всеки неориентиран граф, може да се представи като ориентиран такъв с цикъл. За това при наличие на отрицателно тегло в неориентирания граф, алгоритъмът няма да открие най-кратките пътища.

Пример:

```python
graph_list_of_edges = [
    (0, 1, 1), (0, 2, 7), (0, 3, 5), (1, 3, 1), (2, 1, -10),
]
```

<img src="media/dijkstra_negative_edge_graph.png" width="400px" />

Въпрос: Какво щеше да стане ако реброто от 0 към 1 беше насочено от 1 към 0?

<details>
  <summary>Python code</summary>

```python
INF = float('infinity')

def bellman_ford(start, V, graph):
    distances = [INF] * V
    distances[start] = 0

    for _ in range(V - 1):
        for x, y, w in graph: # O(E)
            if distances[y] != INF
                distances[y] = min(distances[y], distances[x] + w)

    for x, y, w in graph:
        if distances[x] + w < distances[y]:
            raise Exception("Graph has a negative cycle")

    return distances

bellman_ford(0, 4, graph_list_of_edges) # [0, -3, 7, -2]
```

</details>

<details>
  <summary>C++ code</summary>

```c++
struct Edge {
    int from, to, weight;
};

std::vector<int> bellman_ford(int start, int nodesCount, const std::vector<Edge>& edges) {
    std::vector<int> distances(nodesCount, INT_MAX);
    distances[start] = 0;

    for (int i = 0; i < nodesCount - 1; ++i) {
        for (const auto& edge : edges) {
            if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]) {
                distances[edge.to] = distances[edge.from] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]) {
            throw std::logic_error("Oh, no negative cycle...");
        }
    }

    return distances;
}
```

</details>

Интуиция: Алгоритъмът последователно намира най-кратките пътища от началния връх до всички останали с дължина най-много 1, след това с най-много 2 и т.н. до дължина най-много V - 1. Най-краткият път с най-много ребра без цикъл може да бъде с най-много (_V - 1_) ребра.

## Най-кратък път в DAG - използвайки топологична сортировка

- Сложност _O(V + E)_
- По-оптимален от Дийкстра и Белман-Форд при работа с DAG.

Стъпки:

1. Сортираме топологически DAG-a.
2. Итерираме върховете по топологическия ред.
3. За всеки връх релаксираме изходящите ребра.

<details>
  <summary>Python code</summary>

```python
def topological_dfs(u, visited, stack, graph):
    visited.add(u)
    for v, _ in graph[u]:
        if v not in visited:
            topological_dfs(v, visited, stack, graph)
    stack.append(u)


def topological_sort(graph):
    visited = set()
    stack = []
    for u in graph:
        if u not in visited:
            topological_dfs(u, visited, stack, graph)
    stack.reverse()
    return stack


def shortest_paths_dag(S, V, graph):
    INF = float('infinity')
    dist = [INF] * V
    dist[S] = 0

    topo = topological_sort(graph)

    for u in topo:
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist
```

</details>

<details>
  <summary>C++ code</summary>

```c++

struct Edge {
    int to, weight;
};

void topologicalSort(
    int current,
    const std::unordered_map<int, std::vector<Edge>>& graph,
    std::vector<bool>& visited,
    std::stack<int>& topologicalSortStack
) {
    visited[current] = true;
    if (graph.find(current) != graph.end()) {
        for (const auto& edge : graph.at(current)) {
            if (!visited[edge.to]) {
                topologicalSort(edge.to, graph, visited, topologicalSortStack);
            }
        }
    }
    topologicalSortStack.push(current);
}

std::vector<int> dagShortedPath(int start, int V, const std::unordered_map<int, std::vector<Edge>>& graph) {
    std::vector<int> distances(V, INT_MAX);
    distances[start] = 0;

    std::stack<int> topologicalSortStack;
    std::vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSort(i, graph, visited, topologicalSortStack);
        }
    }

    while (!topologicalSortStack.empty()) {
        int u = topologicalSortStack.top();
        topologicalSortStack.pop();

        if (distances[u] != INT_MAX && graph.find(u) != graph.end()) {
            for (const auto& edge : graph.at(u)) {
                if (distances[u] + edge.weight < distances[edge.to]) {
                    distances[edge.to] = distances[u] + edge.weight;
                }
            }
        }
    }

    return distances;
}

```

</details>

### Сравнение

![image](https://github.com/user-attachments/assets/e95779e7-d34e-4799-8938-bb37246f27a8)

## Задачи за упражнение

### Medium

- [Dijkstra: Shortest Reach 2](https://www.hackerrank.com/challenges/dijkstrashortreach/problem)
  - за изпробване на Дийкстра
- [Network Delay Time](https://leetcode.com/problems/network-delay-time)
- [Long Long](https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long)
- [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability)
- [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

### Hard

- [Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)
  - Дийкстра в матрицата
  - напълно аналогични задачи
    - [Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid)
    - [Path With Minimum Effort - Medium](https://leetcode.com/problems/path-with-minimum-effort/)

## Бонус

- Защо O(logV)~O(logE) (не мултиграф)
- Друг алгоритъм за намиране на най-кратък път между всички възможни двойки от върхове - [Floyd-Warshall](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)
	- може да го изпобвате - https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem

### [0-1 BFS (Shortest Path in a Binary Weight Graph)](https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/)

- Модификация на BFS за намиране на най-кратък път в граф, където ребрата имат тежест 0 или 1 (или само две допустими стойности).
- Сложност O(V + E).
- Логиката се основава на използването на двустранна опашка (deque), където върховете, достигнати чрез ребра с тежест 0, се добавят в началото на опашката, а тези, достигнати чрез ребра с тежест 1, се добавят в края. По този начин се гарантира, че върховете с по-ниска тежест се обработват първо.


<details>
  <summary>C++</summary>

```c++
#include <deque>
#include <vector>

std::vector<int> zeroOneBFS(int start, int V, std::unordered_map<int, std::vector<Edge>>& graph) {
    std::vector<int> distances(V, INT_MAX);
    distances[start] = 0;

    std::deque<int> dq;
    dq.push_front(start);

    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();
        
        if (graph.find(current) == graph.end()) {
            continue;
        }

        for (const auto& edge : graph[current]) {
            int newDistance = distances[current] + edge.weight;

            if (newDistance < distances[edge.to]) {
                distances[edge.to] = newDistance;
                if (edge.weight == 0) {
                    dq.push_front(edge.to);
                } else {
                    dq.push_back(edge.to);
                }
            }
        }
    }

    return distances;
}

```

</details>

<details>
  <summary>Python TODO</summary>


</details>
