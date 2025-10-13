# Въведение, преговор и сложности

## Въведение

### Защо са важни Структурите от данни и алгоритми?

- Развиване на problem-solving skills и аналитичната мисъл
- Задължителна част от интервютата за работа ("whiteboard interviews")
  - Анализиране на проблем
  - Разработване на решение
  - Извличане на тестови сценарии
  - Тестване на решението
  - Оценка на решението
- Придобиване на разбиране за това как са имплементирани готовите структури в езика, които използваме ежедневно. Така можем да оценим:
  - каква е тяхната очаквана производителност?
  - как скалират при нарастване на данните?

### Запознаване с Hackerank и Leetcode
- https://www.hackerrank.com/
- https://leetcode.com/

#### Какво ни дават?
- Предварително зададени тестови.
- Автоматично оценяване на решения.
- Неограничен брой опити за предаване на решение.
- Получавате точки от най-високия резултат, получен от някое решение.
- Дори решението да не покрива 100% от тестовете, получавате точките за тестовете, които покривате.
- Автоматичните тестове не могат да се виждат преди да е приключило домашното.
- Възможност за собствено тестване преди предаване.

#### Различните грешки при изпълнение на автоматичен тест:
- Wrong Answer - Логическа грешка в алгоритъма.
- Runtime error - Възникване на грешка по време на изпълнение.
- Terminated due to timeout - Бавен, неподходящ алгоритъм.
- Memory limit - Изчерпване на паметта.
- Abort called - Грешка от ниско ниво (C++ препълване на стека).
- Segmenation fault - Опит за достъпване на памет, която е недостъпна.

[Hackerrank cheatsheet](./HackerrankHacks)

#### Важно
- Само и единствено при решаване на задачи тип LeetCode и Hackerrank няма да си трием динамичната памет и по-големите обекти ще ги заделяме като глобални само и единствено с цел бързодействие на кода ни. В реални условия това е изключително лоша практика.

## Преговор и запознаване със стандартна библиотека
<details>
  <summary>C++</summary>

### Поинтъри и референции
- Поинтър
	- съдържа адреса на една променлива
	- Има нулева стойност
 	- Може да променя стойността си
- Референция
	- "псевдоним"
	- веднъж инициализирана, не може да се промени да е реферция към друго
 

### Типове данни

| Data Type   | Size    | Size (bits) | Signed Value Range                                       | Unsigned Value Range            |
| ----------- | ------- | ----------- | -------------------------------------------------------- | ------------------------------- |
| `char`      | 1 byte  | 8 bits      | -128 to 127                                              | 0 to 255                        |
| `bool`      | 1 byte  | 8 bits      | `true` (1) or `false` (0)                                | N/A                             |
| `short`     | 2 bytes | 16 bits     | -32,768 to 32,767                                        | 0 to 65,535                     |
| `int`       | 4 bytes | 32 bits     | -2,147,483,648 to 2,147,483,647                          | 0 to 4,294,967,295              |
| `long`      | 4 bytes | 32 bits     | -2,147,483,648 to 2,147,483,647                          | 0 to 4,294,967,295              |
| `long long` | 8 bytes | 64 bits     | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807  | 0 to 18,446,744,073,709,551,615 |
| `float`     | 4 bytes | 32 bits     | Approximately ±3.4E−38 to ±3.4E+38 (7 decimal places)    | N/A                             |
| `double`    | 8 bytes | 64 bits     | Approximately ±1.7E−308 to ±1.7E+308 (15 decimal places) | N/A                             |

Формулите са: от -2<sup>n-1</sup> до 2<sup>n-1</sup> - 1 за *signed* типовете, и от 0 до 2<sup>n</sup> - 1 за *unsigned* типовете, където n е броят битове.

Често срещани грешки:
- overflow при събиране на int-ове
- сравняване на double-и с ==
  - **Бонус:** Как работят float и double - [тук](https://fabiensanglard.net/floating_point_visually_explained/?fbclid=IwAR1lwXOIifhzJmXkx49eniqaHE1iI7-MB6ofwR5mHgFOOO_NJWn-WxXbQBk)

### Масиви и матрици
- A[] vs A*[]
- A[][] vs A**

### Рекурсия (pros and cons)
- [Рекурсия](https://www.informatika.bg/lectures/recursion)

### Базово запознаване със структури от stl
- std::string
  - **Бонус:** Как е оптимизиран std::string за малки низове? (small string optimization)
- std::vector
  - **Бонус:** Каква е имплементацията на темплейтна специализация на vector<bool>? (bitset)
  - **Бонус:** Защо ако ползвам std::vector с дефиниран от мен клас, който няма default constructor, това не пречи на std::vector
- std::pair
- iterators
- range-based for loop (also known as for-each)
- auto keyword
- std::swap, std::min, std::max, std::reverse ...

</details>
<details>
  <summary>Python</summary>

### Основни концепции

- За преговор на основни принципи в Python, разгледайте тетрадката към този семинар: [тук](./playground_01.ipynb)
  - Като за начало може да клонирате това репо, линк към [ръководство](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository), или изтеглите ръчно тетрадката посочена в линка.
  - Как да работите с Jyputer тетрадкa във VScode, прочетете [тук](https://code.visualstudio.com/docs/datascience/jupyter-notebooks)! (Силно препоръчително умение за Data Analyst!)
- Как да четем входа от Hackerrank погледнете различните решения на тези две задачи: [решения на задача 1]() и [решения на задача 2]()
  

</details>

## Сложности
- Какво е сложност? Как сравняваме сложности?
- Сложност по време - Best, Worst, Average, Amortized 
- Сложност по памет - Best, Worst, Average, Amortized 
  - in-place алгоритъм - алгоритъм, който работи директно върху подадените данни и не заделя допълнителна памет пропорционална на входа
- https://devopedia.org/algorithmic-complexity

### Big O notation
- [cheatsheet](https://www.bigocheatsheet.com/)

### Видове сложности:

- константа - *O(1)*
- логаритмична - *О(logN)*
- линейна - *O(N)*
- енлог - *O(NlogN)*
- квадратична - *O(N<sup>2</sup>)*
- кубична - *O(N<sup>3</sup>)*
- експоненциална - *O(c<sup>N</sup>)*

Ред на нарастване на времето:

>*1 < logN < sqrtN < N < NlogN < N<sup>2</sup> < N<sup>3</sup> < 2<sup>N</sup> < 3<sup>N</sup> < N! < N<sup>N</sup>*

<img width="1201" height="794" alt="image" src="https://github.com/user-attachments/assets/282344ab-b0fc-438a-a463-052450b71b8a" />


### Правила за смятане на Big O изрази:

- константите, които са множители не влияят.
  > *O(100N) = O(N)*

- влияе само най-бързо растящата функция, при сбор от множители.
  > *О(N<sup>2</sup> + NlogN + N + 1) = O(N<sup>2</sup>)*

- при произведение от множители, влияят всички функции.
  > *O(N<sup>2</sup> log<sup>3</sup>N) не може да бъде опростено.

- основата на логаритъма не влияе.
  > *O(log<sub>2</sub>N) = O(log<sub>3</sub>N)*

    Изписва се просто *O(logN)*.
    Това не важи за степента на логаритмична функция (по-горния пример).
    
---

Примери:
- *О(2N) = O(N) = O(10000N)*
- *O(10000000) < O(logN)*
- *O(N + M)*

При невъзможност да се определи коя функция е по-голяма *N* или *М*, изразът *O(N + M)* не може да бъде опростен.


<details>
  <summary><b>Колко разлика оказва сложността? (практичен пример)</b></summary>

Нека имаме 2 компютъра. Компютър А е най-бързият за времето си със производителност 10 милиарда операции в секунда. Компютър Б е обикновен компютър и изчислява 10 милиона операции в секунда.

Задачата на компютрите е да сортират масив с 10 милиона елемента. 

Машина А използва Insertion sort със сложност *2N<sup>2</sup>*. Машина Б използва Мerge sort със сложност *50NlogN*.

За колко време всяка машина ще се справи със задачата?

Суперкомпютър А:
- S<sub>1</sub> = 2N<sup>2</sup> стъпки, за N = 10<sup>7</sup>
- V<sub>1</sub> = 10<sup>10</sup> стъпки/ сек
- => t<sub>1</sub> = 20000 сек. = ~5.5 ч.

Компютър Б:
- S<sub>2</sub> = 50NlogN стъпки, за N = 10<sup>7</sup>
- V<sub>2</sub> = 10<sup>7</sup> стъпки/ сек
- => t<sub>2</sub> = ~1163 сек. = ~20 мин.

Въпреки разликата в производителността и константите в алгоритмите (*2 и 50*), резултатите са коренно различни.

Още по-съществена разлика се наблюдава при увеличаване на големината на масива 10 пъти. При N = 100 милиона числа, компютър **А** отнема **23 дни**, а компютър **Б** - **4 часа**.

</details>

### Изчислете сложностите по време и по памет на следните алгоритми:

<details>
  <summary>C++</summary>

```c++
int f(int n) {
	int result = 0;
	for (size_t i = 0; i < 32; i++) {
		result += n;
	}
	return result;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(1)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
int f(int n) {
	int arr[INT_MAX];
 	arr[1] = 1;
	arr[2] = 2;
	return 1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(1)
	
  Space Complexity: O(1)
  
  Защо? Но на практика правилно ли е да го правим?
</details>


```c++
int f(int n) {
	int result = 1;
	for(size_t i = 0; i < INT_MAX; i++) {
		result += i;
	}
	return 1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(1)
	
  Space Complexity: O(1)
  
  Защо? Но на практика правилно ли е да го правим?
</details>


```c++
int f(int n) {
	int result = 1;
	for(size_t i = 1; i < n; i*=2) {
		result += i;
	}
	return 1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(log N)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
void selectionSort(int* arr, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;

		// first i numbers are already ordered
		for (size_t j = i + 1; j < length; j++) {
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}

		if (minIndex != i) // if minIndex changed - swap
			swap(arr[i], arr[minIndex]);
	}
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(N ^ 2)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
int binarySearch(const std::vector<int>& v, int target) {
	int left = 0;
	int right = v.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2; // why?
		if (v[mid] == target) {
			return mid;
		}
		else if (v[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(logN)
	
  Space Complexity: O(1)
  
  Защо?
</details>

```c++
void printIndexes(const std::vector<int>& v)  {
    for (int i = 0; i < v.size(); i++)  {
        std::cout << binarySearch(arr, v.size(), arr[i], 0, size - 1);
    }
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: O(N*logN)
	
  Space Complexity: *O(1)*
  
  Защо?
</details>


```c++
void permute(string s, int left, int right) {
  if(left == right) {
    std::cout << s << std::endl;
    return;
  }

  for(int i = left; i <= right; i++) {
    swap(a[left], a[i]);
    permute(s, left + 1, r);
    swap(a[l], a[i]);
  }
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: *O(n!)*
	
  Space Complexity: *O(s.size())*
  
  Защо?
</details>


```cpp
void brothers(int N, int M) {
    for (int i = 0; i < N; ++i) {
        std::cout << i << std::endl;
    }

    for (int j = 0; j < M; ++j) {
        std::cout << j << std::endl;
    }
}
```

<details>
  <summary>Отговор</summary>
  Time Complexity: *O(N + M)* - обхождане на масив с големина *N* и масив с големина *M*.
	
  Space Complexity: *O(1)*
  
  Защо?
</details>

</details>


<details>
  <summary>Python</summary>
  
*O(1)* - връщането на константа:
  
```python
def get_Pi():
    return 3.14
```

*O(1)* - връщането на елемент от масив:
  
```python
def get_5th_element(arr):
    return arr[5]
```

Защо това е така:
- https://stackoverflow.com/questions/37350450/why-is-a-list-access-o1-in-python
- https://softwareengineering.stackexchange.com/questions/252407/why-is-the-complexity-of-fetching-a-value-from-an-array-be-o1 

---

*O(N)* - еднократно обхождане на масив с големина *N*.

```python
for el in arr:
    print(el)
```

*O(N<sup>2</sup>)* - обхождане на масив с големина *N* *N* пъти (чрез вложен цикъл). Обхождане на матрица с размер *NxN*.

```python
for i in range(N):
    for j in range(N):
        print(i, j)
```

---

*O(2<sup>N</sup>)* - Намиране на *N*-тото число от редицата на Фибоначи. Всяко извикване на функцията, създава 2 нови деца, всяко от които 2 свои деца и т.н.

```python
def fibonacci(N):
    if N <= 1:
        return N
    return fibonacci(N-1) + fibonacci(N-2)
```


*O(logN)* - Намиране на колко двойки се съдържат в числото *N*. На всяко рекурсивно извикване, числото намаля 2 пъти.

```python
def count_deuces(N, count = 0):
    if N <= 1:
        return count
    
    count += 1
    return count_deuces(N // 2, count)
```

Как можем да променим функцията, така че да не използва аргумент `count`?

<details>
  <summary>Отговор</summary>

```python
def count_deuces(N):
    if N <= 1:
        return 0
    
    return count_deuces(N // 2) + 1
```

</details>

---

*O(N + M)* - обхождане на масив с големина *N* и масив с големина *M*.

```python
def brothers(N, M):
    for i in range(N):
        print(i)

    for j in range(M):
        print(j)
```

Изпробвайте функциите с различни параметри в [playground-a](./playground_01.ipynb)

</details>


## Задачи

### Easy
- [Solve Me First](https://www.hackerrank.com/challenges/solve-me-first/problem)
- [Simple Array Sum](https://www.hackerrank.com/challenges/simple-array-sum/problem)
- [Roommates](https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/1-410)
- [Single Number 1](https://leetcode.com/problems/single-number/)
	- Може ли да се реши с O(1) допълнителна памет и O(n) време?
- [Move zeroes](https://leetcode.com/problems/move-zeroes/)
- [Plus one](https://leetcode.com/problems/plus-one/)
  
### Medium
- [Two sum](https://leetcode.com/problems/two-sum/)
	- Какво се променя ако сортираме масива?
	- Two-pointer technique
- [Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [Rotate Array](https://leetcode.com/problems/rotate-array/)
- [Rotate image](https://leetcode.com/problems/rotate-image/)
- [Container with most water](https://leetcode.com/problems/container-with-most-water/)

### Hard
- [First missing positive](https://leetcode.com/problems/first-missing-positive/)
  - Първо се опитайте да го решите с O(N) време и O(N) памет.

Решения на задачите на C++ и Python може да намерите в папката [Solutions](./Solutions).


## Quiz


## Бонус Задачи

Majority element - https://leetcode.com/problems/majority-element/?envType=problem-list-v2&envId=divide-and-conquer
- Boyer-Moore Majority Voting Algorithm
