# Упражнение 2

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

```python
arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
N = len(arr)

for i in range(N - 1):
    for j in range(0, N - 1 - i):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

## Selection sort (Метод на пряката селекция)

- *O(N<sup>2</sup>)* сложност по време
- *О(1)* сложност по памет
- *N - 1* брой размени в най-лошия случай
- **не** е стабилен сортиращ алгоритъм

Търси се индексът на най-малкия елемент на всяка итерация. След това се разменя с текущия.

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

Предпочитан пред Bubble sort поради по-малкото на брой размени, но за сметка на това не е стабилен. 

## Insertion sort (Метод на картоиграча)

- *O(N<sup>2</sup>)* сложност по време
- *О(1)* сложност по памет
- стабилен сортиращ алгоритъм

Всеки елемент се тегли като карта с гърба надолу. Търси се мястото му в ръката, като се изместват по-големите стойности с една позиция надясно.

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

Тогава започва обратния процес по сливане на подмасивите. Две вече сортирани половинки се сливат в по-голям подмасив, като се "придърпват" в правилния ред елементи ту от левия, ту от десния.

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

Merge sort гарантира енлог сложност дори в най-лошия случай, за разлика от Quick sort.

## Quick sort (Бързо сортиране)

- *O(N<sup>2</sup>)* сложност по време в най-лошия случай
- *O(NlogN)* сложност по време в средния случай
- *О(logN)* сложност по [памет*](https://en.wikipedia.org/wiki/Quicksort#Space_complexity)
- **не е** стабилен сортиращ алгоритъм

Избира се елемент от масива, по-който ще се извършва подредбата. 
Чрез последователни промени, всички по-малки от избрания остават в лявата част на масива, а по-големите - в дясната. Избраният елемент се сменя с първия по-голям от него, за да се позиционира между двете групи.

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

Спрямо индексът на избрания елемент, масивът се дели на два подмасива. Във всеки от тях се повтарят действията по-избиране и сортиране на групите от по-малки и по-големи числа.

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

Quick sort е по-бърз от Merge sort за малки масиви. Има по-малка константа и изисква по-малко допълнителна памет.

## Counting sort (Сортиране с броене)

- *O(N + К)* сложност по време
- *О(N + K)* сложност по памет
- стабилен сортиращ алгоритъм

Не използва директни сравнения. Заделя се масив с големина всички възможни стойности (*K*). Линейно се обхожда първоначалния масив и се броят срещанията на стойностите.

Броят срещания се преобразуват в индекси, показващи до къде в сортирания масив ще достига всяка група-елементи. Чрез обхождане в обратна посока на оригиналния масив всеки елемент се поставя на съответния последен индекс за групата. Последният индекс за групата се намаля. Поставянето в сортиран ред се случва в нов масив. Накрая сортираните стойности от новия масив се презаписват в стария.

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

print(arr) # [1, 2, 3, 4, 5, 6, 7, 8, 9]
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
- [Squares of a Sorted array](https://leetcode.com/problems/squares-of-a-sorted-array/)
- [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)