# Допълнителна тема 1

## Темата включва

- [Cache](#cache-кеш)
- [Prefix sum](#prefix-sum-префиксна-сума)
- [Trie](#trie-дърво-на-префикси)

## Важно!
Темите тук **не са пряко включени в курса** и не остана време да ги разгледаме в упражненията, но могат да бъдат полезни за развиване на вашите problem-solving skills и, разбира се, при интервютата ви в бъдеще.

---

## Cache (Кеш)

### Описание

**Cache (кеш)** – структура от данни за временно съхранение на често използвани данни, за да се избегнат скъпи повторни изчисления или заявки. Обикновено е с ограничен размер и използва политики за премахване на елементи, когато е пълен.

**Приложения в програмирането:**
- **Memoization** – кеширане на резултати от функции (например Fibonacci)
- **Web кеш** – съхранение на HTTP отговори
- **Database query cache** – резултати от SQL заявки
- **CDN кеш** – статични файлове (изображения, JS, CSS)

**Основни операции:**
- **Get(key)**: ако ключът е в кеша → hit ($\mathcal{O}(1)$), иначе → miss (зареждане/изчисляване и добавяне в кеша)
- **Put(key, value)**: запазване в кеша; при пълен кеш → eviction (премахване на елемент)

**Note:** Други неща, свързани с кеширането, като write-through, write-back, prefetching и др., не са обект на това упражнение, но може да прочетете за тях [тук](https://en.wikipedia.org/wiki/Cache_(computing)).

---

### Eviction policies (Политики за премахване)

Когато кешът е пълен, трябва да решим кой елемент да премахнем:

**LRU (Least Recently Used):**
- Премахва най-отдавна използвания елемент
- Имплементация: hash map + doubly linked list
- $\mathcal{O}(1)$ за операциите get и put

**LFU (Least Frequently Used):**
- Премахва най-рядко използвания елемент
- Пази броя на достъпванията за всеки елемент

**FIFO (First In First Out):**
- Премахва най-стария (първия добавен) елемент
- Имплементация: queue (опашка)
- Прост, но не най-ефективен

**Random:**
- Премахва случаен елемент

**Time aware:**
- Time To Live (TTL): елементите имат срок на годност
- След изтичането му се премахват автоматично
- Могат да се премахнат проактивно или при следващ достъп

### Задачи
- [LRU Cache](https://leetcode.com/problems/lru-cache/) - Medium
  - hash map + doubly linked list (а защо не [singly](https://stackoverflow.com/questions/49621983/lru-cache-with-a-singly-linked-list)?)
- [LFU Cache](https://leetcode.com/problems/lfu-cache/) - Hard

## Prefix sum (Префиксна сума)

### Описание

**[Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum) (префиксна сума)** – техника, при която предварително обработваме масив, като създаваме нов, в който на позиция `i` стои натрупаният резултат от прилагането на дадена операция върху елементите на първоначалния масив от `0` до `i`. Най-често тази операция е събиране.

**Идея:** Вместо да сумираме всеки път от индекс `i` до `j`, предварително изчисляваме:
```text
prefix[i] = arr[0] + arr[1] + ... + arr[i]
```

Тогава сумата от `i` до `j` е:
```text
sum(i, j) = prefix[j] - prefix[i-1]    (при i = 0: sum(0, j) = prefix[j])
```

**Пример:**
```text
arr    = [3, 1, 4, 2, 5]
prefix = [3, 4, 8, 10, 15]

Сума от индекс 1 до 3:
sum(1, 3) = prefix[3] - prefix[0] = 10 - 3 = 7
= arr[1] + arr[2] + arr[3] = 1 + 4 + 2 = 7 ✓
```

**Сложности:**
- Предварително изчисление: $\mathcal{O}(n)$
- Заявка за сума: $\mathcal{O}(1)$
- Памет: $\mathcal{O}(n)$

**Suffix sum** (суфиксна сума) е аналогична – сумира отзад напред.

### Задачи
- [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) - Easy
- [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/) - Easy
- [Contiguous Array](https://leetcode.com/problems/contiguous-array/) - Medium
  - [HackerRank аналог](https://www.hackerrank.com/contests/sda-homework-9/challenges/0-1-1)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) - Medium
- [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) - Medium
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) - Medium

## Trie (Дърво на префикси)

### Описание

**[Trie](https://en.wikipedia.org/wiki/Trie) (prefix tree, дърво на префикси)** – дървовидна структура за ефективно съхранение и търсене на низове, в частност за търсене на думи/префикси и autocomplete.

**Характеристики:**
- Всеки възел (без корена) отговаря на буква (или част от ключ)
- Пътят от корена до възел, маркиран като край на дума, образува дума
- Думи с общ префикс споделят възлите на този префикс

**Визуализация:**
```text
Думи: "cat", "car", "dog", "doge"

       root (null)
      /    \
     c      d
     |      |
     a      o
    / \     |
   t   r    g (*)
  (*)  (*)  |
            e (*)

(*) = край на дума
```

**Предимства:**
- Бързо автодопълване (autocomplete) – например в ранните версии на Google
- Проверка за префикс за $\mathcal{O}(m)$, където m е дължината на префикса
- Алтернатива на hash set за низове

**Недостатъци:**
- Заема повече памет от hash table

### Структура на възел

<details>
  <summary>C++</summary>

```c++
struct TrieNode {
    // може и vector
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;

    // Optional:
    int count = 0; // брой думи с този префикс
};
```

</details>

<details>
  <summary>Python</summary>

```python
class TrieNode:
    def __init__(self):
        # също може да е масив
        self.children = {}  # char -> TrieNode
        self.is_end_of_word = False
        self.count = 0  # optional
```

</details>

### Операции

**Insert (добавяне на дума):**
```text
За всяка буква в думата:
  - Ако възел за буквата не съществува → създай го
  - Премини към следващия възел
  - Увеличи count на възела (ако се пази)
Маркирай последния възел като край на дума

Сложност: O(m), m = дължина на думата
```

**Search (търсене на дума):**
```text
За всяка буква в думата:
  - Ако възел за буквата не съществува → false
  - Премини към следващия възел
Провери дали последният възел е край на дума

Сложност: O(m), m = дължина на думата
```

**StartsWith (търсене на префикс):**
```text
Като Search, но без проверка дали последният възел е край на дума

Сложност: O(m), m = дължина на префикса
```

**Delete (изтриване):**
```text
- Рекурсивно изтриване на възлите, които нямат други деца
- Внимание: не трябва да се изтриват възли, които са част от други думи
```

| Операция   | Време            | Памет            |
|------------|------------------|------------------|
| Insert     | $\mathcal{O}(m)$ | $\mathcal{O}(m)$ |
| Search     | $\mathcal{O}(m)$ | $\mathcal{O}(1)$ |
| StartsWith | $\mathcal{O}(m)$ | $\mathcal{O}(1)$ |
| Delete     | $\mathcal{O}(m)$ | $\mathcal{O}(m)$ |

### Задачи
- [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) - Medium
- [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) - Medium
- [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) - Medium

# Бонус

## Бонус задачи
- [Stream of Characters](https://leetcode.com/problems/stream-of-characters/) - Hard
