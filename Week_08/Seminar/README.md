# Упражнение 8 - Свободна програма

## Важно!
Няма конкретна теми за тази седмица. Всеки семинар ще покаже нещо различно в зависимост какво е преценил - било то преговор, наваксване, по-сложни задачи, допълнителен материал.

В прикачените материали са разгледани допълнителни техники/структури, **които не са пряко включени в курса**, но могат да бъдат полезни за развиване на вашите problem-solving skills и разбира се при интервютата ви в бъдеще. Представени са - **Cache eviction algorithms**, **Prefix sum**, **Trie**.

---

## Cache

### Описание

**Cache (кеш)** - структура от данни за временно съхранение на често използвани данни, за да се избегнат скъпи повторни изчисления или заявки. Обикновено е с ограничен размер и използва политики за премахване на елементи, когато е пълен.

**Приложения в програмирането:**
- **Memoization** - кеширане на резултати от функции (например Fibonacci)
- **Web кеш** - съхранение на HTTP отговори
- **Database query cache** - резултати от SQL заявки
- **CDN кеш** - статични файлове (изображения, JS, CSS)

**Основни операции:**
- **Get(key)**: Ако ключът е в кеша → hit (O(1)), иначе → miss (зареждане/изчисление и добавяне в кеша)
- **Put(key, value)**: Запазване в кеша, при пълен кеш → eviction (премахване на елемент)

**Note:** Други неща свързани с кеширането, като write-through, write-back, prefetching и други, не са обект на това упражнение, но може да прочетете за тях [тук](https://en.wikipedia.org/wiki/Cache_(computing))

---

### Eviction policies (Политики за премахване)

Когато кешът е пълен, трябва да решим кой елемент да премахнем:

**LRU (Least Recently Used):**
- Премахва най-отдавна използвания елемент
- Имплементация: Hash map + Doubly Linked List
- O(1) за get и put операции

**LFU (Least Frequently Used):**
- Премахва най-рядко използвания елемент
- Пази броя на достъпванията за всеки елемент

**FIFO (First In First Out):**
- Премахва най-стария елемент (първо добавен)
- Опашка (queue)
- Прост, но не най-ефективен

**Random:**
- Премахва случаен елемент

**Time aware**
- Time To Live: елементите имат срок на годност
- След изтичане се премахват автоматично
- Могат да се махнат проактивно или при следващ достъп

### Задачи
- [LRU Cache](https://leetcode.com/problems/lru-cache/description/)
- [LFU Cache](https://leetcode.com/problems/lfu-cache/description/)

## [Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum) (също и Suffix sum)

### Описание

**Prefix sum (префиксна сума)** - техника, при която правим предварително обработване на масив като съвзадавме нов, за който на позиция i седи акумулиран резултат от изпълнение на операция върху елементите на първоначалния масив от 0 до i. Най-често тази операция е събиране.

**Идея:** Вместо да сумираме всеки път от индекс `i` до `j`, предварително изчисляваме:
```
prefix[i] = arr[0] + arr[1] + ... + arr[i]
```

Тогава сумата от `i` до `j` е:
```
sum(i, j) = prefix[j] - prefix[i-1]
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
- Предварително изчисление: O(n)
- Заявка за сума: O(1)
- Памет: O(n)

**Suffix sum** е аналогична - сумира отзад напред.

### Задачи
- [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/description/)
- [Contiguous array](https://leetcode.com/problems/contiguous-array/description/)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)
- [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/description/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

## [Trie](https://en.wikipedia.org/wiki/Trie)

### Описание

**Trie (prefix tree, дърво на префикси)** - дървовидна структура за ефективно съхранение и търсене на низове. В частност за търсене на думи/префикси и autocomplete.

**Характеристики:**
- Всеки възел съдържа буква (или част от ключ)
- Пътят от корен до листо формира дума
- Споделени префикси споделят възли

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
- Бързо автодопълване (autocomplete - early age google autocomplete)
- Проверка за prefix за O(m), където m = дължина на префикса
- Алтернатива на hash set за низове

**Недостатъци:**
- Заема повече памет от hash table

### Структура на възел

<details>
  <summary>C++</summary>

```cpp
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
```
За всяка буква в думата:
  - Ако възел за буквата не съществува → създай
  - Премини към следващия възел
Маркирай последния възел като край на дума
  - Увеличи count (ако е приложимо)

Сложност: O(m), m = дължина на думата
```

**Search (търсене на дума):**
```
За всяка буква в думата:
  - Ако възел за буквата не съществува → false
  - Премини към следващия възел
Проверка дали последният възел е край на дума

Сложност: O(m), m = дължина на думата
```

**StartsWith (търсене на префикс):**
```
Като Search, но без проверка за isEndOfWord

Сложност: O(m), m = дължина на думата
```

**Delete (изтриване):**
```
- Рекурсивно изтриване на възли, които нямат други деца
- Внимание: не трябва да се изтриват възли, които са част от други думи
```

| Операция   | Време | Памет |
|------------|-------|-------|
| Insert     | O(m)  | O(m)  |
| Search     | O(m)  | O(1)  |
| StartsWith | O(m)  | O(1)  |
| Delete     | O(m)  | O(1)  |

### Задачи
- [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/description/)
- [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)
- [Design File System](https://leetcode.com/problems/design-file-system/)
- [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)
