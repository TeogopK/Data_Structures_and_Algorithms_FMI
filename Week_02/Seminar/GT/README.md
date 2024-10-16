# Преговор
- сравнение на сложности log 2 N vs log 3 N
- сравнение на сложности - 2^n vs 3^n

# Сортиращи алгоритми
- Основната информация я има добре описана в общото readme
- Разглеждане на имплементациите на алгоритмите

# Допълнителни примери и въпроси
- Стабилност use cases - губим първоначалният ред. Пример със студенти и оценки.
- Наивен Insertion
- Наивен Merge
- Защо сложността на merge sort е N*logN?
- Много чест пропуск - рекурсивните извиквания също заемат памет
- Кога се стига до worst case на quick - да изберете най-малкото или най-голямото
- Защо за малки масиви е полезен insertion sort?
   - Ползва локалити(мести елементи един до друг)
   - Няма рекурсивни извиквания - O(1) памет
   - прави отмествания вместо swap
   - Адаптивен. Малките масиви са много често почти сортирани.

# Допълнително
- някои имплементации на std::sort - https://en.wikipedia.org/wiki/Introsort
- Bucket sort
- Radix sort

# Съвет при решаване на задачи
Ако ще правим много различни заявки върху масив (пример: q1: дай ми най-големия елемен, q2: дай ми четвъртия по големина, q3...), може да е по-оптимално той да бъде предварително сортиран

# Задачи
Merge sorted arrays - Easy - https://leetcode.com/problems/merge-sorted-array/

Contains duplicate - Easy - https://leetcode.com/problems/contains-duplicate/

Find the difference - Easy - https://leetcode.com/problems/find-the-difference/

Squares of a Sorted array - Easy - https://leetcode.com/problems/squares-of-a-sorted-array/
   - O(n*log n) и O(1)
   - O(n) и O(n)

Intersection of two arrays 2 - Easy - https://leetcode.com/problems/intersection-of-two-arrays-ii/

Maximum product of three numbers - Easy - https://leetcode.com/problems/maximum-product-of-three-numbers/

Quick select (k-th element) - Medium - https://leetcode.com/problems/kth-largest-element-in-an-array/

Non-overlapping Intervals - Medium - https://leetcode.com/problems/non-overlapping-intervals/

Sort characters by frequency - Medium - https://leetcode.com/problems/sort-characters-by-frequency/

Merge Intervals - Medium - https://leetcode.com/problems/merge-intervals/

# Бонус

Ред в хаоса - https://www.hackerrank.com/contests/sda-test1-2022-2023/challenges/challenge-3676/problem
