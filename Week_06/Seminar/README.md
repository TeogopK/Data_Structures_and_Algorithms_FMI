# Упражнение 6

# Дървета

## Днес ще разгледаме

- Дървета
- Двоични дървета
- Двоични дървета за търсене (BST)
- Алгоритми за обхождане на дървета

## Tree (Дърво)

- Дървовидна структура от данни(Рекурсивна), която се състои от възли, подобно на свързания списък. Един възел може да има няколко наследника, но само 1 предшественик.
- Дървото се характеризира с липсата на цикли - *Ацикличен свързан граф*.
- Възли без наследници се наричат *листа*.
- Коренът на дървото е възелът без нито един предшественик.

Допълнителни свойства и дефиниции за дърветата:
- Ребро - връзка между двата върха
- Броят на възлите = Броят на ребрата + 1 (|V| = |E| + 1)
- Разклоненост - максималният брой върхове наследници, които може да има връх в едно дърво
- Път - поредица от ребра между върхове
- Листо - възел без наследници
- Дълбочина - дължината на пътя от корена до върха
- Височина на дърво - максималната дълбочина

Още дефиниции може да намерите [тук](https://bg.wikipedia.org/wiki/%D0%94%D1%8A%D1%80%D0%B2%D0%BE_(%D0%BC%D0%B0%D1%82%D0%B5%D0%BC%D0%B0%D1%82%D0%B8%D0%BA%D0%B0))

## Binary Tree (Двоично дърво)

- Дърво, чиито възли имат най-много двама наследника. Най-често се обозначават ляв и десен (left, right).
  
Пример:

![binary_tree_example](https://github.com/user-attachments/assets/d12d373f-5761-41c8-9f0b-99cd0d84a1f7)

## Binary Search Tree (Двоично дърво за търсене)

- Дефинира се рекурсивно по следния принцип:
1. Всяко листо е двоично дърво за търсене.
2. Всяко поддърво започващо от даден възел е двоично дърво за търсене, ако:
    - Най-големият елемент в лявото му поддърво е по-малък от стойността в дадения възел.
    - Най-малкият елемент в дясното му поддърво е по-голям от стойността в дадения възел.
    - И лявото поддърво, и дясното поддърво са двоични дървета за търсене.

Примерно двоично дърво за търсене:

![binary_search_tree](https://github.com/user-attachments/assets/55282c42-4819-4fef-9d0a-75e900fc06c8)

## Представяне

- Интерфейс на Node

```c++
template <typename T>
struct Node {
	T value;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(const T& value, Node* left = nullptr, Node* right = nullptr)
		: value(value), left(left), right(right) { }
	// some more stuff here
};
```

- Интерфейс на BST

```c++
template <typename T>
class BinarySearchTree {
private:
	Node<T>* root = nullptr;
public:
	BinarySearchTree() = default;
	BinarySearchTree(const BinarySearchTree<T>& other) = delete;
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other) = delete;
	~BinarySearchTree() { free(); }

	bool contains(const T&) const;
	void insert(const T&);
	void remove(const T&);

	void dfs() const;
	void bfs() const;
};
```

- друг вариант за представяне на двоично дърво (често го има в примерите в leetcode)
```c++
[1,2,3,null,5,null,4]
```
![image](https://github.com/user-attachments/assets/22c7d5d1-e0d5-4c89-a3ba-70e148e6481c)

## Сложности на BST

- Сложността зависи от баласираността на дървото.

| Операция | Worst case | Average case |
| --- | --- |  --- |
| търсене | *O(N)* | *Θ(logN)* |
| добавяне | *O(N)* | *Θ(logN)* |
| триене | *O(N)* | *Θ(logN)* |
| обхождане | *O(N)* | *Θ(N)* |

- Където N е броят на възлите

## Добавяне, Търсене и премахване на елемент

### Търсене

```c++
template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
	return _contains(root, value);
}

template <typename T>
bool BinarySearchTree<T>::_contains(const Node<T>* current, const T& value) const {
	if (!current) {
		return false;
	}

	if (current->value == value) {
		return true;
	}

	return current->value > value ? contains(current->left, value) : contains(current->right, value);
}
```

### Добавяне
```c++
template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
	root = _insert(root, value);
}

template <typename T>
Node<T>* BinarySearchTree<T>::_insert(Node<T>* current, const T& value) {
	if (!current) {
		return new Node<T>(value);
	}

	if (current->value < value) {
		current->right = _insert(current->right, value);
	}
	else if (value < current->value) {
		current->left = _insert(current->left, value);
	}

	return current;
}
```

Как да се справим с повторения:
- Пазене на count в node
- Правим единия интервал включващ (т.е. от ляво на този Node да могат да седят само елементи <= на сегашния)

### Триене
```c++
template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
	root = _remove(root, value);
}

template <typename T>
Node<T>* BinarySearchTree<T>::_remove(Node<T>* current, const T& value) {
	if (!current) {
		return nullptr;
	}

	if (value < current->value) {
		current->left = _remove(current->left, value);
	}
	else if (current->value < value) {
		current->right = _remove(current->right, value);
	}
	else {
		if (!current->left && !current->right) {
			return nullptr;
		}
		if (!current->left) {
			return current->right;
		}
		if (!current->right) {
			return current->left;
		}

		Node<T>* iter = current->right;
		while (iter->left) {
			iter = iter->left;
		}

		current->value = iter->value;
		current->right = _remove(current->right, current->value);
	}

	return current;
}
```

## Алгоритми за обхождане
Примерите са показани за BST, но важат за всяко двоично дърво.

### Depth-first search (Обхождане в дълбочина)

Алгоритъмът започва от корена и обхожда колкото се може по-надълбоко в даден клон, преди да започне да се връща наобратно.

#### Inorder traversal
- Извежда във възходящ ред стойностите на двоично дърво за търсене.
- Схема: *Ляво - Корен - Дясно* 

```c++
template <typename T>
void BinarySearchTree<T>::inorder(const Node<T>* current) const {
	if (!current) {
		return;
	}

	inorder(current->left);
	std::cout << current->value << " "; // 0 2 3 4 5 8 
	inorder(current->right);
}
```

#### Preorder traversal 
- Коренът е винаги първи.
- Схема: *Корен - Ляво - Дясно*

```c++
template <typename T>
void BinarySearchTree<T>::preorder(const Node<T>* current) const {
	if (!current) {
		return;
	}

	std::cout << current->value << " "; // 3 2 0 5 4 8
	preorder(current->left);
	preorder(current->right);
}
```

#### Postorder traversal
  - Коренът е винаги последен. 
  - Схема: *Ляво - Дясно - Корен*

```c++
template <typename T>
void BinarySearchTree<T>::postorder(const Node<T>* current) const {
	if (!current) {
		return;
	}

	postorder(current->left);
	postorder(current->right);
	std::cout << current->value << " "; // 0 2 4 8 5 3
}
```

#### Iterative DFS
Обхождането в дълбочина може да се направи и без рекурсия чрез използването на стек:

```c++
template <typename T>
void BinarySearchTree<T>::iterativeDfs() const { // inorder
	std::stack<Node<T>*> stack;
	Node<T>* current = root;

	while (current != nullptr || !stack.empty()) {
		while (current != nullptr) {
			stack.push(current);
			current = current->left;
		}

		current = stack.top();
		stack.pop();
		std::cout << current->value << " ";
		current = current->right;
	}
}
```

### Breadth-first search (Обхождане в широчина)
- Нарича се още *Level order traversal*.
- Схема: *корен - дълбочина 1 - дълбочина 2 - ...*

```c++
template <typename T>
void BinarySearchTree<T>::bfs() const {
	std::queue<Node<T>*> container;
	container.push(root);

	while (!container.empty()) {
		size_t levelSize = container.size();
		while (levelSize > 0) {
			Node<T>* current = container.front();
			container.pop();

			if (current) {
				std::cout << current->value << " ";
				container.push(current->left);
				container.push(current->right);
			}
			levelSize--;
		}
		std::cout << std::endl;
	}
}
```

Разяснение на алгоритъма:
1. Обхожда първото ниво - корена, като добавя неговите наследници в опашка.
2. Преминава на следващото ниво - децата на корена. Текущият брой на елементите в опашката е броят на децата.
3. Премахва първия елемент от опашката (първото дете) и добавя неговите наследници ("внуците" на корена) в края на опашката.
4. Продължава да повтаря *стъпка 3*, докато не премине през всички деца от *стъпка 2*.
5. След преминаването през всички деца, в опашката се съдържат единствено върхове добавени от второто ниво - това са "внуците" на корена.
6. Стъпките се повтарят до изчерпване на възлите в дървото - когато се изпразни опашката с възли за обхождане.

## Имплементации в C++

Няма вградено двоично дърво за търсене в stl.
Ако искаме да ползваме такова, ще трябва да си го напишем сами.
Имплементация може да намерите в папката [Implementations](./Implementations);

# Задачи

## За упражнение на основните техники
- [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) - Easy
  - рекурсивно и итеративно
- [Insert into a BST](https://leetcode.com/problems/insert-into-a-binary-search-tree/) - Medium
  - рекурсивно и итеративно
- [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) - Medium
- [Validate BST](https://leetcode.com/problems/validate-binary-search-tree/) - Medium
  - с допълнителна памет и без
- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) - Easy
- Traversals (първите 3 "невидимо" ползват стек)
  - [inorder](https://leetcode.com/problems/binary-tree-inorder-traversal/) - Easy
  - [postorder](https://leetcode.com/problems/binary-tree-postorder-traversal/) - Easy
  - [preorder](https://leetcode.com/problems/binary-tree-preorder-traversal/) - Easy
  - [level order](https://leetcode.com/problems/binary-tree-level-order-traversal/) - Medium

## Други
- [Same Tree](https://leetcode.com/problems/same-tree/) - Easy
- [Symetric Tree](https://leetcode.com/problems/symmetric-tree/) - Easy
- [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/) - Easy
- [Binary Tree Right side view](https://leetcode.com/problems/binary-tree-right-side-view/) - Easy

# Бонус
- Имплементиране на итератор на дърво
  - **Hint** - Stack
  - forward iter - https://www.geeksforgeeks.org/implement-binary-search-treebst-iterator/
- [Trim BST](https://leetcode.com/problems/trim-a-binary-search-tree/) - Medium
- [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/) - Medium
