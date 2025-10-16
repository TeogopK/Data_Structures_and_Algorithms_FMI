
# Сложности

```c++
size_t fact(size_t n) {
	if (n == 0) {
		return 1;
	}

	return n * fact(n - 1);
}
```

Каква е разликата със следното:

```c++
size_t tailFactHelper(size_t n, size_t acc) {
	if (n == 0) {
		return acc;
	}
	return tailFactHelper(n - 1, n * acc);
}

size_t tailFact(size_t n) {
	return tailFactHelper(n, 1);
}
```

```c++
void towersOfHanoi(int n, char src, char aux, char dest) { 
    if (n == 1) { 
        cout << "Move disk 1 from " << src << " to " << dest << endl; 
        return; 
    } 

    towersOfHanoi(n - 1, src, dest, aux);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl; 
    towersOfHanoi(n - 1, aux, src, dest); 
}
```

```c++
https://www.geeksforgeeks.org/dsa/time-complexity-recursive-fibonacci-program/

size_t fibonacci(size_t n) { 
    if (n <= 1) {
        return n; 
    } 

	return fibonacci(n - 1) + fibonacci(n - 2); 
}
```
