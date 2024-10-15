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

В библиотеката има още много полезни функции, които може да разгледате.
