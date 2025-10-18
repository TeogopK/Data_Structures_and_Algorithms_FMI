# Упражнение 2

# Алгоритми за сортиране

- Тест среда да изпробвате някои алгоритми - [hackerrank contest](https://www.hackerrank.com/contests/algorithms-implementation-test-environment/challenges)
- Сайт с визуализация на алгоритмите - [visualalgo](https://visualgo.net/en/sorting)

## Locality
  - Дефиниране
	- свойството на процесора, при което той прехвърля в своя кеш често използвани или съседни данни, за да ги достъпва по-бързо при следващи операции.
    - CPU cache - малка, бърза памет в процесора, която съхранява често използвани данни и инструкции, за да ускори достъпа до тях и да подобри производителността.
      - instruction cache - съхранява често използвани машинни инструкции
      - data cache - съхранява често използвани данни от програмите
    - Основни видове:
    	- Temporal locality - ако даден елемент от паметта е бил достъпен наскоро, има голяма вероятност да бъде достъпен отново скоро
    	- Spacial locality - ако даден елемент от паметта бъде достъпен, има голяма вероятност скоро да бъдат достъпени и елементи, намиращи се близо до него по адрес.
  - обхождане на матрица (статична и динамична) по редове срещу обхождане колони
  - **Бонус:**
	- https://www.geeksforgeeks.org/locality-of-reference-and-cache-operation-in-cache-memory/
  	- [CPU cache](https://en.wikipedia.org/wiki/CPU_cache) и [Locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)

## Характеристики на алгоритмите за сортиране

Освен сложност откъм време и откъм памет алгоритмите за сортиране разполагат и със следните характеристики:

- **Stability** - Един алгоритъм е стабилен, ако след сортировка, два равни елемента са в същата последователност, както преди масивът да бъде сортиран.
  - Пример - Вход: $$1, 2, 3_a, 8, 5, 3_b$$. Тук $$3_a$$ и $$3_b$$ са просто две числа, но ги маркираме, за да видим как са подредени в резултата.
  - Stable sort output: $$1,2,3_a,3_b,5,8$$
  - Unstable sort output: $$1,2,3_b,3_a,5,8$$ - поведението не е детерминистично (тоест понякога може да е $$3_a, 3_b$$ друг път $$3_b, 3_a$$ в зависимост от алгоритъма и входа)

- **In-place** - Показва дали алгоритъмът работи директно върху подадените данни и не заделя допълнителна памет пропорционална на входа. Следователно използва константна памет. 
- **Adaptivity** - Показва дали алгоритъмът работи по-бързо за почти сортирани масиви. Ако алгоритъм е неадаптивен, той има едно и също време за изпълнение независимо дали входът е несортиран или почти сортиран.
- **Locality** - Показва дали алгоритъмът се възползва от cache-a на процесора, за да забързва своето изпълнение. За целта данните трябва да бъдат последователни.

Сравнение по капацитет на памет и колко цикъла на процесора са нужни за достъп до нея.

| Memory hierarchy | CPU cycles | size   |
| ---------------- | ---------- | ------ |
| HDD              | 500, 000   | 1 TB   |
| RAM              | 100        | 4 GB   |
| L2 cache         | 10         | 512 kb |
| L1 cache         | 1          | 32 kb  |

- **Number of comparisons** - Показва колко на брой пъти два елемента биват сравнявани помежду си. Много често това съвпада със сложността на алгоритъма откъм време. Минималната стойност за алгоритми, които използват сравнение, е $$\mathcal{O}(n \times log(n))$$ (**Бонус:** Защо?)
- **Number of swaps** - Показва колко на брой пъти два различни елемента биват разменени в паметта. То не влияе на сложността на алгоритъма, но може да повлияе изпълнението на алгоритъма при големи данни и размяна на големи обекти.

**Бонус:**
- **Online** - Показва дали алгоритъмът се нуждае от всичките входни данни, за да почне да сортира. Ако алгоритъм е "online" той може да започне да сортира получавайки данните си на парчета. Полезни са за четене и обработване на данни от потоци. Обратното на "online" алгоритъм ще наричаме "offline". 
- **External** - Показва дали алгоритъмът би работил върху данни, които не могат да се съберат в оперативната памет. Такива алгоритми са направени с цел да могат да се обработват големи обеми от данни, които в повечето пъти ще идват като потоци от данни с източник файл.
	- Пример - merge sort
- **Parallel** - Показва дали алгоритъм може да бъде изпълнявам на няколко нишки едновременно с цел оптимизация на времето за изпълнение.


## Ще разгледаме

- бавни алгоритми за сортиране
  - Bubble sort
  - Selection sort
  - Insertion sort
- бързи алгоритми за сортиране
  - Merge sort
  - Quick sort 
- други (алгоритми, които не използват сравнения)
  - Counting sort
 
Интерактивна визуализация на алгоритмите можете да намерите [тук](https://visualgo.net/en/sorting)

## Бавни алгоритми за сортиране

## Bubble sort (Метод на мехурчето)

| Bubble sort           | n = input size       |
| --------------------- | -------------------- |
| Time complexity       | $$\mathcal{O}(n^2)$$ |
| Space complexity      | $$\mathcal{O}(1)$$   |
| Number of comparisons | $$\mathcal{O}(n^2)$$ |
| Number of swaps       | $$\mathcal{O}(n^2)$$ |
| Adaptive              | Yes                  |
| Stable                | Yes                  |
| Local                 | Yes                  |
| Online                | No                   |
| In-place              | Yes                  |
| Parallel              | No                   |
| External              | No                   |

- *N * (N - 1) / 2* брой размени в най-лошия случай. Кога се случва това?

Идея: След всяка итерация на *i*, най-големият елемент "изплува" чрез последователни размени на съседни елементи.

### Имплементация

<details>
  <summary>C++</summary>

```c++
void bubbleSort(std::vector<int>& arr) {
    int N = arr.size();
    
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

Има ли излишни итерации в тази имплементация и ако да - как да ги намалим?

```c++
void optimizedBubbleSort(std::vector<int>& arr) {
	int lastSwappedIndex = arr.size() - 1;
	for (size_t i = 0; i < arr.size(); i++) {
		int currentSwappedIndex = 0; // what if we used -1?
		for (size_t j = 0; j < lastSwappedIndex; j++) {
			if (arr[j] > arr[j + 1]) {
				currentSwappedIndex = j;
				swap(arr[j], arr[j + 1]);
			}
		}

		if (currentSwappedIndex == 0) {
			return;
		}
		lastSwappedIndex = currentSwappedIndex;
	}
}
```
</details>


<details>
  <summary>Python</summary>
  TODO:...
</details>

## Selection sort (Метод на пряката селекция)

| Selection sort        | n = input size       |
| --------------------- | -------------------- |
| Time complexity       | $$\mathcal{O}(n^2)$$ |
| Space complexity      | $$\mathcal{O}(1)$$   |
| Number of comparisons | $$\mathcal{O}(n^2)$$ |
| Number of swaps       | $$\mathcal{O}(n)$$   |
| Adaptive              | No                   |
| Stable                | No                   |
| Local                 | No                   |
| Online                | No                   |
| In-place              | Yes                  |
| Parallel              | No                   |
| External              | No                   |

Идея: Търси се индексът на най-малкия елемент на всяка итерация. След това се разменя с текущия.


### Имплементация

<details>
  <summary>C++</summary>

```c++
void selectionSort(std::vector<int>& arr) {
    int N = arr.size();
    
    for (int i = 0; i < N - 1; ++i) {
        int min_index = i;
        
        for (int j = i + 1; j < N; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

		if(min_index != i) {
            std::swap(arr[min_index], arr[i]);
		}
    }
}
```
</details>

<details>
  <summary>Python</summary>
  TODO:...
</details>

Предпочитан пред Bubble sort поради по-малкото на брой размени, но за сметка на това не е стабилен. 

## Insertion sort (Метод на картоиграча)

| Insertion sort        | n = input size       |
| --------------------- | -------------------- |
| Time complexity       | $$\mathcal{O}(n^2)$$ |
| Space complexity      | $$\mathcal{O}(1)$$   |
| Number of comparisons | $$\mathcal{O}(n^2)$$ |
| Number of swaps       | $$\mathcal{O}(n^2)$$ |
| Adaptive              | Yes                  |
| Stable                | Yes                  |
| Local                 | Yes                  |
| Online                | Yes                  |
| In-place              | Yes                  |
| Parallel              | No                   |
| External              | No                   |

Идея: Всеки елемент се тегли като карта с гърба надолу. Търси се мястото му в ръката, като се изместват по-големите стойности с една позиция надясно.


### Имплементация


<details>
  <summary>C++</summary>

```c++
void insertionSort(std::vector<int>& arr) {
    int N = arr.size();
    
    for (int i = 1; i < N; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
```

</details>

<details>
  <summary>Python</summary>
  TODO:...
</details>

**Note:** използваме отмествания, които са по-евтина операция от swap

[Подходящ](https://www.toptal.com/developers/sorting-algorithms) за малки масиви, и почти сортирани масиви. Това се дължи на ранното приключване на вътрешния цикъл при правилно поставено число (Best case сложността на алгоритъма е *O(N)*). Често се ползва в комбинация с други алгоритми.

Защо за малки масиви е полезен insertion sort?
- Ползва локалити(мести елементи един до друг)
- Няма рекурсивни извиквания - O(1) памет
- прави отмествания вместо swap
- Адаптивен. Малките масиви са много често почти сортирани.

---
### Обобщение на бавните алгоритми:

|              | Bubble sort        | Selection sort     | Insertion sort     |
| ------------ | ------------------ | ------------------ | ------------------ |
| Best case    | *O(N)*             | *O(N<sup>2</sup>)* | *O(N)*             |
| Average case | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* |
| Worst case   | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* | *O(N<sup>2</sup>)* |
| Памет        | *O(1)*             | *O(1)*             | *O(1)*             |
| Стабилен     | да                 | не                 | да                 |

## Бързи алгоритми за сортиране

## Merge sort (Сортиране със сливане)

| Merge sort            | n = input size            |
| --------------------- | ------------------------- |
| Time complexity       | $$\mathcal{O}(n*log(n))$$ |
| Space complexity      | $$\mathcal{O}(n)$$        |
| Number of comparisons | $$\mathcal{O}(n*log(n))$$ |
| Number of swaps       | $$\mathcal{O}(n*log(n))$$ |
| Adaptive              | No                        |
| Stable                | Yes                       |
| Local                 | No                        |
| Online                | No                        |
| In-place              | No                        |
| Parallel              | Yes                       |
| External              | Yes                       |

- подходът *разделяй и владей*

Идея: Масивът се разделя на две половинки подмасиви. Всяка половинка продължава да се разделя. Процесът спира при достигане на масив с един елемент, който сам по-себе си е сортиран. Тогава започва обратния процес по сливане на подмасивите. Две вече сортирани половинки се сливат в по-голям подмасив, като се "придърпват" в правилния ред елементи ту от левия, ту от десния.


### Имплементация


<details>
  <summary>C++</summary>

```c++
void _mergeSort(std::vector<int>& arr, size_t left, size_t right, std::vector<int>& buffer) {
    if(right - left <= 1) {
		return;
    }

    size_t mid = left + (right - left) / 2;
    
    _mergeSort(arr, left, mid, buffer);
    _mergeSort(arr, mid, right, buffer);
    _merge(arr, left, mid, right, buffer);
}

void mergeSort(std::vector<int>& arr) {
    if(arr.size() <= 1) {
		return;
    }

    std::vector<int> buffer(arr.size());
    _mergeSort(arr, 0, arr.size(), buffer);
}

void _merge(std::vector<int>& arr, size_t left, size_t mid, size_t right, std::vector<int>& buffer) {
    size_t leftIdx = left;
    size_t rightIdx = mid;
    size_t index = 0;

    while (leftIdx < mid && rightIdx < right) {
        if (arr[leftIdx] <= arr[rightIdx]) {
            buffer[index++] = arr[leftIdx++];
        }
        else {
            buffer[index++] = arr[rightIdx++];
        }
    }

    while (leftIdx < mid) {
        buffer[index++] = arr[leftIdx++];
    }

    while (rightIdx < right) {
        buffer[index++] = arr[rightIdx++];
    }

    for (size_t i = 0; i < index; i++) {
		arr[left + i] = buffer[i];
    }
}
```

</details>

<details>
  <summary>Python</summary>
  TODO:...
</details>


Merge sort гарантира $$\mathcal{O}(n*log(n))$$ сложност дори в най-лошия случай, за разлика от Quick sort.

## Quick sort (Бързо сортиране)

| Quick sort                      | n = input size                           |
| ------------------------------- | ---------------------------------------- |
| Time complexity (Worst case)    | $$\mathcal{O}(n^2)$$                     |
| Time complexity (Average case)  | $$\mathcal{O}(n*log(n))$$                |
| Space complexity (Worst Case)   | $$\mathcal{O}(n)$$                       |
| Space complexity (Average case) | $$\mathcal{O}(log(n))$$                  |
| Number of comparisons           | $$\mathcal{O}(n*log(n))$$                |
| Number of swaps                 | $$\mathcal{O}(n*log(n))$$                |
| Adaptive                        | Anti-Adaptive (more randomness = better) |
| Stable                          | No                                       |
| Local                           | Yes                                      |
| Online                          | No                                       |
| In-place                        | Yes                                      |
| Parallel                        | Yes                                      |
| External                        | No                                       |

- *О(logN)* сложност по [памет в средния случай*](https://en.wikipedia.org/wiki/Quicksort#Space_complexity)!


Идея: Избира се елемент от масива, по-който ще се извършва подредбата. Чрез последователни промени, всички по-малки от избрания остават в лявата част на масива, а по-големите - в дясната. Избраният елемент се сменя с първия по-голям от него, за да се позиционира между двете групи. Спрямо индексът на избрания елемент, масивът се дели на два подмасива. Във всеки от тях се повтарят действията по-избиране и сортиране на групите от по-малки и по-големи числа.


### Имплементация

<details>
  <summary>C++</summary>
  
```c++
int partition(std::vector<int>& arr, int low, int high) {
    int initialPivotIndex = rand() % (high - low + 1) + low; // select random index in the range [low, high] for pivot
    std::swap(nums[initialPivotIndex], nums[high]); // put the pivot at the end

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i], arr[high]);
    
    return i;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// how to use
quickSort(arr, 0, arr.size() - 1);
```

</details>


<details>
  <summary>Python</summary>
  TODO:...
</details>

Quick sort е по-бърз от Merge sort за малки масиви. Има по-малка константа и изисква по-малко допълнителна памет.

## Counting sort (Сортиране с броене)

| Counting sort                | n = input size, k = max number |
| ---------------------------- | ------------------------------ |
| Time complexity (Worst case) | $$\mathcal{O}(n + k)$$         |
| Time complexity (Best case)  | $$\mathcal{O}(n)$$             |
| Space complexity             | $$\mathcal{O}(n + k)$$         |
| Adaptive                     | No                             |
| Stable                       | Yes                            |
| Local                        | No                             |
| Online                       | No                             |
| In-place                     | No                             |
| Parallel                     | Yes                            |
| External                     | Yes                            |

Идея: Не използва директни сравнения. Заделя се масив с големина всички възможни стойности (*K*). Линейно се обхожда първоначалния масив и се броят срещанията на стойностите.
Броят срещания се преобразуват в индекси, показващи до къде в сортирания масив ще достига всяка група-елементи. Чрез обхождане в обратна посока на оригиналния масив всеки елемент се поставя на съответния последен индекс за групата. Последният индекс за групата се намаля. Поставянето в сортиран ред се случва в нов масив. Накрая сортираните стойности от новия масив се презаписват в стария.


### Имплементация

<details>
  <summary>C++</summary>

```c++
void countingSort(std::vector<int>& arr) {
    int N = arr.size();
    
    if (N == 0)
        return;

    int K = *max_element(arr.begin(), arr.end()) + 1;

    std::vector<int> output(N);
    std::vector<int> count(K);

    for (int i = 0; i < N; ++i) 
        count[arr[i]]++;

    for (int i = 1; i < K; ++i)
        count[i] += count[i - 1];

    for (int i = N - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < N; ++i)
        arr[i] = output[i];
}
```

</details>


<details>
  <summary>Python</summary>
  TODO:...
</details>

Counting sort, когато е възможно ползването му, позволява сортиране с линейна сложност.

### Обобщение на бързите алгоритми:

|              | Merge sort | Quick sort         | Counting sort |
| ------------ | ---------- | ------------------ | ------------- |
| Best case    | *O(NlogN)* | *O(NlogN)*         | *O(N + K)*    |
| Average Case | *O(NlogN)* | *O(NlogN)*         | *O(N + K)*    |
| Worst Case   | *O(NlogN)* | *O(N<sup>2</sup>)* | *O(N + K)*    |
| Памет (Average Case)        | *O(N)*     | *O(logN)*             | *O(N + K)*    |
| Памет (Worst Case)       | *O(N)*     | *O(N)*             | *O(N + K)*    |
| Стабилен     | да         | не                 | да            |


## Функции от стандартните библиотеки


<details>
  <summary>C++</summary>

Полезни функции от stl, които ще използваме - [тук](./stl_funcs.md)

</details>

<details>
  <summary>Python</summary>
	
</details>

## Задачи

**Note:** Сложността на решенията ви ще зависят от имплементацията на сортировка, която използвате. Тъй като ще използвате имплементации от стандартната библиотека на езика ви, ще трябва да прочетете в документацията каква е сложността.

### Easy

- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [Find the Difference](https://leetcode.com/problems/find-the-difference/)
- [Squares of a Sorted array](https://leetcode.com/problems/squares-of-a-sorted-array/)
- [Intersection of two arrays 2](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

### Medium
- [K-th largest element in an array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
	- [Quick select algorithm](https://en.wikipedia.org/wiki/Quickselect)
- [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
- [Sort characters by frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
- [Sort the students by their kth score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/)
- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

### Hard
...

## Бонус

- някои имплементации на std::sort - https://en.wikipedia.org/wiki/Introsort
- Bucket sort
- Radix sort
- Задача:
  - [Ред в хаоса](https://www.hackerrank.com/contests/sda-test1-2022-2023/challenges/challenge-3676/problem)
  - https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
