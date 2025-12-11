# Упражнение 10 - Приоритетна опашка

## Днес ще разгледаме

- Пирамида (Heap)
- Пирамидално сортиране (Heap sort)
- Приоритетна опашка (Priority queue)

## Heap (Пирамида)

Heap e дървовидна структура от данни, която изпълнява heap свойството:

- **Min heap** - най-малкият елемент е коренът. Всеки възел е по-малък по стойност от децата си.
- **Max heap** - най-големият елемент е коренът. Всеки възел е по-голям по стойност от децата си.

Има различни видове пирамиди, но в рамките на курса ще говорим за двоична пирамида. За нея е характерно:

- Всяко ниво на дървото без последното е задължително запълнено - complete дърво
- Последното ниво се запълва последователно.
- Структура може да се имплементира чрез масив.

<img src="https://github.com/user-attachments/assets/e71e3fcd-d235-427b-a81c-d6db9e207d3c" alt="Drawing" style="max-width: 450px;" />

### Функции:

- **O(1)** достъп до най-малкия елемент - корена.
- **O(log(N))** добавяне и премахване на елемент.
- Не предоставя възможност за ефикасно търсене на случаен елемент.
- **Не е** задължително обхождането в широчина/дълбочина да изведе елементите в сортиран ред.
- Премахването на корена до изчерпване на елементите **ще изведе** елементите в сортиран ред.

### Имплементация с масив

- Коренът се намира на индекс 0.
- Децата на възел _i_ се намират на позиции _2i + 1_ и _2i + 2_.
- Родителят на възел _i_ се намира на позиция _(i - 1) / 2_

### Операции:

#### siftUp - O(logN)

<details>
    <summary>C++</summary>

```c++
void siftUp(std::vector<int>& arr, int currentIndex) {
    int parentIndex = (currentIndex - 1) / 2;

    // Continue sifting up until the element reaches the root or is in the correct position
    while (currentIndex > 0 && arr[currentIndex] > arr[parentIndex]) {
        std::swap(arr[currentIndex], arr[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}
```

</details>

<details>
    <summary>Python</summary>

```python
def sift_up(arr, current_index):
    parent_index = (current_index - 1) // 2

    while current_index > 0 and arr[current_index] > arr[parent_index]:
        arr[current_index], arr[parent_index] = arr[parent_index], arr[current_index]
        current_index = parent_index
        parent_index = (current_index - 1) // 2
```

</details>

---

#### siftDown (heapify) - O(logN)

<details>
	<summary>C++</summary>

```c++
void siftDown(std::vector<int>& arr, int currentIndex) {
    int largestIndex = currentIndex; // assume current node is the largest
    int leftIndex = 2 * currentIndex + 1;
    int rightIndex = 2 * currentIndex + 2;

    if (leftIndex < arr.size() && arr[leftIndex] > arr[largestIndex]) {
        largestIndex = leftIndex;
    }
    if (rightIndex < arr.size() && arr[rightIndex] > arr[largestIndex]) {
        largestIndex = rightIndex;
    }

    // If the largest is not the root, swap and recursively fix the affected sub-tree
    if (largestIndex != currentIndex) {
        std::swap(arr[currentIndex], arr[largestIndex]);
        siftDown(arr, largestIndex);
    }
}
```

</details>

<details>
    <summary>Python</summary>

```python
def sift_down(arr, current_index, size=None):
    if size is None:
        size = len(arr)

    largest_index = current_index
    left = 2 * current_index + 1
    right = 2 * current_index + 2

    if left < size and arr[left] > arr[largest_index]:
        largest_index = left
    if right < size and arr[right] > arr[largest_index]:
        largest_index = right

    if largest_index != current_index:
        arr[current_index], arr[largest_index] = arr[largest_index], arr[current_index]
        sift_down(arr, largest_index, size)

```

</details>

---

#### buildHeap - O(N)

<details>
	<summary>C++</summary>

```c++
void makeHeap(std::vector<int>& arr) {
    // Start from the last non-leaf node and move upwards
    // the last n/2 + 1 nodes are already valid heaps!
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        siftDown(arr, i);
    }
}
```

</details>

<details>
    <summary>Python</summary>

```python
def build_heap(arr):
    for i in range(len(arr) // 2 - 1, -1, -1):
        sift_down(arr, i)

```

</details>

---

При създаване на heap от масив последните $n/2$ елемента (листата) вече изпълняват heap свойството, затова не прилагаме за тях `siftDown`.

<img src="https://github.com/user-attachments/assets/45bf873a-06cf-43a8-8e0a-8b3b0dddd45e" alt="Drawing" style="max-width: 400px;" />

Защо `buildHeap` е $\mathcal{O}(n)$? Детайлно обяснение:
- [wikipedia](https://en.wikipedia.org/wiki/Binary_heap#Building_a_heap).
- [stackoverflow](https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity)
  
Визуализация: [VisualAlgo - Heap](https://visualgo.net/en/heap)

## Heap Sort (Пирамидално сортиране)

Алгоритъм:

1. Създаване на Heap чрез `buildHeap` - $\mathcal{O}(n)$
2. Последователно извличане на елементи с `siftDown` - $\mathcal{O}(n \log n)$

<details>
	<summary>C++</summary>

```c++
void heapSort(std::vector<int>& arr) {
    // O(n)
    buildHeap(arr);

    // O(nlogn)
    for (int i = n - 1; i > 0; --i) {
        // Move the current root to the end
	// as a result the last element will be max/min
        std::swap(arr[0], arr[i]);

        // siftDown on the reduced array!!!
        siftDown(arr, 0, i);
    }
}
```

</details>

<details>
	<summary>Python</summary>

```python
def heap_sort(arr):
    n = len(arr)
    build_heap(arr)

    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        sift_down(arr, 0, i)

```

</details>

| Характеристика   | Стойност                |
| ---------------- | ----------------------- |
| Time complexity  | $\mathcal{O}(n \log n)$ |
| Space complexity | $\mathcal{O}(1)$        |
| Stable           | No                      |
| In-place         | Yes                     |
| Adaptive         | No                      |
| Locality         | No                      |

- използва се в [Introsort](https://en.wikipedia.org/wiki/Introsort)

## Сравнение на Heap с други структури

| Операция         | Heap     | BST (балансирано) | Сортиран масив |
| ---------------- | -------- | ----------------- | -------------- |
| Insert           | O(log n) | O(log n)          | O(n)           |
| Delete min/max   | O(log n) | O(log n)          | O(1)           |
| Get min/max      | O(1)     | O(log n)          | O(1)           |
| Search arbitrary | O(n)     | O(log n)          | O(log n)       |
| Build from array | O(n)     | O(n log n)        | O(n log n)     |

## Priority Queue (Приоритетна опашка)

Абстрактна структура от данни, на която всеки елемент има приоритет. От приоритетната опашка излизат първо елементите с по-висок приоритет, последвани от тези с по-нисък. Не е дефинирано поведението в случай на еднакакъв приоритет кой излиза пръв т.е. зависи от имплементацията. Приоритетна опашка обикновено се имплементира с Heap, където приоритета се определя на база сравнение между елементите.

Основни операции:

- isEmpty() - проверка дали има елементи
- insertWithPriority(element, priority) - добави елемент с приоритет
- getHighestPriorityElement() - взима елемента с най-висок приоритет

## Имплементации в стандартните библиотеки

<details>
	<summary>C++</summary>

std::priority_queue<T> е темплейтен клас идващ от <queue>. По подразбиране контейнера отзад е std::vector и приоритетната опашка работи като Max heap, т.е. най-приоритетния елемент е най-отгоре. Това се случва понеже по-подразбиране compare функцията е std::less, който просто извиква operator< на типа

```c++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

// ...
priority_queue<int> maxHeap;

// main functions
maxHeap.size(); // returns size
maxHeap.empty(); // returns size == 0
maxHeap.top(); // returns the top element (with the highest prio)
maxHeap.push(el); // inserts el
maxHeap.pop(); // pops top element
```

Ако искаме да направим min heap, трябва да използваме std::greater<T> за compare функция. std::greater<T> извиква operator> на типа

```c++
priority_queue<int, vector<int>, greater<int>> minHeap;
```

**Note:** преди C++14 вместо std::less и std::greater се е ползвало op< и op>

В случай, че нашия тип няма operator< или operator>, или тези функции не правят това, което ни трябва за да получим нужната подредба в приоритетната опашка, трябва да подадем наша compare функция(или тип на обект, който се държи като функция :)).

```c++
#include <iostream>
#include <vector>
#include <queue>

struct Struct {
	int a, b;
};

struct StructMaxComparator {
	bool operator()(const Struct& s1, const Struct& s2) {
		return s1.a < s2.a;
	}
};

struct StructMinComparator {
	bool operator()(const Struct& s1, const Struct& s2) {
		return s1.a > s2.a;
	}
};

int main() {
	// change to StructMinComparator to make it min heap
	std::priority_queue<Struct, std::vector<Struct>, StructMaxComparator> pq;

	pq.push({ 1, 2 });
	pq.push({ 2, 3 });
	pq.push({ 0, 4 });

	while (!pq.empty()) {
		auto& s = pq.top();
		std::cout << s.a << " " << s.b << std::endl;
		pq.pop();
	}
}

```

Допълнителни полезни функции, ако ползвате c++:

- std::make_heap - прави масив на heap за линейно време
- std::pop_heap - маха елемент от heap и му оправя наредбата със siftDown
- std::push_heap -
- std::nth_element - използва quick select алгоритъма - average O(n) време

Създаване на приоритетна опашка от съществуващ масив:

```c++
// v1
std::vector<int> arr = {7, 3, 4, 9, 6};
std::priority_queue<int> pq(arr.begin(), arr.end());

// v2
std::vector<int> arr = {7, 3, 4, 9, 6};
std::make_heap(arr.begin(), arr.end());
// use arr as heap

```

</details>

<details>
	<summary>Python</summary>

Съществуват две готови имплементации _heapq_ и _queue.PriorityQueue_.

### heapq

- [Модулът](https://docs.python.org/3/library/heapq.html) работи върху _list_ структура.
- Може да превърне _list_ в _Min heap_ чрез _heappify()_ за **_O(N)_** време без използването на допълнителна памет.
- Масив превърнат в _Heap_ **не е** сортиран! Всеки елемент трябва да бъде изваден за логаритмично време.
- Предоставя възможност за добавяне на елемент (_heappush()_) и премахване на най-малкия елемент (_heappop()_) с логаритмична сложност.

```python
import heapq

h = [7, 3, 4, 9, 6]
heapq.heapify(h)

print(h[0]) # 3
heapq.heappush(h, 5)

while h:
    print(heapq.heappop(h)) # 3, 4, 5, 6, 7, 9
```

Ако искаме да използваме MaxHeap можем да добавяме елементите с обратен приоритет. Тогава при премахването им може да се наложи да обърнем знака.

```python
import heapq

h = []
heapq.heappush(h, -10)
heapq.heappush(h, -3)
heapq.heappush(h, -7)

print(-heapq.heappop(h)) # 10
```

```python
import heapq

arr = [10, 3, 7]
h = [-x for x in arr]
heapq.heapify(h)

print(-heapq.heappop(h))  # 10
```

```python
import heapq

h = []

heapq.heappush(h, (-90, "Gosho"))
heapq.heappush(h, (-75, "Pesho"))
heapq.heappush(h, (-82, "Ivan"))

# вадим ги по най-голям score
while h:
    neg_score, name = heapq.heappop(h)
    score = -neg_score
    print(name, score)

```

### queue.PriorityQueue

- Модулът [_queue_](https://docs.python.org/3/library/queue.html) предоставя синхронни опашки, които са [_thread safe_](https://en.wikipedia.org/wiki/Thread_safety).
- Използва _heapq_ структурата отдолу.
- Предоставя възможност за добавяне на елемент (_put()_) и премахване на най-малкия елемент (_get()_) с логаритмична сложност.

```python
from queue import PriorityQueue

pq = PriorityQueue()
arr = [7, 3, 4, 9, 6]

for el in arr:
    pq.put(el)

print(pq.queue[0]) # 3
pq.put(5)

while not pq.empty():
    print(pq.get())  # 3, 4, 5, 6, 7, 9
```

</details>

## Задачи за упражнение

### Easy

- [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
- [Max Score After K Operations - Medium/Easy](https://leetcode.com/problems/maximal-score-after-applying-k-operations/)
- [K Closest Points to Origin - Medium](https://leetcode.com/problems/k-closest-points-to-origin/)
- [Kth Largest Element in an Array - Medium](https://leetcode.com/problems/kth-largest-element-in-an-array)
  - sorting
  - quick select algo
  - heap

### Medium
- [Jesse and Cookies](https://www.hackerrank.com/challenges/jesse-and-cookies/problem)
- [Task Scheduler](https://leetcode.com/problems/task-scheduler/)
  - с много памет
  - с малко памет 
- [Фитнес зала](https://www.hackerrank.com/contests/sda-test4-2022-2023-343rrsdfs/challenges/challenge-3768/problem)
  - leetcode analog - https://leetcode.com/problems/meeting-rooms-ii/description/
- [Магазин за баници](https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/fullstack-developer)
  - leetcode аналог - https://leetcode.com/problems/single-threaded-cpu/

### Hard
- [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
  - [Hackerrank аналог](https://www.hackerrank.com/challenges/find-the-running-median/problem)
  - sorting
  - pq
  - insertion
- [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
  - kN
  - nlogk
