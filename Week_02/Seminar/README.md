# Упражнение 2

# Алгоритми за сортиране

- Тестова среда, в която да изпробвате някои алгоритми - [hackerrank contest](https://www.hackerrank.com/contests/algorithms-implementation-test-environment/challenges)
- Сайт с визуализация на алгоритмите - [VisuAlgo](https://visualgo.net/en/sorting)
- Опростена версия на README-то за Python: [линк](./Python_simple_README.md)

## Характеристики на алгоритмите за сортиране

Освен сложността по време и по памет, алгоритмите за сортиране имат и следните характеристики:

- **Stability** - Един алгоритъм е стабилен, ако след сортировка, два равни елемента са в същата последователност, както преди масивът да бъде сортиран.
  - Пример - Вход: $$1, 2, 3_a, 8, 5, 3_b$$. Тук $$3_a$$ и $$3_b$$ са просто две числа, но ги маркираме, за да видим как са подредени в резултата.
  - Stable sort output: $$1,2,3_a,3_b,5,8$$
  - Unstable sort output: $$1,2,3_b,3_a,5,8$$ - поведението не е детерминистично (тоест понякога може да е $$3_a, 3_b$$ друг път $$3_b, 3_a$$ в зависимост от алгоритъма и входа)

- **In-place** - Показва дали алгоритъмът работи директно върху подадените данни, без да заделя допълнителна памет, пропорционална на входа. Следователно използва константна памет.
- **Adaptivity** - Показва дали алгоритъмът работи по-бързо за почти сортирани масиви. Ако алгоритъмът е неадаптивен, той има едно и също време за изпълнение, независимо дали входът е несортиран, или почти сортиран.

- **Number of comparisons** - Показва колко пъти два елемента биват сравнявани помежду си. Много често това съвпада със сложността на алгоритъма по време. Минималната стойност за алгоритми, които използват сравнения, е $$\mathcal{O}(n \times log(n))$$ (виж бонуса по-долу).

- **Number of swaps** - Показва колко пъти два различни елемента биват разменени в паметта. Не винаги определя сложността на алгоритъма, но може да повлияе на бързината му при големи данни и при размяна на големи обекти.

- **Locality** - Показва дали алгоритъмът се възползва от кеша на процесора, за да ускори своето изпълнение. За целта данните трябва да се достъпват последователно в паметта.

Сравнение на нивата на паметта по капацитет и по брой процесорни цикли, нужни за достъп до тях:

| Memory hierarchy | CPU cycles | size   |
| ---------------- | ---------- | ------ |
| HDD              | 500 000    | 1 TB   |
| RAM              | 100        | 4 GB   |
| L2 cache         | 10         | 512 KB |
| L1 cache         | 1          | 32 KB  |

---

<details>
  <summary><b>Бонус: Locality in depth</b></summary>

- Дефиниране
  - свойството на процесора, при което той прехвърля в своя кеш често използвани или съседни данни, за да ги достъпва по-бързо при следващи операции.
  - CPU cache - малка, бърза памет в процесора, която съхранява често използвани данни и инструкции, за да ускори достъпа до тях и да подобри производителността.
    - instruction cache - съхранява често използвани машинни инструкции.
    - data cache - съхранява често използвани данни от програмите.
  - Основни видове:
    - Temporal locality - ако даден елемент от паметта е бил достъпен наскоро, има голяма вероятност да бъде достъпен отново скоро
    - Spacial locality - ако даден елемент от паметта бъде достъпен, има голяма вероятност скоро да бъдат достъпени и елементи, намиращи се близо до него по адрес.
- Сравнение на обхождане на матрица (статична и динамична) по редове срещу обхождане колони
  - обхождането по редове е по-ефективно тъй като елементите в паметта са подредени по редове, което води до по-добро използване на кеша.
- **Бонус:**
  - <https://www.geeksforgeeks.org/locality-of-reference-and-cache-operation-in-cache-memory/>
  - [CPU cache](https://en.wikipedia.org/wiki/CPU_cache) и [Locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)

</details>

<details>
  <summary><b>Бонус: Защо долната граница за сортиране чрез сравнения е O(n log n)?</b></summary>

Доказателство с дърво на решенията.

Всеки алгоритъм, който сортира чрез сравнения, може да се представи като **двоично дърво**:

- всеки вътрешен възел е едно сравнение `a[i] < a[j]?`;
- двата клона са двата възможни отговора;
- всяко листо е крайният резултат, тоест конкретна наредба на елементите.

Пример за $$n = 3$$ (елементи $$a, b, c$$):

```text
                a<b?
              /      \
            да        не
           b<c?       a<c?
          /    \      /    \
      a,b,c   a<c?  b,a,c   b<c?
             /   \          /   \
         a,c,b  c,a,b    b,c,a  c,b,a
```

Листата са всички възможни наредби на елементите - $$n!$$ на брой. Броят сравнения в най-лошия случай е височината на дървото, която е поне $$\log_2(n!)$$ (двоично дърво с височина $$h$$ има най-много $$2^h$$ листа). По формулата на Стирлинг (от ДИС) $$\log_2(n!) = \mathcal{O}(n \log n)$$.

</details>

## Ще разгледаме

- [бавни алгоритми за сортиране](#бавни-алгоритми-за-сортиране)
  - [Bubble sort](#bubble-sort-метод-на-мехурчето)
  - [Selection sort](#selection-sort-метод-на-пряката-селекция)
  - [Insertion sort](#insertion-sort-метод-на-картоиграча)
- [бързи алгоритми за сортиране](#бързи-алгоритми-за-сортиране)
  - [Merge sort](#merge-sort-сортиране-със-сливане)
  - [Quick sort](#quick-sort-бързо-сортиране)
- други (алгоритми, които не използват сравнения)
  - [Counting sort](#counting-sort-сортиране-с-броене)

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
| In-place              | Yes                  |

- *N * (N - 1) / 2* брой размени в най-лошия случай. Кога се случва това?

Идея: След всяка итерация на *i* най-големият от оставащите елементи "изплува" в края чрез последователни размени на съседни елементи.

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

Има ли излишни итерации в тази имплементация и, ако да, как да ги намалим?

```c++
void optimizedBubbleSort(std::vector<int>& arr) {
    int lastSwappedIndex = arr.size() - 1;
    for (size_t i = 0; i < arr.size(); i++) {
        int currentSwappedIndex = 0; // what if we used -1?
        for (size_t j = 0; j < lastSwappedIndex; j++) {
            if (arr[j] > arr[j + 1]) {
                currentSwappedIndex = j;
                std::swap(arr[j], arr[j + 1]);
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

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(N - 1):
    for j in range(0, N - 1 - i):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

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
| In-place              | Yes                  |

Идея: На всяка итерация се търси индексът на най-малкия елемент в несортираната част. След това този елемент се разменя с първия елемент на несортираната част.

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

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(N - 1):
    min_index = i

    for j in range(i + 1, N):
        if arr[j] < arr[min_index]:
            min_index = j

    arr[min_index], arr[i] = arr[i], arr[min_index]

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

Предпочитан пред Bubble sort поради по-малкия брой размени, но за сметка на това не е стабилен.

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
| In-place              | Yes                  |

Идея: Елементите се вземат един по един, както картоиграч тегли карти. Всяка нова карта се вмъква на правилното място в ръката (сортираната част), като по-големите стойности се изместват с една позиция надясно.

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

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(1, N):
    key = arr[i]

    j = i - 1
    while j >= 0 and key < arr[j]:
        arr[j + 1] = arr[j]
        j -= 1

    arr[j + 1] = key

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

**Note:** Използваме отмествания, които са по-евтина операция от swap.

[Подходящ](https://www.toptal.com/developers/sorting-algorithms) за малки и почти сортирани масиви. Това се дължи на ранното приключване на вътрешния цикъл, когато елементът вече е на правилното място (best case сложността на алгоритъма е *O(N)*). Често се ползва в комбинация с други алгоритми.

Защо insertion sort е полезен за малки масиви?

- Има добра локалност (работи със съседни елементи).
- Няма рекурсивни извиквания - *O(1)* памет.
- Прави отмествания вместо размени.
- Адаптивен е - при почти сортирани данни работи почти линейно.

---

### Обобщение на бавните алгоритми

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
| In-place              | No                        |

- Използва подхода *разделяй и владей*.

Идея: Масивът се разделя на два подмасива (половини). Всяка половина продължава да се разделя. Процесът спира при достигане на масив с един елемент, който сам по себе си е сортиран. Тогава започва обратният процес - сливане на подмасивите. Две вече сортирани половинки се сливат в по-голям подмасив, като се "придърпват" в правилния ред елементи ту от левия, ту от десния.

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
  
```python
def merge_sort(arr):
    if len(arr) > 1:
        middle = len(arr) // 2

        left_arr = arr[:middle]
        right_arr = arr[middle:]

        merge_sort(left_arr)
        merge_sort(right_arr)

        merge(arr, left_arr, right_arr)
```

```python
def merge(arr, left_arr, right_arr):
    index = left = right = 0
    left_size = len(left_arr)
    right_size = len(right_arr)

    while left < left_size and right < right_size:
        if left_arr[left] <= right_arr[right]:
            arr[index] = left_arr[left] 
            left += 1
        else:
            arr[index] = right_arr[right] 
            right += 1
        index += 1

    while left < left_size:
        arr[index] = left_arr[left]
        index += 1
        left += 1

    while right < right_size:
        arr[index] = right_arr[right]
        index += 1
        right += 1
```

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]

merge_sort(arr)
print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

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
| In-place                        | Yes                                      |

- *O(logN)* сложност по [памет в средния случай](https://en.wikipedia.org/wiki/Quicksort#Space_complexity)!

Идея: Избира се елемент от масива (pivot), спрямо който ще се извършва подредбата. Чрез последователни размени всички по-малки от избрания елемент се преместват в лявата част на масива, а по-големите - в дясната. Избраният елемент се разменя с първия по-голям от него, за да се позиционира между двете групи. Спрямо индекса на избрания елемент масивът се дели на два подмасива. Във всеки от тях се повтарят действията по избиране на елемент и разделяне на по-малки и по-големи числа.

### Имплементация

<details>
  <summary>C++</summary>
  
```c++
int partition(std::vector<int>& arr, int low, int high) {
    int initialPivotIndex = rand() % (high - low + 1) + low; // select random index in the range [low, high] for pivot
    std::swap(arr[initialPivotIndex], arr[high]); // put the pivot at the end

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
  
```python
def partition(arr, low, high):
    pivot = arr[high] # The last element is chosen as the pivot.
    i = low

    for j in range(low, high):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1

    arr[i], arr[high] = arr[high], arr[i]
    
    return i
```

```python
def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)
```

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

quick_sort(arr, 0, N - 1)
print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

На практика Quick sort често е по-бърз от Merge sort, защото има по-малка константа и по-добра локалност. Освен това изисква по-малко допълнителна памет.

## Counting sort (Сортиране с броене)

| Counting sort                | n = input size, k = max number |
| ---------------------------- | ------------------------------ |
| Time complexity (Worst case) | $$\mathcal{O}(n + k)$$         |
| Time complexity (Best case)  | $$\mathcal{O}(n)$$             |
| Space complexity             | $$\mathcal{O}(n + k)$$         |
| Adaptive                     | No                             |
| Stable                       | Yes                            |
| Local                        | No                             |
| In-place                     | No                             |

Идея: Не използва директни сравнения. Заделя се масив с размер, равен на броя на възможните стойности (*K*). Линейно се обхожда първоначалният масив и се броят срещанията на стойностите.
Броят срещания се преобразува в индекси, показващи докъде в сортирания масив ще достига всяка група елементи. Чрез обхождане на оригиналния масив в обратна посока (за да е стабилен алгоритъмът) всеки елемент се поставя на последния свободен индекс за своята група. След това този индекс се намалява. Поставянето в сортиран ред се случва в нов масив. Накрая сортираните стойности от новия масив се презаписват в стария.

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

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]

N = len(arr)
K = max(arr) + 1

output = [0] * N
count = [0] * K

for i in range(N):
    count[arr[i]] += 1

for i in range(1, K):
    count[i] += count[i - 1]

for i in reversed(range(N)):
    output[count[arr[i]] - 1] = arr[i]
    count[arr[i]] -= 1

for i in range(N):
    arr[i] = output[i]

print(arr)  # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

</details>

Counting sort, когато е възможно ползването му, позволява сортиране с линейна сложност.

### Обобщение на бързите алгоритми

|                      | Merge sort | Quick sort         | Counting sort |
| -------------------- | ---------- | ------------------ | ------------- |
| Best case            | *O(NlogN)* | *O(NlogN)*         | *O(N + K)*    |
| Average Case         | *O(NlogN)* | *O(NlogN)*         | *O(N + K)*    |
| Worst Case           | *O(NlogN)* | *O(N<sup>2</sup>)* | *O(N + K)*    |
| Памет (Average Case) | *O(N)*     | *O(logN)*          | *O(N + K)*    |
| Памет (Worst Case)   | *O(N)*     | *O(N)*             | *O(N + K)*    |
| Стабилен             | да         | не                 | да            |

## Функции от стандартните библиотеки

<details>
  <summary>C++</summary>

Полезни функции от STL, които ще използваме - [тук](./stl_funcs.md).

</details>

<details>
  <summary>Python</summary>

- Сортиране с lambda функция

  ```python
  nums = [5, 2, 9, 1]
  nums.sort(key=lambda x: -x)
  print(nums)  # [9, 5, 2, 1]
  ```

- Сортиране с custom comparator

  ```python
  from functools import cmp_to_key
  
  nums = [5, 2, 9, 1]
  nums.sort(key=cmp_to_key(lambda a, b: a - b))
  print(nums)  # [1, 2, 5, 9]
  ```

</details>

## Задачи

**Note:** Сложността на решенията ви ще зависи от имплементацията на сортиране, която използвате. Тъй като ще използвате имплементации от стандартната библиотека на езика си, ще трябва да проверите в документацията каква е сложността им.

### Easy

- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [Find the Difference](https://leetcode.com/problems/find-the-difference/)
- [Squares of a Sorted array](https://leetcode.com/problems/squares-of-a-sorted-array/)
- [Intersection of two arrays 2](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
- [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
- [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)

### Medium

- [K-th largest element in an array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
 	- [Quick select algorithm](https://en.wikipedia.org/wiki/Quickselect)
- [Sort characters by frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
- [Sort the students by their kth score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/)
- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

## Бонус

<details>
  <summary><b>Други характеристики на алгоритмите за сортиране</b></summary>

- **Online** - Показва дали алгоритъмът се нуждае от всички входни данни, за да започне да сортира. Ако алгоритъмът е "online", той може да започне да сортира, получавайки данните си на части. Такива алгоритми са полезни за четене и обработване на данни от потоци. Обратното на "online" алгоритъм ще наричаме "offline".
- **External** - Показва дали алгоритъмът би работил върху данни, които не могат да се съберат в оперативната памет. Такива алгоритми са създадени, за да обработват големи обеми от данни, които в повечето случаи идват като потоци от данни с източник файл.
 	- Пример - merge sort
- **Parallel** - Показва дали алгоритъмът може да бъде изпълняван на няколко нишки едновременно с цел намаляване на времето за изпълнение.

|                | Online | External | Parallel |
| -------------- | ------ | -------- | -------- |
| Bubble sort    | No     | No       | No       |
| Selection sort | No     | No       | No       |
| Insertion sort | Yes    | No       | No       |
| Merge sort     | No     | Yes      | Yes      |
| Quick sort     | No     | No       | Yes      |
| Counting sort  | No     | Yes      | Yes      |

</details>

- C++: някои имплементации на std::sort - [wikipedia](https://en.wikipedia.org/wiki/Introsort#Pseudocode) & [medium article](https://11dhanushs.medium.com/intro-sort-a-brief-introduction-f06b419674de)

### Други алгоритми за сортиране

- [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)

### Задачи

- [Ред в хаоса - Hard](https://www.hackerrank.com/contests/sda-test1-2022-2023/challenges/challenge-3676/problem)
- [Earliest Possible Day of Full Bloom - Hard](https://leetcode.com/problems/earliest-possible-day-of-full-bloom/)
