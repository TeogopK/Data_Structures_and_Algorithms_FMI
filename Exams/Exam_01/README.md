# Контролно 1 СДА 21.10.2025г.

## Задача 1 (7 * 20 точки)

Определете сложността откъм време и памет в най-лошия случай на всеки един от дадените фрагменти.
ЗАДЪЛЖИТЕЛНО обосновете отговора си в рамките на 1–2 изречения.

---

### 1.1)

```cpp
void f1(int n) {
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j++) {
			if (j > 0) {
				break;
			}
		}
	}
}
```

```python
def f1(n):
    for i in range(n):
        for j in range(i):
            if j > 0:
                break
```

*Отговор:* $O(N)$ време, $O(1)$ памет
Вътрешният цикъл се прекратява веднага, но това се случва $N$ пъти.

---

### 1.2)

```cpp
void f2(int n) {
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < 10; i++) {
			}
		}
	}
}
```

```python
def f2(n):
    for _ in range(n):
        for _ in range(n):
            for _ in range(10):
                pass
```

*Отговор:* $O(N^2)$ време, $O(1)$ памет
Най-вътрешният цикъл е фиксирани 10 операции: $O(10 \cdot N \cdot N) = O(N^2)$.

---

### 1.3)

```cpp
void f3(int n, int m) {
	for (int i = 1; i < n; i *= 2) {
		for (int j = 1; j < m; j++) {
	 	}
	}
}
```

```python
def f3(n, m):
    i = 1
    while i < n:
        for j in range(1, m):
            pass
        i *= 2
```

*Отговор:* $O(M \cdot \log N)$ време, $O(1)$ памет
Вътрешният цикъл прави $M$ операции, а външният цикъл се изпълнява $\log N$ пъти.

---

### 1.4)

```cpp
void f4(unsigned int n, unsigned int acc) {
	if (acc * acc >= n) {
		return;
	}

	return f4(n, acc + 1);
}
```

```python
def f4(n, acc):
    if acc * acc >= n:
        return
    return f4(n, acc + 1)
```

*Отговор:* $O(\sqrt{N})$ време, $O(\sqrt{N})$ памет
Рекурсията достига до $\sqrt{N}$, след което спира.

---

### 1.5)

```cpp
void test(int N, int K) {
	for (int i = 0; i < N; i++) {
		for (int i = 1; i < K; i *= 4) {
		}
	}
	for (int i = 0; i < N * N; i++) {
	}
}
```

```python
def f5(N, K):
    for i in range(N):
        j = 1
        while j < K:
            j *= 4
    for i in range(N * N):
        pass
```

*Отговор:* $O(N \cdot \log K + N^2)$ време, $O(1)$ памет
Двата отделни цикъла дават сумарна сложност: първи $O(N \cdot \log K)$, втори $O(N^2)$.

---

### 1.6)

```cpp
int f6(std::vector<int>& v, unsigned int index) {
	if (index == v.size()) {
		return 0;
	}

	return v[index] + f6(v, index + 1);
}
```

```python
def f6(v, index=0):
    if index == len(v):
        return 0
    return v[index] + f6(v, index + 1)
```

*Отговор:* $O(N)$ време, $O(N)$ памет
Рекурсивната функция обхожда всички елементи на масива.

---

### 1.7)

```cpp
long long f7(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 1) {
		return a * f7(a * a, b / 2);
	}
	return f7(a * a, b / 2);
}
```

```python
def f7(a, b):
    if b == 0:
        return 1
    if b % 2 == 1:
        return a * f7(a * a, b // 2)
    return f7(a * a, b // 2)
```

*Отговор:* $O(\log b)$ време, $O(\log b)$ памет
Рекурсията зависи само от $b$, който се дели на $2$ всяка стъпка.

---


## Задача 2 (условие)

Да се напише програма, която прочита от конзолата масив $\text{array}$ с $N$ цели числа и намира за всеки елемент колко на брой по-големи елемента от него има в масива.  
Програмата трябва да отпечата в конзолата нов масив $\text{result}$, за който е изпълнено:

$\text{result}[i] = \text{броя на елементите в } \text{array} \text{, които са по-големи от } \text{array}[i], \quad \forall i \in [0, N-1]$

*Вход:*

* Първи ред: число $N \in [1, 100000]$
* Втори ред: $N$ цели числа в интервала $[0, 1000]$

*Изход:*

* $N$ цели числа в конзолата

В рамките на две/три изречения обяснете сложността на вашето решение по време и по памет.

*Примерен вход и изход:*

| №   | Вход             | Изход     |
| --- | ---------------- | --------- |
| 1   | 5 <br> 8 1 2 2 3 | 0 4 2 2 1 |
| 2   | 4 <br> 6 5 4 8   | 1 2 3 0   |
| 3   | 4 <br> 7 7 7 7   | 0 0 0 0   |

*Решение*

<details>
<summary>C++</summary>
<br>

```cpp

```

</details>

<details>
<summary>Python</summary>
<br>

```python
def solve(nums, N)
	K = max(nums) + 1
	counts = [0] * K
	results = [0] * N

	# We count the occurences of each number
	for x in nums:
		counts[x] += 1
	
	# We start a cumulative sum from the end of the array
	for i in range(K - 2, 0, -1):
		counts[i] += counts[i + 1]

	# This way counts[i] shows how many numbers are bigger than the number i - 1
	# Except for the last number, that should not throw index out of range
	for i, x in enumerate(nums):
		results[i] = counts[x + 1] if x != K - 1 else 0 

	return results

N = int(input())
nums = [int(x) for x in input().split()]

results = solve(nums, N)
print(*results)
```

</details>

<details>
<summary>Алтернативен синтаксис Python</summary>
<br>

```python
# Alternative syntax solution
N = int(input())
nums = list(map(int, input().split()))

K = max(nums) + 1
counts = [0] * K
results = [0] * N

# We count the occurences of each number
for x in nums:
	counts[x] += 1

# We start a cumulative sum from the end of the array
for i in reversed(range(K - 1)):
	counts[i] += counts[i + 1]

# This way counts[i] shows how many numbers are bigger than the number i - 1
counts += [0]

for i, x in enumerate(nums):
	results[i] = counts[x + 1]

print(*results)
```
</details>