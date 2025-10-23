# Упражнение 3

# Алгоритми за търсене

## Днес ще разгледаме

- Linear search
- Binary search
    - Lower bound
    - Upper bound
    - Binary search по отговора
- Ternary search
- Jump search

## Linear search (Линейно търсене)

- работи за сортирани **и** несортирани данни
- *O(N)* сложност по време
- подходящ за малък брой заявки при несортирани данни

Всеки елемент от масива се сравнява последователно с търсения.


<details>
  <summary>C++</summary>
	
```c++
int linear_search(const vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
```

</details>


<details>
  <summary>Python</summary>

```python
def linear_search(arr, X):
    for i in range(len(arr)):
        if arr[i] == X:
            return i
    
    return -1

arr = [9, 4, 3, 2, 6, 7, 1, 8, 5]
X = 6

print(linear_search(arr, X)) # 4
```

</details>

## Binary search (Двоично търсене)

- работи **само** за сортирани данни
- *O(logN)* сложност по време
- подходящ за много наброй заявки
- нуждае се от броя на данните (N)

Сравнява се средния елемент с търсения. Ако търсеният елемент е по-малък, разглежда се масива отляво на средния елемент. Ако търсеният е по-голям, разглежда се масива отдясно на средния. Стъпките се повтарят до намиране на елемента.

<details>
	<summary><b>Въпрос:</b> Колко заявки трябва да имам, че да си заслужава да сортирам масивът и после да използвам binary search вместо вместо linear?</summary>

#### 1. Проблем
Искаме да търсим многократно в **несортиран масив** от `n` елемента:
- Всяко query с **linear search** = O(n)
- Ако **сортираме веднъж** (O(n log n)), после всяко търсене е **binary search**: O(log n)

#### 2. Нека имаме `k` заявки за търсене.

- **Ако НЕ сортираш, всяка заявка:**
  - O(n)
  - Общо време: **T₁ = k * n**
- **Ако сортираш веднъж, после binary search:**
  - O(n log n) (сортиране) + O(log n) (всяко търсене)
  - Общо време: **T₂ = n log n + k * log n**


#### 3. Кога е по-изгодно да сортираш?

Искаме **T₂ < T₁:** т.е. **n log n + k log n < k n**
<br />
Определяме при кое k това е изпълнено:

```
n * log n + k * log n < k * n
n * log n < k * (n - log n)
k > n * log n / (n - log n)

// За голямо `n`, може да пренебрегнем `log n` спрямо `n`:
// следователно

k > log n
```

#### 4. Заключение

- **Ако търсиш броя на запитвания `k > log n`**, си струва да сортираш масива и да използваш двоично търсене.
- Ако са **по-малко от log n**, линейното търсене често е по-изгодно.

</details>

---

### Итеративна имплементация

<details>
  <summary>C++</summary>
	
```c++
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2; // !!!
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
```

</details>

<details>
  <summary>Python</summary>

```python
def binary_search(arr, X):
    left = 0
    right = len(arr) - 1

    Xi = 0

    while left <= right:
        mid = left + (right - left) // 2

        if X <= arr[mid]:
            right = mid - 1
            Xi = mid
        else:
            left = mid + 1

    return Xi

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90]
X = 60

Xi = binary_search(arr, X)
print(Xi) # 5
```

</details>

На C++, при пресмятане на средния индекс трябва да се внимава за overflow, ако бъде пресмятан като **(left + right) / 2**.

---

### Рекурсивна имплементация

- *O(logN)* сложност по памет на рекурсивната имплементация

<details>
  <summary>C++</summary>

```c++
int binarySearchRecursive(const vector<int> &arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchRecursive(arr, l, mid - 1, x);
        return binarySearchRecursive(arr, mid + 1, r, x);
    }
    return -1;
}
```
	
</details>


<details>
  <summary>Python</summary>

```python
def binary_search_recursive(arr, X, left, right):
    if left <= right:
        mid = left + (right - left) // 2

        if X == arr[mid]:
            return mid
        elif X < arr[mid]:
            return binary_search_recursive(arr, X, left, mid - 1)
        return binary_search_recursive(arr, X, mid + 1, right)
    return -1
```

</details>

---

### Lower bound
- връща първият елемент в масива не по-малък от x.

<details>
  <summary>C++</summary>

```c++
int lowerBound(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left; // If left == nums.size(), target is greater than all elements
}
```

</details>

<details>
  <summary>Python</summary>

	TODO...
</details>

---

### Upper bound
- връща първият елемент в масива, който е по-голям от x.

<details>
  <summary>C++</summary>

```c++
int upperBound(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

</details>

<details>
  <summary>Python</summary>
	TODO...
</details>

---

**В следния snippet са използвани имплементации от стандартната библиотека на на binary_search, lower_bound, upper_bound.** 

Изпробвайте следния code snippet с target - 0, 5, 6, 11. При target 11 връща v.end() на C++, а на Python - len(v).

<details>
  <summary>C++</summary>

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 6, 7, 8, 9 };
	int target = 0;

	// https://en.cppreference.com/w/cpp/algorithm/binary_search.html
	std::cout << (std::binary_search(v.begin(), v.end(), target)) << std::endl;

	// https://en.cppreference.com/w/cpp/algorithm/lower_bound.html
	auto lbIter = std::lower_bound(v.begin(), v.end(), target);
	if (lbIter != v.end()) {
		std::cout << *lbIter << std::endl;
	}

	// https://en.cppreference.com/w/cpp/algorithm/upper_bound.html
	auto ubIter = std::upper_bound(v.begin(), v.end(), target);
	if (ubIter != v.end()) {
		std::cout << *ubIter << std::endl;
	}
}
```

</details>

<details>
  <summary>Python</summary>
  
```python
import bisect

v = [1, 2, 3, 4, 6, 7, 8, 9]
targets = [0, 5, 6, 11]

for target in targets:
    print(bisect.bisect_left(v, target))
    print(bisect.bisect_right(v, target))
    print()
```

</details>


#### Задача
Намерете броя срещания на едно число в сортиран масив

---

### Binary search по отговора (Binary Search on answer)
Binary Search on Answer е техника за решаване на задачи, в които търсим оптимална стойност (най-малка или най-голяма), която отговаря на дадено условие. Тя се използва, когато можем да проверим дали дадена стойност е валидно решение и отговорът се намира в определен диапазон. В този случай, вместо да търсим конкретен елемент, търсим минимална или максимална граница на възможното решение.

Критерии дали мога да си реша задачата с тази техника?
- Можем да проверим дали дадена стойност е решение на задачата
- Възможните стойности са ограничени отгоре и отдолу

#### Задачи
Sqrt(X) и Puncakes

## Ternary search (Тристранно търсене)

- работи за сортирани и параболични данни
- *O(log<sub>3</sub>N)* сложност по време
- подходящ за [намиране](https://cp-algorithms.com/num_methods/ternary_search.html) на единствен максимум/ минимум на функция

Сравняват се двата средни елементи с търсения. Ако търсеният елемент е по-малък от първия среден, разглежда се масива отляво на първия среден елемент. Ако търсеният е между двата средни, разглежда се втората третина от масива. Ако търсеният е по-голям от втория среден елемент - разглежда се масива отдясно на втория среден елемент. Отново стъпките се повтарят до намиране на елемента.

<details>
  <summary>C++</summary>
  
```c++
int ternarySearch(const vector<int> &arr, int l, int r, int x) {
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == x)
            return mid1;
        if (arr[mid2] == x)
            return mid2;
        if (x < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (x > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}
```

</details>

<details>
  <summary>Python</summary>
  
```python
def ternarySearch(arr, key, l, r):
    if r >= l:
        mid1 = l + (r - l) //3
        mid2 = r - (r - l) //3 

        if arr[mid1] == key:
            return mid1
         
        if arr[mid2] == key:
            return mid2

        if key < arr[mid1]:
            return ternarySearch(arr, key, l, mid1 - 1)
        elif key > arr[mid2]:
            return ternarySearch(arr, key, mid2 + 1, r)
        else:
            return ternarySearch(arr, key, mid1 + 1, mid2 - 1)
    return -1

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90]
X = 60

Xi = ternarySearch(arr, X, 0, len(arr) - 1)
print(Xi) # 5
```


</details>

</br>
<details>
  <summary><b>Въпрос:</b> Кой алгоритъм е по-оптимален в общия случай BinarySearch или TernarySearch?</summary>

**Отговор:** BinarySearch, понеже прави по-малко сравнения.

https://www.geeksforgeeks.org/binary-search-preferred-ternary-search/
</details>

**Бонус**: Защо Merge sort дели масива на две части? Защо не на повече?

## Jump search (Търсене със скоци)

- работи **само** за сортирани данни
- [оптималният скок](https://www.wolframalpha.com/input?i=Argmin+of+f%28x%29+%3D+n%2Fx+%2B+x%2C+x+%3E+0%2C+n+%3E+0+for+x) е *sqrt(N)* (за минимален общ брой сравнения)
- *O(sqrt(N))* сложност по време
- [по-бавен](https://www.symbolab.com/solver/limit-calculator/%5Clim_%7Bx%5Cto%5Cinfty%7D%5Cleft(%5Cfrac%7Blnx%7D%7B%5Csqrt%7Bx%7D%7D%5Cright)?or=input) от Binary search ([*O(log(N))* < *O(sqrt(N))* < *O(N)*](https://www.wolframalpha.com/input?i=plot+log%28n%29%2C+sqrt%28n%29+from+1+to+1000))
- подходящ когато стъпките назад в масив ни струват скъпо

Търсеният елемент се сравнява последователно с елементи на позиции, кратни на стъпката (корен от N). Когато търсеният елемент стане по-малък от елемента на K-та стъпка, се извършва линейно търсене в интервала (K-1)-ва стъпка до K-та стъпка.

Jump search прави 1 връщане назад в масива, докато при Binary search има най-много *logN* връщания. При нужда от ограничаване на връщанията Jump search е предпочитан пред Binary search въпреки по-голямата сложност по време. Точно поради тази причина не се извършва двоично търсене в намерения интервал.

<details>
  <summary>C++</summary>

```c++
int jump_search(const vector<int> &arr, int x) {
    int len = arr.size();
    int jump = sqrt(len);
    int start = 0, end = start + jump;

    while (end < len && arr[end] <= x) {
        start = end;
        end += jump;
        if (end > len - 1)
            end = len;
    }

	// we don't do binary here because it requires back steps
    for (int i = start; i < end; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```
</details>

<details>
  <summary>Python</summary>
  

```python
import math

def jumpSearch(arr, X):
    N = len(arr)
    block_size = int(math.sqrt(N))

    step = block_size
    prev = 0
    while arr[min(step, N) - 1] < X:
        prev = step
        step += block_size
        if prev >= N:
            return -1

    while arr[prev] < X:
        prev += 1

        if prev == min(step, N):
            return -1
     
    if arr[prev] == X:
        return prev
     
    return -1

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90]
X = 50

Xi = jumpSearch(arr, X)
print(Xi) # 4
```

</details>

<details>
	<summary>Математиката зад оптималния скок</summary>

#### 1. Означения
- Масивът има **`n`** елемента.
- Размерът на скока е **`m`**.

#### 2. Брой стъпки при Jump Search
- **Скокове:** Минаваме масива през всеки `m`-ти елемент: индекси 0, m, 2m, 3m, ...
  - Брой скокове: **`n / m`**
- **Линейно търсене:** След последния скок — търсим линейно в блока (до `m` елемента).


#### 3. Обща формула за стъпките
T(m) = брой скокове + брой проверки в блока

T(m) = n/m + m

#### 4. Оптимизация на T(m)

Търсим минимум на `T(m)` спрямо `m`:

1. Вземаме производната и я приравняваме на 0:

    ```
    dT/dm = -n/m^2 + 1 = 0
    ```

2. Решаваме за `m`:

    ```
    n/m^2 = 1
    m^2 = n
    m = √n
    ```

#### 5. Минимален брой стъпки

Заместваме `m = √n` във формулата:

T(√n) = n/√n + √n = √n + √n = 2√n

#### 6. Заключение

Jump Search е **най-ефикасен при скок m = √n** и има сложност **O(√n)**.

</details>


## Задачи за упражнение

### Easy
- [Binary Search](https://leetcode.com/problems/binary-search/)
- [Sqrt(x)](https://leetcode.com/problems/sqrtx/)
- [First Bad Version](https://leetcode.com/problems/first-bad-version)
- [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

### Medium
- [Puncakes](https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/problem)
- [Perfect Printer](https://www.hackerrank.com/contests/sda-homework-3/challenges/challenge-2674)
- [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array)
- [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix)
    - 3 решения
- [Find Minimum in rotated sorted array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

### Hard
...

# Бонус материал

## Exponential search (Експоненциално търсене)

- работи **само** за сортирани данни
- [*O(logi)*](https://en.wikipedia.org/wiki/Exponential_search#Performance) сложност по време, където *i* е позицията на числото
- подходящ при търсене на елементи, намиращи се в началото на масива (*i < N*)
- подходяш, когато не знаем големината на входните данни, в които търсим (например поток)

Търсеният елемент се сравнява последователно с елементи на позиции, степени на двойката (2<sup>K</sup>). Когато търсеният елемент стане по-малък от елемента на К-та степен, се извършва двоично търсене в интервала 2<sup>K-1</sup>-ва позиция до 2<sup>K</sup>-та позиция.

<details>
  <summary>C++</summary>

```c++
int exponentialSearch(const vector<int>& arr, int X) {
    int N = arr.size();

    if (arr[0] == X)
        return 0;

    int i = 1;
    while (i < N && arr[i] <= X)
        i *= 2;

    int left = i / 2;
    int right = min(i, N - 1);

    return binarySearch(arr, left, right, X);
}
```
</details>

<details>
  <summary>Python</summary>
  
```python
def exponential_search(arr, X):
    N = len(arr)

    i = 1
    while i < N and arr[i] <= X:
        i = i * 2

    left = i // 2
    right = min(i, N-1)
     
    return binary_search(arr, X, left, right)

arr = [10, 20, 30, 40, 50, 60, 70, 80, 90]
X = 60

Xi = exponential_search(arr, X)
print(Xi) # 5
```

</details>

</details>

## Interpolation Search
- https://en.wikipedia.org/wiki/Interpolation_search

## Бонус на бонуса: Eytzinger binary search
- Eytzinger binary search - https://algorithmica.org/en/eytzinger
    - Как може да бъде оптимизиран binary search при много заявки в големи масиви?
	- Branch predictor - https://en.wikipedia.org/wiki/Branch_predictor

