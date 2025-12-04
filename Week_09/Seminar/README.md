
# Упражнение 9

# Динамично програмиране

Динамично програмиране е алгоритмична техника, при която решаваме сложен проблем като го разделяме на подпроблеми и запазваме резултатите им.
Основата идея е всеки подпроблем да бъде решен точно веднъж и неговият резултат да бъде запазен в случай, че се нуждаем от него отново. С тази оптимизация можем да намалим сложността на някои алгоритми от експоненциална на полиномиална.

Техниката за запазване на вече получени резултати се нарича **мемоизация**. С тази техника печелим бързодействие откъм действие за сметка на памет. 

За разлика от задачите "разделяй и владей", в случая на динамичното програмиране подпроблемите се препокриват (поради което запазваме резултатите им).

Една от дилемите на програмирането - [Space-time tradeoff](https://en.wikipedia.org/wiki/Space%E2%80%93time_tradeoff)

## Кога една задача се решава с динамично програмиране?
Има две основни характеристики на проблеми, които предполагат, че задача може да се реши с динамично програмиране:
- (Optimal Substructure) Когато оптималното решение на задачата, може да се намери чрез оптималните решения на неговите подзадачи, вместо да се опитат всички възможни варианти.
- (Overlapping Subproblems) Някои подзадачи трябва да бъдат пресметнати повече от веднъж, за да се реши финалният проблем.

Обикновено такива задачи търсят:
- Максимална/минимална стойност
- Брой начини да се направи нещо

## Компоненти

### State
Математическа функция, която съдържа отговора на дадена задача.

По по-прост начин казано, това е функция, която ни дава отговора на дадена задача и запазва този отговора в контейнер. При повторно извикване ни дава директно кешираната стойност.

### База
Начални стойности на нашия state.

### Рекурентна зависимост
Рекурентна зависимост е уравнение, което изразява state-a, чрез предишни негови стойности.


## Подходи
### Top-Down approach
Започваме от проблемът, който искаме да решим, разделяме го на подпроблеми, които искаме да решим, и така рекурсивно докато не стигнем базата. Имплементира се рекурсивно. С този подход пресмятаме само подпроблемите, които са ни нужни за финалния.

### Bottom-Up approach
Започваме да решаваме от най-малките проблеми и от тях постепенно решаваме по-големи, докато не решим финалния, който искаме. Имплементира се итеративно.
С този подход може да пресметнем резултатите на подпроблеми, които не са ни нужни за решаване на финалния. Полезен, когато се нуждаем от резултатите на всички подпроблеми.

## Стъпки за решаване на такъв тип задачи
- Измисляме state
- Измисляме рекурентната зависимост
- Пробваме

## Примери с основни задачи

### Пример с Фибоначи - Memoization

- State - *F(N)* - връща N-тото число на Фибоначи
- База - *F(1)* = 1, *F(2)* = 1
- Рекурентно уравнение - *F(N)* = *F(N - 1)* + *F(N - 2)*

Ето и рекурсивна имплементация на алгоритъма:

<details>
	<summary>C++</summary>

```c++
size_t fibonacci(size_t n) {
	if (n == 0 || n == 1) { // n == 0 - just to handle the zero edge case
		return n;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}
```
	
</details>

<details>
	<summary>Python TODO</summary>
	
</details>

В тази имплементация на многократно се извиква fibonacci с един и същ входен параметър по време на изпълнение на функцията. Забележете колко пъти се пресмята fibonacci(3)

![image](https://github.com/user-attachments/assets/09ba87c2-405a-44de-8fe9-e8272be891ec)

Затова можем да използваме **мемоизация** за да запазваме вече пресметнатите стойности и да не се налага да ги пресмятаме втори път.

<details>
	<summary>C++</summary>
	
```c++
size_t fibonacci(size_t n) {
	if (n == 0 || n == 1) {
		return n;
	}
	static size_t dp[1000]{};

	if (dp[n] == 0) {
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}

	return dp[n];
}
```

</details>

<details>
	<summary>Python TODO</summary>
</details>


В случая при извикване с n = 5, fibonacci(3) ще бъде пресметнато само първият път, а следващите пъти стойността ще бъде достъпвано директно от cache-a.

### Пример с Фибоначи - Tabulation

Същата задача може да бъде и решена като започнем да решаваме по-малките проблеми и надграждайки да стигнем до проблема, който искаме да решим.

<details>
	<summary>C++</summary>

```c++
long long fibonacci(size_t n) {
	if (n == 0 || n == 1) {
		return n;
	}

	long long prevPrev = 0, prev = 1, curr;
	for (size_t i = 2; i <= n; i++) {
		curr = prevPrev + prev;
		prevPrev = prev;
		prev = curr;
	}
	return curr;
}
```

</details>


<details>
	<summary>Python TODO</summary>
	
</details>

## Задачи с dp грид (матрица)
Пример - [Unique Paths](https://leetcode.com/problems/unique-paths/description/)

Задачи, при които state-a представлява матрица. Съответно тези задачи имат сложност от към памет O(n^2). Много често в тези гридове ни трябва само предишния ред спрямо текущия, следователно може да пазим само по два реда и да ги разменяме на всяка стъпка, което сваля паметта до O(n).

<details>
	<summary>C++</summary>

```c++
// O(n^2) memory
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 1));
 
	for(size_t i = 1; i < m; i++) {
		for(size_t j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
        
	return dp[m - 1][n - 1];
}


// O(n) memory
int uniquePaths(int m, int n) {
	vector<int> prev(n, 1);    

	for(int i = 1; i < m; ++i) {
		vector<int> curr(n, 1);
		for(int j = 1; j < n; ++j) {
			curr[j] = prev[j] + curr[j - 1];
		}
		prev = std::move(curr);
	}
    
	return prev[n - 1];
}

// O(n) smarter (works in some cases)
int uniquePaths(int m, int n) {
	vector<int> dp(n, 1);
	for(int i = 1; i < m; ++i) {
		for(int j = 1; j < n; ++j) {
			dp[j] += dp[j-1];
		}
	}

	return dp[n-1];
}
```

</details>


<details>
	<summary>Python TODO</summary>
	
</details>

## Още ресурси
- [reddit dp post](https://www.reddit.com/r/leetcode/comments/14o10jd/the_ultimate_dynamic_programming_roadmap/)
- [Algo monster](https://algo.monster/problems/dynamic_programming_intro)

## Задачи

### Easy
- [Fibonacci number](https://leetcode.com/problems/fibonacci-number/)
	- Подобни:
		- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
		- [Min cost Climbing stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

### Medium
- [Coin Change](https://leetcode.com/problems/coin-change/)
- [House Robber](https://leetcode.com/problems/house-robber/)
- [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)
	- Подобни:
		- [Unique Paths](https://leetcode.com/problems/unique-paths/description/)
		- [Unique Paths 2](https://leetcode.com/problems/unique-paths-ii/)
- [Triangle](https://leetcode.com/problems/triangle/description/)
- [Jump Game - Medium](https://leetcode.com/problems/jump-game/)

### Medium to hard
- [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
	- [wiki](https://en.wikipedia.org/wiki/Longest_common_subsequence)
	- [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/)
		- чрез рекурентна зависимост
		- чрез LCS
- 0/1 Knapsack problem
	- https://www.youtube.com/watch?v=xOlhR_2QCXY
- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

## Бонус
- [Minimum insertion steps to make a string palindrome - Hard](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)
	- коя задача можем да преизползваме за тази?
