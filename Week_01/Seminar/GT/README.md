# Преговор
- Locality
  - итериране на матрица по редове и колони

# Още за алгоритми
Какво е:
- Greedy algorithm
  	- пример с пътища
- Backtracking algorithm
	- пример с лабиринт

# Сложности. Изчисление на сложности. Примери

- Сложност по време - Best, Worst, Average, Amortized 

- Сложност по памет - Best, Worst, Average, Amortized 
  - in-place алгоритъм - алгоритъм, който работи директно върху подадените данни и не заделя допълнителна памет пропорционална на входа

Изчислете сложностите по време и по памет на следните алгоритми:

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
	
  Space Complexity: O(1)
  
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
  Time Complexity: O(n!)
	
  Space Complexity: O(1)
  
  Защо?
</details>

# Задачи
1. Number of Islands - Medium - https://leetcode.com/problems/number-of-islands/

2. Rotate array - Medium - https://leetcode.com/problems/rotate-array/
    - Bonus: solve with O(1) extra space and O(n) time

3. Single Number 1 - Easy - https://leetcode.com/problems/single-number/
    - Hint: Introduction to programming

4. Single Number 2 - Medium - https://leetcode.com/problems/single-number-ii/

5. Move zeroes - Easy - https://leetcode.com/problems/move-zeroes/

6. Plus one - Easy - https://leetcode.com/problems/plus-one/

7. Rotate image - Medium - https://leetcode.com/problems/rotate-image/

8. Container with most water - Medium - https://www.hackerrank.com/contests/practice-1-sda/challenges/challenge-2196/problem

    - leetcode - https://leetcode.com/problems/container-with-most-water/

9. Missing Bus Ticket 2(First missing positive number) - Hard - https://leetcode.com/problems/first-missing-positive/
    - First try to solve it with O(N) time and O(N) space (as we did in the last seminar)


# Quiz time

# Бонус:

Majority element - https://leetcode.com/problems/majority-element/?envType=problem-list-v2&envId=divide-and-conquer
- Boyer-Moore Majority Voting Algorithm

