# Упражнение 2

# Сложност на алгоритми
  
## Днес ще разгледаме

- Видове сложности
- Правила за смятане на Big O изрази
- Основи при изчисляване на сложности

## Видове сложности:

- константа - *O(1)*
- логаритмична - *О(logN)*
- линейна - *O(N)*
- енлог - *O(NlogN)*
- квадратична - *O(N<sup>2</sup>)*
- кубична - *O(N<sup>3</sup>)*
- експоненциална - *O(c<sup>N</sup>)*

Ред на нарастване на времето:

>*1 < logN < sqrtN < N < NlogN < N<sup>2</sup> < N<sup>3</sup> < 2<sup>N</sup> < 3<sup>N</sup> < N! < N<sup>N</sup>*


## Правила за смятане на Big O изрази:

- константите, които са множители не влияят.
  > *O(100N) = O(N)*

- влияе само най-бързо растящата функция, при сбор от множители.
  > *О(N<sup>2</sup> + NlogN + N + 1) = O(N<sup>2</sup>)*

- при произведение от множители, влияят всички функции.
  > *O(N<sup>2</sup> log<sup>3</sup>N) не може да бъде опростено.

- основата на логаритъма не влияе.
  > *O(log<sub>2</sub>N) = O(log<sub>3</sub>N)*

    Изписва се просто *O(logN)*.
    Това не важи за степента на логаритмична функция (горния пример).
    
---

Примери:
- *О(2N) = O(N) = O(10000N)*
- *O(10000000) < O(logN)*
- *O(N + M)*

При невъзможност да се определи коя функция е по-голяма *N* или *М*, изразът *O(N + M)* не може да бъде опростен.


## Колко разлика оказва сложността? (практичен пример)

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


## Основи при изчисляване на сложности

*O(1)* - връщането на константа:
  
```cpp
double get_Pi() {
    return 3.14;
}

*O(1)* - връщането на елемент от масив:
  
```cpp
int get_5th_element(int arr[]) {
    return arr[5];
}
```

---

*O(N)* - еднократно обхождане на масив с големина *N*.

```cpp
void traverse_array(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << std::endl;
    }
}
```

*O(N<sup>2</sup>)* - обхождане на масив с големина *N* *N* пъти (чрез вложен цикъл). Обхождане на матрица с размер *NxN*.

```cpp
void traverse_matrix(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << i << " " << j << std::endl;
        }
    }
}
```

---

*O(2<sup>N</sup>)* - Намиране на *N*-тото число от редицата на Фибоначи. Всяко извикване на функцията, създава 2 нови деца, всяко от които 2 свои деца и т.н.

```cpp
int fibonacci(int N) {
    if (N <= 1) {
        return N;
    }
    return fibonacci(N - 1) + fibonacci(N - 2);
}
```


*O(logN)* - Намиране на колко двойки се съдържат в числото *N*. На всяко рекурсивно извикване, числото намаля 2 пъти.

```cpp
int count_deuces(int N, int count = 0) {
    if (N <= 1) {
        return count;
    }
    
    return count_deuces(N / 2, count + 1);
}

---

*O(N + M)* - обхождане на масив с големина *N* и масив с големина *M*.

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

---

*O(sqrt(N))* - проверка дали едно число е просто.

```cpp
bool is_prime(int N) {
    if (N < 2) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(N); ++i) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}
```


## Задачи за упражнение

- [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
- [Plus One](https://leetcode.com/problems/plus-one/)
- [Rotate Image](https://leetcode.com/problems/rotate-image/)
- [Water supplies](https://www.hackerrank.com/contests/practice-1-sda/challenges/challenge-2196)
- [Missing bus ticket](https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/missing-bus-ticket/problem)
- [Single Number](https://leetcode.com/problems/single-number/)

