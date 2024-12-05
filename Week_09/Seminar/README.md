# Упражнение 9

# Приоритетна опашка

## Днес ще разгледаме

- Пирамида (Heap)
- Пирамидално сортиране (Heap sort)
- Приоритетна опашка (Priority queue)

## Heap (Пирамида)

Heap e дървовидна структура от данни, която изпълнява heap свойството:
- min heap най-малкият елемент е коренът. Всеки възел е по-малък по стойност от децата си.
- max heap най-големият елеменет е коренът. Всеки възел е по-голям по стойност от децата си

Има различни видове пирамиди, но в рамките на курса ще говорим за двоична пирамида. За нея е характерно:
- Всяко ниво на дървото без последното е задължително запълнено. Complete дърво!
- Последното ниво се запълва последователно.
- Структура може да се имплементира чрез масив.

![image](https://github.com/user-attachments/assets/e71e3fcd-d235-427b-a81c-d6db9e207d3c)

### Функции:

- **O(1)** достъп до най-малкия елемент - корена.
- **O(log(N))** добавяне и премахване на елемент.
- Не предоставя възможност за ефикасно търсене на случаен елемент.
- **Не е** задължително обхождането в широчина/дълбочина да изведе елементите в сортиран ред.
- Премахването на корена до изчерпване на елементите **ще изведе** елементите в сортиран ред.

### Имплементация с масив

- Коренът се намира на индекс 0.
- Децата на възел *i* се намират на позиции *2i + 1* и *2i + 2*.
- Родителят на възел *i* се намира на позиция *(i - 1) / 2*

### Операции:
- siftUp - **O(logN)**
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
- siftDown - **O(logN)**
```c++
void heapify(std::vector<int>& arr, int currentIndex) {
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
        heapify(arr, largestIndex);
    }
}
```
- buildHeap - **O(N)** 
```c++
void makeHeap(std::vector<int>& arr) {
    // Start from the last non-leaf node and move upwards
    // the last n/2 + 1 nodes are already valid heaps!
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        siftDown(arr, i);
    }
}
```

При създаване на heap от масив, както можем да забележим, последните n/2 + 1 елемента (листата), те вече изпълняват heap свойството, затова няма да прилагаме за тях операцията siftDown

![image](https://github.com/user-attachments/assets/45bf873a-06cf-43a8-8e0a-8b3b0dddd45e)


Ако някой се интересува защо buildHeap ила O(n) сложност може да прочете [тук](https://en.wikipedia.org/wiki/Binary_heap#Building_a_heap)

## Heap Sort (Пирамидално сортиране)

- *O(NlogN)* сложност по време.
- *О(1)* сложност по памет - *inplace*.
- Първо, създаване na Heap чрез метода *makeHeap* - линейно при оптимална имплементация.
- Второ, последователно изкарване на всеки елемент чрез запазване на Heap свойството - логаритмична сложност.
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

## Priority Queue (Приоритетна опашка)

Абстрактна структура от данни, на която всеки елемент има приоритет. От приоритетната опашка излизат първо елементите с по-висок приоритет, последвани от тези с по-нисък. Не е дефинирано поведението в случай на еднакакъв приоритет кой излиза пръв т.е. зависи от имплементацията. Приоритетна опашка обикновено се имплементира с Heap, където приоритета се определя на база сравнение между елементите.

Основни операции:
- isEmpty() - проверка дали има елементи
- insertWithPriority(element, priority) - добави елемент с приоритет
- getHighestPriorityElement() - взима елемента с най-висок приоритет

## Имплементации в езиците
## Имплементация в C++
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

**Note:** преди C++14 вместо std::lest и std::greater се е ползвало op< и op>

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

## Имплементации в Python

Съществуват две готови имплементации *heapq* и *queue.PriorityQueue*.

### heapq

- [Модулът](https://docs.python.org/3/library/heapq.html) работи върху *list* структура.
- Може да превърне *list* в *Min heap* чрез *heappify()* за ***O(N)*** време без използването на допълнителна памет. 
- Масив превърнат в *Heap* **не е** сортиран! Всеки елемент трябва да бъде изваден за логаритмично време.
- Предоставя възможност за добавяне на елемент (*heappush()*) и премахване на най-малкия елемент (*heappop()*) с логаритмична сложност.

```python
import heapq

h = [7, 3, 4, 9, 6]
heapq.heapify(h)

print(h[0]) # 3
heapq.heappush(h, 5)

while h:
    print(heapq.heappop(h)) # 3, 4, 5, 6, 7, 9
```

### queue.PriorityQueue

- Модулът [*queue*](https://docs.python.org/3/library/queue.html) предоставя синхронни опашки, които са [*thread safe*](https://en.wikipedia.org/wiki/Thread_safety).
- Използва *heapq* структурата отдолу.
- Предоставя възможност за добавяне на елемент (*put()*) и премахване на най-малкия елемент (*get()*) с логаритмична сложност.

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

## Задачи за упражнение

Лесни(директно прилагане):
- [Last Stone Weight - Easy](https://leetcode.com/problems/last-stone-weight/)
- [Max Score After K Operations - Medium/Easy](https://leetcode.com/problems/maximal-score-after-applying-k-operations/)
- [K Closest Points to Origin - Medium](https://leetcode.com/problems/k-closest-points-to-origin/)
- [Kth Largest Element in an Array - Medium](https://leetcode.com/problems/kth-largest-element-in-an-array)
  - sorting
  - quick select algo
  - heap

Medium/Hard:
- [Jesse and Cookies - Medium](https://www.hackerrank.com/challenges/jesse-and-cookies/problem)
- [Task Scheduler - Medium](https://leetcode.com/problems/task-scheduler/)
- [Фитнес зала - Medium](https://www.hackerrank.com/contests/sda-test4-2022-2023-343rrsdfs/challenges/challenge-3768/problem)
- [Магазин за баници - Medium](https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/fullstack-developer)
  - leetcode аналог - https://leetcode.com/problems/single-threaded-cpu/
- [Find Median from Data Stream - Hard](https://leetcode.com/problems/find-median-from-data-stream/)
    - [Hackerrank аналог](https://www.hackerrank.com/challenges/find-the-running-median/problem)
- [Merge k Sorted Lists - Hard](https://leetcode.com/problems/merge-k-sorted-lists/)
    - може и без pq
