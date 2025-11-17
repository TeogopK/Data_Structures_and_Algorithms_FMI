# Упражнение 6

## Днес ще разгледаме

- Дървета
- Двоични дървета
- Двоични дървета за търсене (BST)
- Алгоритми за обхождане на дървета
- Балансирани дървета

# Дървета

## Tree (Дърво)

- Дървовидна структура от данни (рекурсивна, нелинейна), която се състои от възли, подобно на свързания списък. Един възел може да има няколко наследника, но само 1 предшественик.
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
  
### Пример:

<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/e0124a48-86d1-49d1-8f56-a4f7b8c2bb8f" />

### Видове двоични дървета:

![image](https://github.com/user-attachments/assets/f9e7b30b-f94e-4a24-bd62-1257fcae67d6)


## Binary Search Tree (Двоично дърво за търсене)

- Дефинира се рекурсивно по следния принцип:
1. Всяко листо е двоично дърво за търсене.
2. Всяко поддърво започващо от даден възел е двоично дърво за търсене, ако:
    - Най-големият елемент в лявото му поддърво е по-малък от стойността в дадения възел.
    - Най-малкият елемент в дясното му поддърво е по-голям от стойността в дадения възел.
    - И лявото поддърво, и дясното поддърво са двоични дървета за търсене.

Примерно двоично дърво за търсене:

<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/589b8b94-17e4-46a0-8e5f-4d3bb51f99e2" />

## Представяне

### Интерфейс на Node

<details>
  <summary>C++</summary>

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

</details>

<details>
  <summary>Python</summary>

```python
class TreeNode:
    def __init__(self, value = None):
        self.left  = None
        self.right = None
        self.value = value

```

</details>


### Интерфейс на BST


<details>
  <summary>C++</summary>

```c++
template <typename T>
class BinarySearchTree {
private:
	Node<T>* root = nullptr;
public:
	BinarySearchTree() = default;
	BinarySearchTree(const BinarySearchTree<T>& other);
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);
	~BinarySearchTree() { free(); }

	bool contains(const T&) const;
	void insert(const T&);
	void remove(const T&);

	void dfs() const;
	void bfs() const;
};
```

</details>

<details>
  <summary>Python</summary>

```python
class BinarySearchTree:
    def __init__(self):
        self.root = None

    def contains(self, value):
        pass

    def insert(self, value):
        pass

    def remove(self, value):
        pass

    def dfs(self):
        pass

    def bfs(self):
        pass

```

</details>


### Представяне чрез Node
Най-често използваното. Всеки възел съдържа данни и указатели към левия и десния наследник. Позволява динамично добавяне/премахване на елементи и е естествено за рекурсивни алгоритми.

### Представяне на двоично дърво чрез масив
Индекс `i` има деца на `2*i+1` (ляво) и `2*i+2` (дясно). Често в LeetCode задачи.
Когато един Node е `null`, съответният индекс в масива също е `null`.

Ниво `k` е между индекси `[2^k - 1, 2^(k+1) - 2]`:
- Ниво 0 (корен): индекс 0
- Ниво 1: индекси [1, 2] (ляво и дясно дете на корена)
- Ниво 2: индекси [3, 6] (деца на ниво 1 - 4 на брой)
- Ниво 3: индекси [7, 14] (деца на ниво 2 - 8 на брой)

```c++
[1,2,3,null,5,null,4]
```

```python
[1, 2, 3, None, 5, None, 4]
```

<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/45da782c-8a8e-4144-8b00-040a67d69a47" />

## Представяне на двоично дърво чрез parent array
Масив, където индексът представлява възел, а стойността на този индекс е родителят на възела.

```
Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
// parent of 0(index) is 1
// parent of 1(index) is 5
// ...
          5
        /  \
       1    2
      /    / \
     0    3   4
         /
        6 
```

## Представяне на дърво чрез `vector<vector<int>>`
Структура, при която всеки възел се представя като вектор от децата му. Често се използва при задачи с произволни дървета (не непременно двоични), където броят наследници може да варира.

**Формат:** `vector<vector<int>> tree(N)`, където:
- `tree[i]` съдържа вектор от индексите на децата на възел `i`
- `N` е броят на възлите в дървото

**Пример:**

<details>
  <summary>C++</summary>

```cpp
vector<vector<int>> tree = {
    {1, 2},     // възел 0 има деца 1 и 2
    {3, 4},     // възел 1 има деца 3 и 4
    {5},        // възел 2 има дете 5
    {},         // възел 3 няма деца (листо)
    {},         // възел 4 няма деца (листо)
    {6},        // възел 5 има дете 6
    {}          // възел 6 няма деца (листо)
};
```

</details>

<details>
  <summary>Python</summary>

```python
tree = [
    [1, 2],     # възел 0 има деца 1 и 2
    [3, 4],     # възел 1 има деца 3 и 4
    [5],        # възел 2 има дете 5
    [],         # възел 3 няма деца (листо)
    [],         # възел 4 няма деца (листо)
    [6],        # възел 5 има дете 6
    []          # възел 6 няма деца (листо)
]
```

</details>


**Визуализация:**
```
          0
        /   \
       1     2
      / \    |
     3   4   5
             |
             6
```

**Типично използване:**

<details>
  <summary>C++</summary>

```cpp
// Построяване на дърво от ребра
vector<vector<int>> buildTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> tree(n);
    for (const auto& edge : edges) {
        int parent = edge[0];
        int child = edge[1];
        tree[parent].push_back(child);
    }
    return tree;
}

// DFS обхождане
void dfs(int node, const vector<vector<int>>& tree, vector<bool>& visited) {
    cout << node << " ";
    
    for (int child : tree[node]) {
        dfs(child, tree, visited);
    }
}
```

</details>

<details>
  <summary>Python</summary>

```python
# Построяване на дърво от ребра
def build_tree(n, edges):
    tree = [[] for _ in range(n)]
    for parent, child in edges:
        tree[parent].append(child)
    return tree

# DFS обхождане
def dfs(node, tree, visited):
    print(node, end=' ')
    
    for child in tree[node]:
        dfs(child, tree, visited)
```

</details>

## Добавяне, Търсене и премахване на елемент

### Търсене

Търсенето използва свойството на BST - елементите вляво са по-малки, вдясно по-големи. Сравняваме търсената стойност с текущия възел и рекурсивно продължаваме в съответното поддърво.

<details>
  <summary>C++</summary>

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

</details>

<details>
  <summary>Python</summary>

```python
def _contains(self, current, value):
    if not current:
        return False
    if current.val == value:
        return True
    if value < current.val:
        return self._contains(current.left, value)
    return self._contains(current.right, value)

def contains(self, value):
    return self._contains(self.root, value)

```
</details>


### Добавяне

Добавянето също използва свойството на BST. Сравняваме стойността с текущия възел и рекурсивно продължаваме в съответното поддърво, докато намерим празно място (nullptr), където да добавим новия възел. Връщайки се от рекурсията, всяка функция връща указател към текущия възел, така че да се поддържа връзката между родител и дете след добавянето.

<details>
  <summary>C++</summary>

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

</details>

<details>
  <summary>Python</summary>

```python
def _insert(self, current, value):
    if not current:
        return TreeNode(value)
    if value < current.val:
        current.left = self._insert(current.left, value)
    elif value > current.val:
        current.right = self._insert(current.right, value)
    return current

def insert(self, value):
    self.root = self._insert(self.root, value)

```

</details>

Как да се справим с повторения:
- Пазене на count в node
- Правим единия интервал включващ (т.е. от ляво на този Node да могат да седят само елементи <= на сегашния)

### Триене

Имаме 3 случая:
- трием възел без деца (изтриваме директно)
- трием възел с 1 дете (заместваме с детето)
- трием възел с 2 деца (заместваме с най-малкия от дясното поддърво (или най-големия от лявото) и рекурсивно го трием).

<details>
  <summary>C++</summary>

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

</details>


<details>
  <summary>Python</summary>

```python
def _remove(self, current, value):
    if not current:
        return None
    if value < current.val:
        current.left = self._remove(current.left, value)
    elif value > current.val:
        current.right = self._remove(current.right, value)
    else:
        if not current.left:
            return current.right
        if not current.right:
            return current.left
        temp = current.right
        while temp.left:
            temp = temp.left
        current.val = temp.val
        current.right = self._remove(current.right, temp.val)
    return current

def remove(self, value):
    self.root = self._remove(self.root, value)

```

</details>


## Алгоритми за обхождане
Примерите са показани за BST, но важат за всяко двоично дърво.

### Depth-first search (Обхождане в дълбочина)

Алгоритъмът започва от корена и обхожда колкото се може по-надълбоко в даден клон, преди да започне да се връща наобратно.

#### Inorder traversal
- Извежда във възходящ ред стойностите на двоично дърво за търсене.
- Схема: *Ляво - Корен - Дясно* 


<details>
  <summary>C++</summary>

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

</details>

<details>
  <summary>Python</summary>

```python
def inorder(current):
    if current is None:
        return
    
    inorder(current.left)
    print(current.val, end=' ') # 0 2 3 4 5 8 
    inorder(current.right)
```

</details>

#### Preorder traversal 
- Коренът е винаги първи.
- Схема: *Корен - Ляво - Дясно*

<details>
  <summary>C++</summary>

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

</details>

<details>
  <summary>Python</summary>

```python
def preorder(current):
    if current is None:
        return
    
    print(current.val, end=' ') # 3 2 0 5 4 8
    preorder(current.left)
    preorder(current.right)
```

</details>

#### Postorder traversal
  - Коренът е винаги последен. 
  - Схема: *Ляво - Дясно - Корен*


<details>
  <summary>C++</summary>

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

</details>

<details>
  <summary>Python</summary>

```python
def postorder(current):
    if current is None:
        return
    
    postorder(current.left)
    postorder(current.right)
    print(current.val, end=' ') # 0 2 4 8 5 3 
```

</details>

#### Iterative DFS
Обхождането в дълбочина може да се направи и без рекурсия чрез използването на стек:


<details>
  <summary>C++</summary>

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

</details>


<details>
  <summary>Python</summary>


```python
def iterative_inorder(root):
    stack = []
    current = root

    while stack or current:
        if current:
            stack.append(current) 
            current = current.left
        else:
            current = stack.pop()
            print(current.val, end=' ') # 0 2 3 4 5 8 
            current = current.right
```

#### Recursion limit
*Важно!* Възможно е да се увеличи ограничението за максимална дълбочина на рекурсия в Python, вместо да се пишат итеративни варианти на алгоритмите, чрез следния код:

```python
import sys
sys.setrecursionlimit(10_000)
```

</details>

### Breadth-first search (Обхождане в широчина)
- Нарича се още *Level order traversal*.
- Схема: *корен - дълбочина 1 - дълбочина 2 - ...*


<details>
  <summary>C++</summary>

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

</details>


<details>
  <summary>Python</summary>

```python
from collections import deque

def bfs(root):
    q = deque([root])
    level = 0

    while q:
        length = len(q)
        print(f"Level {level}:", end=' ')

        for _ in range(length):
            current = q.popleft()
            print(current.val, end=' ')

            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)

        print()
        level += 1
        
"""
Output:
Level 0: 3 
Level 1: 2 5 
Level 2: 0 4 8
"""
```

</details>

Разяснение на алгоритъма:
1. Обхожда първото ниво - корена, като добавя неговите наследници в опашка.
2. Преминава на следващото ниво - децата на корена. Текущият брой на елементите в опашката е броят на децата.
3. Премахва първия елемент от опашката (първото дете) и добавя неговите наследници ("внуците" на корена) в края на опашката.
4. Продължава да повтаря *стъпка 3*, докато не премине през всички деца от *стъпка 2*.
5. След преминаването през всички деца, в опашката се съдържат единствено върхове добавени от второто ниво - това са "внуците" на корена.
6. Стъпките се повтарят до изчерпване на възлите в дървото - когато се изпразни опашката с възли за обхождане.


## Сложности по време на BST

| Операция  | Worst case | Average case |
| --------- | ---------- | ------------ |
| търсене   | *O(N)*     | *Θ(logN)*    |
| добавяне  | *O(N)*     | *Θ(logN)*    |
| триене    | *O(N)*     | *Θ(logN)*    |
| обхождане | *O(N)*     | *Θ(N)*       |

**Notes:**
- N е броят на възлите
- Сложността зависи от баласираността на дървото!!!

## Имплементации

<details>
  <summary>C++</summary>

Няма вградено двоично дърво за търсене в stl. Ако искаме да ползваме такова, ще трябва да си го напишем сами. Имплементация може да намерите в папката [Implementations](./Implementations);

</details>

<details>
  <summary>Python</summary>

Няма вградено двоично дърво за търсене в Python. Ако искаме да ползваме такова, ще трябва да си го напишем сами. Примерна имплементация в [Playground-a](./playground_06.ipynb), и [TheAlgorithms Python](https://github.com/TheAlgorithms/Python/tree/master/data_structures/binary_tree)


</details>

## Балансирани дървета

### AVL tree (АВЛ дърво)

- Самобалансиращо се двоично дърво за търсене.
- Разликата във височината на лявото и дясното поддърво за всеки възел е по-малка или равна 1.
- Гарантирана *O(logN)* сложност в най-лошия случай при търсене, добавяне и триене на елемент.
- Балансиране е нужно при добавянето или триене на елемент, когато се наруши свойството за разлика във височините.

#### Визуализация на операциите по балансиране
![AVL tree operations GIF](https://upload.wikimedia.org/wikipedia/commons/f/fd/AVL_Tree_Example.gif)

### Различните случаи на дисбаланс и как се коригират чрез ротации:
<img width="600" height="500" alt="image" src="https://github.com/user-attachments/assets/b8e6487a-25c6-45f0-9e58-f33d055817a5" />

### Сравнение на структурите спрямо сложност по време

| операция | масив  | свързан списък | сортиран масив | двоично наредено дърво | балансирано двоично наредено дърво |
| -------- | ------ | -------------- | -------------- | ---------------------- | ---------------------------------- |
| търсене  | *O(N)* | *O(N)*         | *O(logN)*      | *O(N)*                 | *O(logN)*                          |
| добавяне | *O(N)* | *O(N)*         | *O(N)*         | *O(N)*                 | *O(logN)*                          |
| триене   | *O(N)* | *O(N)*         | *O(N)*         | *O(N)*                 | *O(logN)*                          |


### Balance Factor (Баланс фактор)

- За всеки възел: `BF = height(right) - height(left)`
- Балансирано дърво: `-1 <= BF <= 1`
- Дисбаланс: `|BF| > 1`

### 4-те случая на дисбаланс

**Забележка:** В примерите използваме конкретни стойности (31, 99, 133, които в кода отговарят на x, y, z) и обозначаваме поддърветата с T1, T2, T3, T4, за да покажем как те се преместват при ротация.

#### 1. Left-Left (LL) - Единична дясна ротация

**Кога възниква:** Добавяме в **лявото** поддърво на **лявото** дете.

```
      133 (BF = -2)                 99
      /  \T4                       /  \
     99 (BF = -1)      =>         31   133
    /  \                         / \   / \
   31   T2                      T1 T3 T2 T4
  / \
 T1  T3  <- новодобавен елемент е тук (в T1 или T3)
```

**Решение:** Right Rotation около 133

Поддърво **T2** се премества от дясно дете на 99 към ляво дете на 133.

<details>
  <summary>C++</summary>

```cpp
Node* rightRotate(Node* z) {  // z = 133
    Node* y = z->left;          // y = 99
    Node* T2 = y->right;        // T2

    y->right = z;
    z->left = T2;

    // Update heights
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; // new root (99)
}
```

</details>

<details>
  <summary>Python</summary>

```python
def right_rotate(z):  # z = 133
    y = z.left          # y = 99
    T2 = y.right        # T2

    y.right = z
    z.left = T2

    # Update heights
    z.height = 1 + max(height(z.left), height(z.right))
    y.height = 1 + max(height(y.left), height(y.right))

    return y  # new root (99)
```

</details>

---

#### 2. Right-Right (RR) - Единична лява ротация

**Кога възниква:** Добавяме в **дясното** поддърво на **дясното** дете.

```
      31 (BF = 2)                   99
     /  \                          /  \
    T1   99 (BF = 1)      =>      31   133
        /  \                     / \   / \
       T2  133                  T1 T2 T3 T4
          / \
         T3  T4  <- новодобавен елемент е тук (в T3 или T4)
```

**Решение:** Left Rotation около 31

Поддърво **T2** се премества от ляво дете на 99 към дясно дете на 31.

<details>
  <summary>C++</summary>

```cpp
Node* leftRotate(Node* x) {  // x = 31
    Node* y = x->right;        // y = 99
    Node* T2 = y->left;        // T2

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; // new root (99)
}
```

</details>

<details>
  <summary>Python</summary>

```python
def left_rotate(x):  # x = 31
    y = x.right       # y = 99
    T2 = y.left       # T2

    y.left = x
    x.right = T2

    # Update heights
    x.height = 1 + max(height(x.left), height(x.right))
    y.height = 1 + max(height(y.left), height(y.right))

    return y  # new root (99)

```

</details>

---

#### 3. Left-Right (LR) - Двойна ротация (ляво-дясна)

**Кога възниква:** Добавяме в **дясното** поддърво на **лявото** дете.

```
     133 (BF = -2)        133                  99
     /  \T4               /  \                /  \
    31 (BF = 1)   =>     99   T4      =>     31   133
   / \                  /  \                / \   / \
  T1 99                31   T3             T1 T2 T3 T4
    / \               / \
   T2  T3            T1  T2
       ^- новодобавен елемент е тук (в T2 или T3)
```

**Решение:**

1. Left Rotation около 31 (x) - поддърво **T2** става дясно дете на 31
2. Right Rotation около 133 (z) - поддърво **T3** става ляво дете на 133

**Защо две ротации, а не просто right rotation на 133?**

Ако направим само Right Rotation на 133 - отново ще имаме същия дисбаланс, но от другата страна:

```text
     133                  31
     /  \T4              /  \
    31         =>       T1   133
   / \                      /  \
  T1  99                   99   T4
     / \                  / \
    T2  T3               T2  T3
```

<details>
  <summary>C++</summary>

```cpp
Node* leftRightRotate(Node* z) {  // z = 133
    z->left = leftRotate(z->left);  // leftRotate(31)
    return rightRotate(z);           // rightRotate(133) -> връща 99
}
```

</details>

<details>
  <summary>Python</summary>

```python
def left_right_rotate(z):  # z = 133
    z.left = left_rotate(z.left)  # left_rotate(31)
    return right_rotate(z)         # right_rotate(133) -> връща 99
```

</details>

---

#### 4. Right-Left (RL) - Двойна ротация (дясно-лява)

**Кога възниква:** Добавяме в **лявото** поддърво на **дясното** дете.

```
   31 (BF = 2)             31                    99
   /  \                   /  \                  /  \
  T1   133 (BF = -1) =>  T1   99       =>     31   133
      /  \                   /  \            / \   / \
     99   T4                T2  133         T1 T2 T3 T4
    / \                        /  \
   T2  T3                     T3   T4
   ^- новодобавен елемент е тук (в T2 или T3)
```

**Решение:**

1. Right Rotation около 133 (z) - поддърво **T3** става ляво дете на 133
2. Left Rotation около 31 (x) - поддърво **T2** става дясно дете на 31

<details>
  <summary>C++</summary>

```cpp
Node* rightLeftRotate(Node* x) {  // x = 31
    x->right = rightRotate(x->right);  // rightRotate(133)
    return leftRotate(x);               // leftRotate(31) -> връща 99
}
```

</details>

<details>
  <summary>Python</summary>

```python
def right_left_rotate(x):  # x = 31
    x.right = right_rotate(x.right)  # right_rotate(133)
    return left_rotate(x)             # left_rotate(31) -> връща 99
```

</details>

---

### Алгоритъм за балансиране при Insert

<details>
  <summary>C++</summary>

```cpp
Node* insert(Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left),
                           height(node->right));

    // 3. Get the balance factor of this ancestor node
    int balance = getBalance(node);

    // 4. If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance < -1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance > 1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance < -1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance > 1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->right) - height(node->left) : 0;
}
```

</details>

<details>
  <summary>Python</summary>

```python
def insert(node, key):
    # 1. Perform the normal BST insertion
    if not node:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    elif key > node.key:
        node.right = insert(node.right, key)
    else:
        return node  # Equal keys not allowed

    # 2. Update height
    node.height = 1 + max(height(node.left), height(node.right))

    # 3. Get balance factor
    balance = get_balance(node)

    # 4. Balance cases
    # Left Left Case
    if balance < -1 and key < node.left.key:
        return right_rotate(node)

    # Right Right Case
    if balance > 1 and key > node.right.key:
        return left_rotate(node)

    # Left Right Case
    if balance < -1 and key > node.left.key:
        node.left = left_rotate(node.left)
        return right_rotate(node)

    # Right Left Case
    if balance > 1 and key < node.right.key:
        node.right = right_rotate(node.right)
        return left_rotate(node)

    return node


def height(node):
    return node.height if node else 0


def get_balance(node):
    return height(node.right) - height(node.left) if node else 0

```

</details>

### Запомняне по картинка

```
    LL (Left-Left):        LR (Left-Right):
         z                      z
        /                      /
       y                      y
      /                        \
     x                          x
     
    Форма:  /                Форма: <
           /                        >
    
    
    RR (Right-Right):      RL (Right-Left):
    z                           z
     \                           \
      y                           y
       \                         /
        x                       x
        
    Форма: \                Форма: >
            \                      <
```

Правило:
- Права линия (LL, RR) → 1 ротация
- Начупена линия (LR, RL) → 2 ротации (първо изправяме, после завъртаме)


### Имплементации в C++ и Python

Няма вградено балансирано двоично дърво за търсене в Python.
Структурите *set* и *dict* използват *Hash table*. Може да разгледате външата библиотека [Python Sorted Containers](https://grantjenks.com/docs/sortedcontainers/), която обаче не използва BST.

Примерна имплементация [AVL Tree in Python](https://github.com/TheAlgorithms/Python/blob/master/data_structures/binary_tree/avl_tree.py) и [Red-Black Tree in Python](https://github.com/TheAlgorithms/Python/blob/master/data_structures/binary_tree/red_black_tree.py).

В C++ съществуват *ordered* варианти на горните колекции, които подреждат елементите/ ключовете по-големина. При обхождане на структурите последователността е *inorder*.
Това са структурите *[set](https://en.cppreference.com/w/cpp/container/set.html)*, *[map](https://en.cppreference.com/w/cpp/container/map.html)*, *[multiset](https://en.cppreference.com/w/cpp/container/multiset.html)* и *[multimap](https://en.cppreference.com/w/cpp/container/multimap.html)*.
"Behind the scenes" работят с червено-черни дървета.

<details>
  <summary>C++ Map and Set</summary>

#### Map
- Структура key - value
- Key е уникален
- Дървото е сортирано по key
- Операции: `insert()`, `erase()`, `find()`, `[]` - всички *O(logN)*
- Пример за използване:
  ```cpp
  std::map<int, string> m;
  // Map with custom comparator (за низходящ ред по ключ)
  // Може да дадете и собствен компаратор
  // std::map<int, string, std::greater<int>> m_desc;
  
  m[1] = "one";
  m.insert({2, "two"});
  m[3] = "three";
  
  // Търсене
  if (m.find(1) != m.end()) { /* намерен */ }
  
  // Премахване
  m.erase(2);  // по ключ
  auto it = m.find(3);
  if (it != m.end()) {
      m.erase(it);  // по итератор
  }
  
  // Итериране (в сортиран ред по ключ)
  for (const auto& [key, value] : m) {
      std::cout << key << ": " << value << "\n";
  }
  ```

#### Set
- Структура от уникални елементи
- Дървото е сортирано по елементите
- Операции: `insert()`, `erase()`, `find()`, `count()` - всички *O(logN)*
- Пример за използване:
  ```cpp
  std::set<int> s;
  // Set with custom comparator (за низходящ ред)
  // Може да дадете и собствен компаратор
  // std::set<int, std::greater<int>> s_desc;

  s.insert(5);
  s.insert(3);
  s.insert(8);
  
  // Търсене
  if (s.count(5)) { /* съществува */ }
  
  // Премахване
  s.erase(3);  // по стойност
  auto it = s.find(8);
  if (it != s.end()) {
      s.erase(it);  // по итератор
  }
  
  // Итериране (в сортиран ред)
  for (int val : s) {
      std::cout << val << " ";
  }
  ```

</details>

# Задачи

## За упражнение на основните техники
- [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
  - рекурсивно и итеративно
- [Insert into a BST](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
  - рекурсивно и итеративно
- [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)
- Traversals (първите 3 "невидимо" ползват стек)
  - [inorder](https://leetcode.com/problems/binary-tree-inorder-traversal/)
  - [postorder](https://leetcode.com/problems/binary-tree-postorder-traversal/)
  - [preorder](https://leetcode.com/problems/binary-tree-preorder-traversal/)
  - [level order](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [Validate BST](https://leetcode.com/problems/validate-binary-search-tree/) - Medium
  - с допълнителна памет
  - без допълнителна памет
- [Binary Tree Right side view](https://leetcode.com/problems/binary-tree-right-side-view/)
	- bfs
 	- dfs
- [Maximum depth of binary tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

## Още задачи за дървета

### Easy
- [Same Tree](https://leetcode.com/problems/same-tree/)
- [Symetric Tree](https://leetcode.com/problems/symmetric-tree/)
- [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
- [Diameter of a binary tree](https://leetcode.com/problems/diameter-of-binary-tree/description/)

### Medium
- [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)
- [Lowest Common Ancestor of Deepest Leaves](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)
- Имаме дърво с уникални числа на всеки Node. Като вход ще получим много заявки за проверка дали един Node е наследник на друг. Заявките са от вида 1 наследник ли е на 3.
	- бавно решение - всеки път проверка
    - entry и exit time

<details>
	<summary>Explanation</summary>

```
      1
     / \
    2   3
   /   / \
  4   5   6

// entry and exit times (of the dfs operation) of every node
      1 (en:1, ex:12)
     /             \
  2 (2,5)          3 (6,11)
  /                /      \
4(3,4)            5(7,8)   6(9,10)

// x is descendant of y if entry[y] < entry[x] && exit[x] < exit[y]
```

</details>


## Задачи за Map и Set
- [Volleyball friends](https://www.hackerrank.com/contests/sda-hw-8/challenges/volleyball-friends)
- [Smallest number in infinite set](https://leetcode.com/problems/smallest-number-in-infinite-set/description/)
- [Continuous subarrays](https://leetcode.com/problems/continuous-subarrays/description/)

# Бонус
- Имплементиране на итератор на дърво
  - **Hint** - Stack
  - forward iter - https://www.geeksforgeeks.org/implement-binary-search-treebst-iterator/
  - [Binary search tree iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/?envType=problem-list-v2&envId=design)


## Бонус: Red-Black tree (Червено-черно дърво)

- Отново гарантира *O(logN)* сложност в най-лошия случай при търсене, добавяне и триене на елемент.
- Операциите добавяне и триене на елемент не изискват толкова често балансиране, поради по-малката строгост в поддържането на баланс спрямо AVL дърво.
- [wiki](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)

Свойства:
- Коренът е винаги черен.
- Всяко листо е черно (NIL leaf).
- Децата на червен възел са винаги черни.
- Всеки директен път от корен на поддърво до всяко листо в поддървото (NIL leaf) минава през равен брой черни възли.

Следствие:
- Родителят на червен възел е винаги черен.
- Връх с един наследник е винаги червен.

<img width="500" height="400" alt="Example of Red-Black tree" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/Red-black_tree_example_with_NIL.svg/1920px-Red-black_tree_example_with_NIL.svg.png" />

