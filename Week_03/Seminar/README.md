# Упражнение 3

# Алгоритми за търсене

## Днес ще разгледаме

- Linear search
- Binary search
    - Lower bound
    - Upper bound
- Ternary search
- Jump search
- Exponential search


## Linear search (Линейно търсене)

- работи за сортирани **и** несортирани данни
- *O(N)* сложност по време
- подходящ за малък брой заявки при несортирани данни

Всеки елемент от масива се сравнява последователно с търсения.

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

## Binary search (Двоично търсене)

- работи **само** за сортирани данни
- *O(logN)* сложност по време
- подходящ за много наброй заявки

Сравнява се средния елемент с търсения. Ако търсеният елемент е по-малък, разглежда се масива отляво на средния елемент. Ако търсеният е по-голям, разглежда се масива отдясно на средния. Стъпките се повтарят до намиране на елемента.

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

- При пресмятане на средния индекс трябва да се внимава за overflow, ако бъде пресмятан като **(left + right) / 2**.

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
- *O(logN)* сложност по памет на рекурсивната имплементация

### Lower bound
- връща първият елемент в масива не по-малък от x.

### Upper bound
- връща първият елемент в масива, който е по-голям от x.

Изпробвайте следния code snippet с target - 0, 5, 6, 11. (При 11 ви връща v.end())
```c++
int main() {
	std::vector<int> v = {1, 2, 3, 4, 6, 7, 8, 9};
	int target = 0;

	std::cout << (*std::lower_bound(v.begin(), v.end(), target)) << std::endl;
	std::cout << (*std::upper_bound(v.begin(), v.end(), target)) << std::endl;
}
```

#### Задача
Намерете броя срещания на едно число в сортиран масив

### Binary Search on answer - guess and check
Binary Search on Answer е техника за решаване на задачи, в които търсим оптимална стойност (най-малка или най-голяма), която отговаря на дадено условие. Тя се използва, когато можем да проверим дали дадена стойност е валидно решение и отговорът се намира в определен диапазон. В този случай, вместо да търсим конкретен елемент, търсим минимална или максимална граница на възможното решение.

## Ternary search (Тристранно търсене)

- работи за сортирани и параболични данни
- *O(log<sub>3</sub>N)* сложност по време
- подходящ за [намиране](https://cp-algorithms.com/num_methods/ternary_search.html) на единствен максимум/ минимум на функция

Сравняват се двата средни елементи с търсения. Ако търсеният елемент е по-малък от първия среден, разглежда се масива отляво на първия среден елемент. Ако търсеният е между двата средни, разглежда се втората третина от масива. Ако търсеният е по-голям от втория среден елемент - разглежда се масива отдясно на втория среден елемент. Отново стъпките се повтарят до намиране на елемента.

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


<details>
  <summary><b>Въпрос:</b> Кой алгоритъм е по-оптимален в общия случай BinarySearch или TernarySearch?</summary>

**Отговор:** BinarySearch, понеже прави по-малко сравнения.

https://www.geeksforgeeks.org/binary-search-preferred-ternary-search/
</details>

## Jump search (Търсене със скоци)

- работи **само** за сортирани данни
- [оптималният скок](https://www.wolframalpha.com/input?i=Argmin+of+f%28x%29+%3D+n%2Fx+%2B+x%2C+x+%3E+0%2C+n+%3E+0+for+x) е *sqrt(N)* (за минимален общ брой сравнения)
- *O(sqrt(N))* сложност по време
- [по-бавен](https://www.symbolab.com/solver/limit-calculator/%5Clim_%7Bx%5Cto%5Cinfty%7D%5Cleft(%5Cfrac%7Blnx%7D%7B%5Csqrt%7Bx%7D%7D%5Cright)?or=input) от Binary search ([*O(log(N))* < *O(sqrt(N))* < *O(N)*](https://www.wolframalpha.com/input?i=plot+log%28n%29%2C+sqrt%28n%29+from+1+to+1000))
- подходящ когато стъпките назад в масив ни струват скъпо

Търсеният елемент се сравнява последователно с елементи на позиции, кратни на стъпката (корен от N). Когато търсеният елемент стане по-малък от елемента на K-та стъпка, се извършва линейно търсене в интервала (K-1)-ва стъпка до K-та стъпка.

Jump search прави 1 връщане назад в масива, докато при Binary search има най-много *logN* връщания. При нужда от ограничаване на връщанията Jump search е предпочитан пред Binary search въпреки по-голямата сложност по време. Точно поради тази причина не се извършва двоично търсене в намерения интервал.

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

    for (int i = start; i < end; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```

## Exponential search (Експоненциално търсене)

- работи **само** за сортирани данни
- [*O(logi)*](https://en.wikipedia.org/wiki/Exponential_search#Performance) сложност по време, където *i* е позицията на числото
- подходящ при търсене на елементи, намиращи се в началото на масива (*i < N*)
- подходяш, когато не знаем големината на входните данни, в които търсим (например поток)

Търсеният елемент се сравнява последователно с елементи на позиции, степени на двойката (2<sup>K</sup>). Когато търсеният елемент стане по-малък от елемента на К-та степен, се извършва двоично търсене в интервала 2<sup>K-1</sup>-ва позиция до 2<sup>K</sup>-та позиция.

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

## Задачи за упражнение

- [Binary Search - Easy](https://leetcode.com/problems/binary-search/)
- [Sqrt(x) - Easy](https://leetcode.com/problems/sqrtx/)
- [Search Insert Position - Easy](https://leetcode.com/problems/search-insert-position)
- [First Bad Version - Easy](https://leetcode.com/problems/first-bad-version)
- [Puncakes - Medium](https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/problem)
- [Peak Index in a Mountain Array - Medium](https://leetcode.com/problems/peak-index-in-a-mountain-array)
    - 2 решения - ternary и binary
- [Search a 2D Matrix - Medium](https://leetcode.com/problems/search-a-2d-matrix)
    - 3 решения
- [Find first and last position of element in sorted array - Medium](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- [Safe Sort - Medium](https://www.hackerrank.com/contests/si-practice-2/challenges/task-1-1-1)

## Бонус задачи
- [Single Element in a Sorted array - Medium](https://leetcode.com/problems/single-element-in-a-sorted-array/)
- [Search in Rotated Sorted Array - Medium](https://leetcode.com/problems/search-in-rotated-sorted-array/)

# Бонус материал
- Eytzinger binary search - https://algorithmica.org/en/eytzinger
    - Как може да бъде оптимизиран binary search при много заявки в големи масиви?
- Branch predictor - https://en.wikipedia.org/wiki/Branch_predictor
