# Упражнение 3

# Алгоритми за сортиране

## Днес ще разгледаме

- бавни алгоритми за сортиране
  - Bubble sort
  - Selection sort
  - Insertion sort
- бързи алгоритми за сортиране
  - Merge sort
  - Quick sort 
- други
  - Counting sort

## Бавни алгоритми за сортиране

## Bubble sort (Метод на мехурчето)

- *O(N<sup>2</sup>)* сложност по време
- *О(1)* сложност по памет
- *N * (N - 1) / 2* брой размени в най-лошия случай
- [стабилен](https://en.wikipedia.org/wiki/Category:Stable_sorts) сортиращ алгоритъм

След всяка итерация на *i*, най-големият елемент "изплува" чрез последователни размени на съседни елементи.

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

## Selection sort (Метод на пряката селекция)

- *O(N<sup>2</sup>)* сложност по време
- *О(1)* сложност по памет
- *N - 1* брой размени в най-лошия случай
- **не** е стабилен сортиращ алгоритъм

Търси се индексът на най-малкия елемент на всяка итерация. След това се разменя с текущия.

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
        
        std::swap(arr[min_index], arr[i]);
    }
}
```

Предпочитан пред Bubble sort поради по-малкото на брой размени, но за сметка на това не е стабилен. 

## Insertion sort (Метод на картоиграча)

- *O(N<sup>2</sup>)* сложност по време
- *О(1)* сложност по памет
- стабилен сортиращ алгоритъм

Всеки елемент се тегли като карта с гърба надолу. Търси се мястото му в ръката, като се изместват по-големите стойности с една позиция надясно.

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

[Подходящ](https://www.toptal.com/developers/sorting-algorithms) за малки масиви, и почти сортирани масиви. Това се дължи на ранното приключване на вътрешния цикъл при правилно поставено число (Best case сложността на алгоритъма е *O(N)*).

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

- *O(NlogN)* сложност по време
- *О(N)* сложност по памет
- подходът *разделяй и владей*
- стабилен сортиращ алгоритъм

Масивът се разделя на две половинки подмасиви. Всяка половинка продължава да се разделя. Процесът спира при достигане на масив с един елемент, който сам по-себе си е сортиран.
  
```c++
void mergeSort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        int middle = arr.size() / 2;

        std::vector<int> left_arr(arr.begin(), arr.begin() + middle);
        std::vector<int> right_arr(arr.begin() + middle, arr.end());

        mergeSort(left_arr);
        mergeSort(right_arr);

        merge(arr, left_arr, right_arr);
    }
}
```

Тогава започва обратния процес по сливане на подмасивите. Две вече сортирани половинки се сливат в по-голям подмасив, като се "придърпват" в правилния ред елементи ту от левия, ту от десния.

```c++
void merge(std::vector<int>& arr, std::vector<int>& left_arr, std::vector<int>& right_arr) {
    int left_size = left_arr.size();
    int right_size = right_arr.size();
    
    int index = 0;
    int left = 0;
    int right = 0;

    while (left < left_size && right < right_size) {
        if (left_arr[left] <= right_arr[right]) {
            arr[index++] = left_arr[left++];
        } else {
            arr[index++] = right_arr[right++];
        }
    }

    while (left < left_size) {
        arr[index++] = left_arr[left++];
    }

    while (right < right_size) {
        arr[index++] = right_arr[right++];
    }
}
```

Merge sort гарантира енлог сложност дори в най-лошия случай, за разлика от Quick sort.

## Quick sort (Бързо сортиране)

- *O(N<sup>2</sup>)* сложност по време в най-лошия случай
- *O(NlogN)* сложност по време в средния случай
- *О(logN)* сложност по [памет*](https://en.wikipedia.org/wiki/Quicksort#Space_complexity)
- **не е** стабилен сортиращ алгоритъм

Избира се елемент от масива, по-който ще се извършва подредбата. 
Чрез последователни промени, всички по-малки от избрания остават в лявата част на масива, а по-големите - в дясната. Избраният елемент се сменя с първия по-голям от него, за да се позиционира между двете групи.

```c++
int partition(std::vector<int>& arr, int low, int high) {
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
```

Спрямо индексът на избрания елемент, масивът се дели на два подмасива. Във всеки от тях се повтарят действията по-избиране и сортиране на групите от по-малки и по-големи числа.

```c++
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

Quick sort е по-бърз от Merge sort за малки масиви. Има по-малка константа и изисква по-малко допълнителна памет.

## Counting sort (Сортиране с броене)

- *O(N + К)* сложност по време
- *О(N + K)* сложност по памет
- стабилен сортиращ алгоритъм

Не използва директни сравнения. Заделя се масив с големина всички възможни стойности (*K*). Линейно се обхожда първоначалния масив и се броят срещанията на стойностите.

Броят срещания се преобразуват в индекси, показващи до къде в сортирания масив ще достига всяка група-елементи. Чрез обхождане в обратна посока на оригиналния масив всеки елемент се поставя на съответния последен индекс за групата. Последният индекс за групата се намаля. Поставянето в сортиран ред се случва в нов масив. Накрая сортираните стойности от новия масив се презаписват в стария.

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

Counting sort, когато е възможно ползването му, позволява сортиране с линейна сложност.

### Обобщение на бързите алгоритми:

|          | Merge sort | Quick sort         | Counting sort |
| -------- | ---------- | ------------------ | ------------- |
| BC       | *O(NlogN)* | *O(NlogN)*         | *O(N + K)*    |
| AC       | *O(NlogN)* | *O(NlogN)*         | *O(N + K)*    |
| WC       | *O(NlogN)* | *O(N<sup>2</sup>)* | *O(N + K)*    |
| Памет    | *O(N)*     | *O(logN)*          | *O(N + K)*    |
| Стабилен | да         | не                 | да            |

## Задачи за упражнение (в LeetCode)

- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [Find the Difference](https://leetcode.com/problems/find-the-difference/)
