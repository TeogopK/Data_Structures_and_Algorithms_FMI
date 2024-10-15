## Полезни функции от stl, които ще използваме

От библиотеката `algorithm`:

- [sort](https://en.cppreference.com/w/cpp/algorithm/sort)
  - Сортира елемените в подаден диапазон (by default нарастващ ред), не гарантира стабилност
  - Алгоритъм behind the scenes - в зависимост от имплементацията, но е комбинация от няколко сортировки
  - Optional comparator - Приема компаратор функция дефинирана от нас - функция, която получава два елемента и връща true, ако елементите са в правилна подредба.
    Функцията е задължителна, в случай, че данните ви нямат предефиниран operator<.

```c++
    sort(arr.begin(), arr.end());
    stable_sort(arr.begin(), arr.end());
    
    // подредба в намаляващ ред
    sort(v.begin(), v.end(), [](const int& a, const int& b) {
		return a > b;
	});
```

- [max_element](https://en.cppreference.com/w/cpp/algorithm/max_element) 
  - Приема итератори за начало и край
  - Optional comparator - Приема компаратор функция дефинирана от нас - функция, която получава два елемента и връща true, ако първият елемен е по-малък от вторият
  - връща итератор към най-големият елемент в [first, last). Ако няколко елемента изпълняват това условие, връща итератор към първия от тях.

```c++
*max_element(arr.begin(), arr.end()); // max element
*max_element(
    arr.begin(),
    arr.end(),
    [](const pair<int, string> &a, const pair<int, string> &b) { 
        return a.first < b.first; 
    })
```

- [min_element](https://en.cppreference.com/w/cpp/algorithm/min_element) - аналогично

В библиотеката има още много полезни функции, които може да разгледате. Пример за няколко такива:

```c++
    /* ALGORITHM */
    int vec_max = *max_element(vec.begin(), vec.end());                                // Get max element
    int vec_min = *min_element(vec.begin(), vec.end());                                // Get min element
    sort(vec.begin(), vec.end());                                                      // Sort
    stable_sort(vec.begin(), vec.end());                                               // Sort
    sort(vec.begin(), vec.end(), [](auto a, auto b) { return a > b; });                // Sort with custom function
    next_permutation(vec.begin(), vec.end());                                          // Get the next permutation
    replace(vec.begin(), vec.end(), 0, 42);                                            // Replace all occurrences of 0 with 42
    auto pivot_it = partition(vec.begin(), vec.end(), [](auto a) { return a < 15; });  // Partition and return iterator to pivot
    nth_element(vec.begin(), vec.begin() + 2, vec.end());                              // Rearrange elements so nth is the pivot
    int count_42s = count(vec.begin(), vec.end(), 42);                                 // Count the occurrences of 42
    auto first_42 = find(vec.begin(), vec.end(), 42);                                  // Iterator to the first occurrence of 42
    auto vec_lower = lower_bound(vec.begin(), vec.end(), 42);                          // Iterator to the first element >= 42
    auto vec_upper = upper_bound(vec.begin(), vec.end(), 42);                          // Iterator to the first element > 42
    bool found_42 = binary_search(vec.begin(), vec.end(), 42);                         // True if 42 exists in the sorted collection
    // Shuffle
    std::random_device dev;
    std::mt19937 g(dev());
    shuffle(vec.begin(), vec.end(), g);  // Shuffle array
```
