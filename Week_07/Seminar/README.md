# Упражнение 7

## Днес ще разгледаме

- Хеш функции
- Хеш таблица и хеш сет
- Техника Rolling hash

## Хеш функции
Хеш функция наричаме функция, която получава елемент от произволно голяма множество (дори безкрайно) и връща стойност от някакво фиксирано крайно множество.

Основните характеристиките на хеш функциите са:

- Да бъдат бързи за изчисление.
- Да създават минимален брой колизии - т.е. данните да са разпределени равномерно в целия интервал
- Когато хешират един и същи обект, винаги да връщат една и съща стойност - да няма елемент на случайност или някакво състояние, което да повлияе на резултата от функцията (*stateless*).
- Oт $x == y$ следва $hash(x) == hash(y)$.
- От $hash(x) == hash(y)$ **не следва задължително** $x == y$.


### Пример: 

**Наивна хеш функция за низове**:
```text
Низ "abd":
'a' → 1, 'b' → 2, 'd' → 4
hash("abd") = 1 + 2 + 4 = 7

Низ "bad":
'b' → 2, 'a' → 1, 'd' → 4
hash("bad") = 2 + 1 + 4 = 7  ← КОЛИЗИЯ!
```

Две различни думи имат еднаква хеш стойност → **колизия**.

**По-добра хеш функция**:
```text
hash(s) = s[0]·p^(n-1) + s[1]·p^(n-2) + ... + s[n-2]·p¹ + s[n-1]·p⁰

Където p е просто число (например 31), n е дължината на низа

"abd" (n=3) → 1·31² + 2·31¹ + 4·31⁰ = 961 + 62 + 4 = 1027
"bad" (n=3) → 2·31² + 1·31¹ + 4·31⁰ = 1922 + 31 + 4 = 1957

Различни стойности! ✓
```

## Hashtable (Хештаблица)

[**Визуализация във visualalgo**](https://visualgo.net/en/hashtable)

**Дефиниция:** Структура от данни, която съхранява двойки ключ-стойност и осигурява бърз достъп (средно O(1)) чрез хеширане.

**Основна идея:** Използва масив и хеш функция за директен достъп до елементите. Вместо да търсим линейно или бинарно, изчисляваме **къде точно** е елементът.

**Как работи:**
```text
Ключ → хешираме ключа → получаваме индекс в масив → записваме стойността

"John" → hash("John") → 42 → "john@example.com"
```

**Предимства:**
- Константно време за търсене/добавяне/триене (average case)
- Ефективна за голям брой операции

**Недостатъци:**
- Не запазва подреденост
- Заема повече памет (поради load factor)
- Възможни колизии

Още много за хештаблица можете да прочетете [тук](https://en.wikipedia.org/wiki/Hash_table)

---

### Load Factor (Коефициент на запълване)

**Load factor (α)** показва колко запълнена е хеш таблицата:

```
α = n / m

където:
n = брой елементи в таблицата
m = размер на масива
```

**Защо е важен:**
- Колкото по-малък е α, толкова по-малко колизии, но неефективно използване на памет
- Колкото по-голям е α, толкова повече колизии и по-бавно време за операции

**Използва се различен load factor в зависимост от метода за справяне с колизии.**

---

## Справяне с колизии

Хеш функцията преобразува ключа в индекс на масива. Тъй като размерът на масива е ограничен, а възможните ключове са безкрайни, е възможно два различни ключа да се хешират до един и същи индекс - това се нарича **колизия**. Колизиите са неизбежна част от хеширането. Затова хеш функцията е важна да разпределя ключовете възможно най-равномерно, понеже, справянето с колизиите увеличава средното време за изпълнение на заявка.

### Separate chaining
- Това е най-популярният метод за справяне с колизии.
- Когато обект представен като цяло число, принадлежи на заета клетка - същото цяло число, двата обекта се нареждат в свързан списък. 
- Проверката дали елемент принадлежи в списъка се извършва линейно.
- Използва се свързан списък, защото бързо се добавя елемент в края и премахва елемент от средата.

```text
Хеш таблица (m=7):

0: → ["cat", 5] → ["dog", 3] → null
1: → null
2: → ["apple", 10] → null
3: → ["car", 7] → ["bus", 2] → ["bike", 9] → null
4: → null
5: → ["sun", 1] → null
6: → ["moon", 4] → null

hash("cat") = hash("dog") = 0  ← колизия, но двата са в списък
```

### [Open addressing](https://en.wikipedia.org/wiki/Open_addressing)
Open addressing is another collision resolution technique in which every entry record is stored in the bucket array itself, and the hash resolution is performed through probing

#### Linear Probing
- Ако обект се хешира до дадено цяло число *x*, но то вече е заето, то тогава ще бъде попълнено първото число по-голямо от *x*, което е свободно. 
- Ако например обект се хешира до числото 5 и то е заето, то тогава се започва търсене в 6, 7 и т.н.
- Не толкова предпочитан метод, поради наличието на *clustering*.
- [Описание на операциите по търсене, добавяне, триене](https://en.wikipedia.org/wiki/Linear_probing#Operations)

**Clustering** в обхвата на HashMap - явление, при което множество хеш стойности попадат в близки позиции, създавайки групи, които влошават ефективността на таблицата.
Пример, ако се замислите, в автобус 94 винаги има най-много хора около вратите на автобуса, докато в средата е по-празно. Тогава казваме, че има клъстър при всяка от вратите.

```text
Преди:
0: [ ][ ][ ][A][B][ ][ ][ ][ ][ ]
              ↑
           клъстър

След добавяне на C, D, E:
0: [ ][ ][ ][A][B][C][D][E][ ][ ]
              ↑____________↑
           голям клъстър!
           
→ Всички нови елементи с hash ∈ {3,4,5,6,7} ще удължат клъстъра
→ Операциите стават O(n) в най-лош случай
```

#### Double Hashing
- Използва 2 хеширащи функции, през които да прекарва даден обект.
- Първата функция $h1(key)$ дава началната позиция.
- При колизия, втората функция $h2(key)$ определя стъпката за търсене.
- Формула: $index = (h1(key) + i · h2(key)) % m$, където $i = 0, 1, 2, ...$
- [Ресурс за double hashing](https://en.wikipedia.org/wiki/Double_hashing)

#### Quadratic probing
- https://en.wikipedia.org/wiki/Quadratic_probing

## Имплементации в C++ и Python

Основните стурктури в Python, които са имплементирани чрез хештаблица, са *set* и *dictionary*.
В C++ това са *unordered_set* и *unordered_map*.

#### Python set/ C++ unordered_set

Представлява множество, в което всеки елемент е хеширан. За амортизирано константно време - *О(1\*)*, може да извършва операциите:
1) Да провери дали съществува даден елемент в множество.
2) Да добави елемент в множеството.
3) Да премахне елемент в множеството.
4) Да вземе броя на елементите в множеството.

#### Python dictionary/C++ unordered_map

Aналогична на *set*-a, но се състои от ключове, които сочат към стойности.
- Ключовете биват хеширани - отговарят на горепосочените характеристики на *set*-a.
- Не предоставя възможност за константа проверка дали дадена стойност съществува - единствено ключ.

Разписано как работи *dict*-a в Python: [ресурс](https://stackoverflow.com/questions/327311/how-are-pythons-built-in-dictionaries-implemented
)

## Какво е нужна на структура за да бъде ключ в хештаблица?
- Трябва да има дефинирана хеш функция, която връща цяло число. (getHashCode())
- Трябва да има дефинирана функция/оператор за равенство (==), за да се проверява дали два ключа са еднакви. (equals())
- Във всеки език тези функции са дефинирани по подразбиране за основните типове (int, string, и т.н.), но за потребителски типове трябва да ги дефинираме сами.

Пример в папка [Examples](./Examples/)

## Сравнение на сложностите и необходими функции

![image](https://github.com/user-attachments/assets/9a0fdb1c-ee7e-44e3-93f7-78c06715abaf)


## Мултимножества
В курса няма конкретно да разглеждаме следните структури, но е хубаво да знаете за съществуването им, понеже могат да бъдат полезни в някои задачи. Накратко, multimap структурите допускат повторения на ключовете, a multiset на стойностите. Повече може да прочетете на съответните линкове:
- [std::multimap](https://en.cppreference.com/w/cpp/container/multimap)
- [std::multiset](https://en.cppreference.com/w/cpp/container/multiset)
- [std::unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap)
- [std::unordered_multiset](https://en.cppreference.com/w/cpp/container/unordered_multiset)

## Техника Rolling hash

Техника за ефективно изчисляване на хеш стойност при преместване на "прозорец" върху низ или масив. Вместо да пресмятаме хеша отначало за всеки прозорец, актуализираме стойността получена на предишния прозорец за **O(1)** време.

**Note:** Не е постижимо с всяка hash функция!

```text
Пример:
Низ: "abcde"
Хеш функция: hash(s) = s[0]·p^(n-1) + s[1]·p^(n-2) + ... + s[n-2]·p¹ + s[n-1]·p⁰
Нека p = 31.
Нека 'a' = 1, 'b' = 2, 'c' = 3, 'd' = 4, 'e' = 5 ...
Нека прозорецът е с дължина 3.

Следователно:
hash("abc") = 1·31² + 2·31¹ + 3·31⁰ = 961 + 62 + 3 = 1026
hash("bcd") = 2·31² + 3·31¹ + 4·31⁰ = 1922 + 93 + 4 = 2019

Но hash("bcd") може да се изчисли от hash("abc"):
hash("bcd") = (hash("abc") - 1·31²) · 31 + 4·31⁰ = (1026 - 961) · 31 + 4 = 2019
```

Задача, която можем да решим с тази техника:
- [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences)

Полезни ресурси:
- [Rolling hash](https://en.wikipedia.org/wiki/Rolling_hash)
- [Rabin-Karp string search algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)
- Нагледно с код - https://www.francofernando.com/blog/algorithms/2021-05-16-rolling-hash/

## Задачи за упражнение

### Easy
- [Isomorphic strings](https://leetcode.com/problems/isomorphic-strings/)
- [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii)

### Medium
- [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence)
  - sorted vector/set vs unordered set
- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
  - добра за live coding
- [Group Anagrams](https://leetcode.com/problems/group-anagrams)
- [Special Triples](https://www.hackerrank.com/contests/sda-hw-9-2022/challenges/challenge-3771/)
- [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs)

### Hard
...

## Бонус

### Задачи
#### Hard (вероятно е да останат за следващия път)
- [LRU Cache](https://leetcode.com/problems/lru-cache/)
  - използване на няколко структури
- [0-1 Subarray](https://www.hackerrank.com/contests/sda-homework-9/challenges/0-1-1)
  - [leetcode аналог](https://leetcode.com/problems/contiguous-array/)
  - техника prefix sum
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k)
  - техника prefix sum
- [LFU Cache](https://leetcode.com/problems/lfu-cache/description/)
  - използване на няколко структури

### Материали
- [Encryption](https://en.wikipedia.org/wiki/Encryption)
- [Hashing vs Encryption](https://www.geeksforgeeks.org/computer-networks/difference-between-hashing-and-encryption/)
- [Hashing passwords](https://auth0.com/blog/hashing-passwords-one-way-road-to-security/)
