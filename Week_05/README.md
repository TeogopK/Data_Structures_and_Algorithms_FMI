# Упражнение 4

## Темата включва

- Едносвързан списък
- Двойносвързан списък
- Array vs Linked list
- Задачи
- Бонус

## Свързан списък

**Note:** В папка LinkedLists може да намерите имплементации на структурите

### Какво е абстрактна структура от данни
Абстрактният тип данни дава определена дефиниция (абстракция) на конкретната структура т.е. определя допустимите опера­ции и свойства, без да се интересува от конкретната реализация. Това позволява един тип абстрактни данни да има различни реализации и респективно различна ефективност.

[List](https://en.wikipedia.org/wiki/List_(abstract_data_type)) е абстрактна структура от данни. Никой не ни задължава имплементацията отзад да е масив или linked list, стига да е спазен интерфейсът.

### Какво е свързан списък
Линейна структура от данни, чиито данни не са наредени последователно в паметта, а всеки елемент има указател към следващия.

![image](https://github.com/user-attachments/assets/552c9370-4a1d-485d-8062-a9d27ff9d49b)

Има различни имплементации:
- с опашка
- без опашка
- singly
- doubly

Кога бихме го използвали и защо ни е Linked list:
- Всичко изискващо Next/Prev функционалност
- Специфични задачи с много добавяния(в начало и край) и конкатенирания на листи
- Да разберем поинтърите
- Използва се в други по-сложни структури от данни

### Представяне в паметта

|Array|LinkedList|
|------------------------------------|------------------------------------|
| <img width="1059" height="478" alt="image" src="https://github.com/user-attachments/assets/1c6f82d3-d50e-4ef0-b127-71206c9b99cc" /> | <img width="1048" height="485" alt="image" src="https://github.com/user-attachments/assets/d59950ce-5408-4697-85d6-353c90e21438" /> |

|Inserting a node|Removing a node|
|------------------------------------|------------------------------------|
| <img width="1026" height="273" alt="image" src="https://github.com/user-attachments/assets/a07ca68a-7ca8-4ced-8e04-6d62b4ebe084" /> | <img width="1027" height="465" alt="image" src="https://github.com/user-attachments/assets/b7f02376-6c73-40eb-947f-d4925f6e4a9d" /> |

### Преглед на имплементация на Singly linked list (Едносвързан списък)

**Note:** Никой не ни пречи във всяка от имплементациите да добавим и size на колекцията.

Класическата имплементация на възел от едносвързан списък:

<details>
  <summary>C++</summary>

```c++
template<typename T>
struct Node {
  T value;
  Node* next;

  Node(const T& value, Node* next = nullptr)
    : value(value), next(next) { }
};
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>


Тази структура може да се обвие в клас, който да представлява свързан списък. Свързаният списък държи указател към първият node, за оптимизация и по-бързо добавяне в края ще пазим и последния.


<details>
  <summary>C++</summary>

```c++
template<typename T>
class SinglyLinkedList {
private:
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node* next = nullptr)
			: value(value), next(next) { }
	};

	Node* head, * tail;
public:
....
};

```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

---

Опашката дава възможност за добавяне на елемент за константно време в края на списъка:

<details>
  <summary>C++</summary>

```c++
template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
	Node* newNode = new Node(value);

	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

---

Добавяне на елемент в началото на списъка става за константно време:


<details>
  <summary>C++</summary>
	
```c++
template<typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
	Node* newNode = new Node(value);

	if (!head) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

---

Обхождане на свързан списък:


<details>
  <summary>C++</summary>

```c++
template<typename T>
void SinglyLinkedList<T>::print() const {
	Node* iter = head;

	while (iter) {
		std::cout << iter->value << " ";
		iter = iter->next;
	}

	std::cout << "\n";
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

---

Изтриване на елемент в **началото** на списъка - **константна** сложност:

<details>
  <summary>C++</summary>

```c++
template<typename T>
void SinglyLinkedList<T>::pop_front() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* temp = head;
	head = head->next;
	delete temp;

	// in case we had only one element
	if (!head) {
		tail = nullptr;
	}
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

---

Изтриване на елемент в **края** на списъка - **линейна** сложност, понеже нямаме директен достъп до предпоследния елемент!

<details>
  <summary>C++</summary>

```c++
template<typename T>
void SinglyLinkedList<T>::pop_back() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* prev = nullptr;
	Node* iter = head; // iter will be poiting to the last element after the loop
	while (iter != tail) {
		prev = iter;
		iter = iter->next;
	}

	if (iter == head) { // in case we had only one element
		head = tail = nullptr;
	}
	else {
		prev->next = nullptr;
		tail = prev;
	}

	delete iter;
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

## Двойносвързан списък

Всеки възел съхранява указател за елементите преди и след себе си. Това позволява обхождане на списъка в обратна посока.
Класическата имплементация на възел от двойносвързан списък:

<details>
  <summary>C++</summary>

```c++
template<typename T>
class DoublyLinkedList {
private:
	struct Node {
		T value;
		Node* prev, * next;

		Node(const T& value, Node* prev = nullptr, Node* next = nullptr)
			: value(value), prev(prev), next(next) { }
	};

	Node* head, * tail;
	size_t length = 0;
public:
...
};
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

Имплементациите не се различава особено от тази на SinglyLinkedList освен с това, че трябва правилно да нагласяме prev и next на всеки елемент.
Важно е да споменем, че в този случай премахване на елемент в края на списъка може да бъде постигнато за константно време:

---

Премахване на елемент в края на списъка - **константно** време:

<details>
  <summary>C++</summary>

```c++
template<typename T>
void DoublyLinkedList<T>::pop_back() {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	Node* toDelete = tail;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete toDelete;
	length--;
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

Получаваме предимството да премахнем последния елемент за константно време, но увеличаваме паметта, нужна за съхранението на структурата.

### Алтернативна имплементация със sentinel nodes

Добавят се dummy nodes в началото и края, които никога не се трият, с цел да се спестят всичките проверки свързани с head и tail.
https://www.geeksforgeeks.org/dsa/doubly-linked-list-using-sentinel-nodes/

## Linked List или Array

Предимства на Linked List:
- константно време за добавяне в началото и края (в зависимост от имплементация).
- константно време за добавяне на елемент на произволна позиция при наличие на указател*.
- не се заделя излишна памет за резервни клетки.
- константно време за конкатенация на два листа

Недостатъци:
- произволен достъп до елемент на дадена позиция е линейно време
- търсенето става за линейно време
- заделя се допълнителна памет за всеки указател към следващия елемент.
- Няма locality, което в практиката е от изключителна важност

Почти винаги ще предпочитаме масив, заради бързото търсене и locality.

<details>
  <summary>Добавянето в масив e със сложност Amortized O(1). (Отвори за обяснение)</summary>
Амортизираната сложност е общият разход на операция, оценен за цяла поредица от операции.

С други думи, ако добавим само един елемент, това може да бъде много скъпо — $\mathcal{O}(n)$, но ако добавим n елемента, тогава сложността ще бъде $\mathcal{O}(n)$ за добавяне на всички n елемента.

Обяснение с пример:
Нека вземем динамичен масив (в C++ това е std::vector).

В началото имаме само един празен слот. За константно време добавяме един елемент в края на масива.

Когато искаме да добавим още един елемент, масивът е запълнен, затова го удвояваме по размер (до 2 слота), копираме стария елемент в началото и за константно време добавяме новия елемент в края. Копирането изисква $\mathcal{O}(n)$ стъпки.

Искаме да добавим трети елемент, но капацитетът ни е 2, затова увеличаваме масива до 4 елемента, което изисква $\mathcal{O}(n)$ стъпки, и добавяме новия елемент в края за константно време.

Искаме да добавим четвърти елемент, а капацитетът ни вече е 4, така че можем да го добавим в края за константно време.

В заключение:
Всеки път, когато искаме да добавим елемент на позиция $2^k$, трябва да разширим масива със сложност $\mathcal{O}(2^k)$. Всички останали добавяния са със сложност $\mathcal{O}(1)$.

В крайна сметка имаме следната сума: $1 + 2^0 + 1 + 2^1 + 1 + 1 + 2^2 + 1 + 1 +... + 2^k$, където $k = \log(n)$. Ако съберем тези числа, ще получим n от единиците и 2n от степените на двойката. Заключението е, че добавянето на n елемента ни струва $\mathcal{O}(n)$ време. С други думи, амортизираната сложност на добавяне на един елемент е $\mathcal{O}(1)$.
</details>

## Complexity comparison

| Operation / Data structure | Array            | Singly linked list without tail | Singly linked list with tail | Doubly linked list without tail | Doubly linked list with tail |
| -------------------------- | ---------------- | ------------------------------- | ---------------------------- | ------------------------------- | ---------------------------- |
| push_front                 | $\mathcal{O}(n)$ | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             |
| pop_front                  | $\mathcal{O}(n)$ | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             |
| get_front                  | $\mathcal{O}(1)$ | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             |
| push_back                  | $\mathcal{O}(1*)$ | $\mathcal{O}(n)$                | $\mathcal{O}(1)$             | $\mathcal{O}(n)$                | $\mathcal{O}(1)$             |
| pop_back                   | $\mathcal{O}(1)$ | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             | $\mathcal{O}(n)$                | $\mathcal{O}(1)$             |
| get_back                   | $\mathcal{O}(1)$ | $\mathcal{O}(n)$                | $\mathcal{O}(1)$             | $\mathcal{O}(n)$                | $\mathcal{O}(1)$             |
| get_at                     | $\mathcal{O}(1)$ | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             |
| find_key                   | $\mathcal{O}(n)$ | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             |
| erase_key                  | $\mathcal{O}(n)$ | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             |
| is_empty                   | $\mathcal{O}(1)$ | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             |
| add_before                 | $\mathcal{O}(n)$ | $\mathcal{O}(n)$                | $\mathcal{O}(n)$             | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             |
| add_after                  | $\mathcal{O}(n)$ | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             | $\mathcal{O}(1)$                | $\mathcal{O}(1)$             |

**Note: За XOR linked list - add_before и add_after са с линейна сложност!**


### Имплементации в STL
- std::list -> doubly
- forward_list -> singly


## Задачи

### Подходи и съвети за задачи
- техника Two pointers - fast and slow
- В случай, че ни трябва директен достъп - да пазим масив с всички ListNode* - ListNode*[10000000]
- Във всяка задача има много edge cases около
	- празен list
 	- това дали елемент е head или tail
	- дали елемент е nullptr
- Много често задачите могат да бъдат решени по повече от един начин

### Easy

- [Middle of the linked list](https://leetcode.com/problems/middle-of-the-linked-list/)
- [Linked list cycle](https://leetcode.com/problems/linked-list-cycle/)
  - https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
- [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [Reverse linked list](https://leetcode.com/problems/reverse-linked-list/)
- [Replace element with ones](https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3729)
- [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
- [Palindrome Linked list](https://leetcode.com/problems/palindrome-linked-list/)
  
### Medium
- [Delete Node in a Listed List](https://leetcode.com/problems/delete-node-in-a-linked-list/)
  - O(1) time and space
- [Linked List cycle 2 - Medium](https://leetcode.com/problems/linked-list-cycle-ii/)
  - за O(1) space как ще стане
- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [Odd and Event Linked list](https://leetcode.com/problems/odd-even-linked-list/)

### Hard
- [ZUMA - Hard](https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/zuma-1)

# Бонус

## XOR Linked List
Това е Doubly Linked list, който заема толкова памет колкото един singly linked list. Всеки Node пази като стойност XOR стойността на адреса на предходния елемент и на следващия. (Припомнете си как работеше XOR и по-конкретно пробвайте тази задача https://leetcode.com/problems/single-number/).

<details>
  <summary>C++</summary>
	
```c++
template<typename T>
class XORLinkedList {
private:
	struct Node {
		T value;
		Node* nextXORPrev;

		Node(const T& value, Node* nextXORPrev = nullptr)
			: value(value), nextXORPrev(nextXORPrev) { }
	};

	Node* head = nullptr, * tail = nullptr;

	static Node* XOR(Node* a, Node* b) {
		return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
	}
public:
```
</details>


<details>
  <summary>Python</summary>
	TODO:
</details>

---

Когато се нуждаем да достъпим следващия елемент, прави XOR на запазената стойност с тази на адреса на предходния поинтър.
Пример с обхождане на целият лист.

<details>
  <summary>C++</summary>

```c++
template<typename T>
void XORLinkedList<T>::print() const {
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		std::cout << current->value << ' ';
		// current->nextXORPrev is XOR of prev and next
		// if xor it with prev we get next
		Node* next = XOR(prev, current->nextXORPrev);
		prev = current;
		current = next;
	}
}
```

</details>

<details>
  <summary>Python</summary>
	TODO:
</details>

---

Недостатъци:
- трудна за имплементация
- нуждаем се от предходен или следващ елемент за да итерираме. Тоест ако имаме просто указател към един node, не можем да тръгнем към предишен или следващ

Още за XOR linked list - https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/

## Skip list
- https://www.geeksforgeeks.org/skip-list/#:~:text=A%20skip%20list%20is%20a,determined%20through%20a%20probabilistic%20analysis.
- https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/skiplists.pdf

## Бонус задачи
- Linked list problems - http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
