# Упражнение 1

# Въведение в курса

## Като за начало
- [СДА опознавателна анкета](https://forms.gle/WVVaFzSLQ7MQLGi28)

## Защо са важни Структурите от данни и алгоритми?

- Интервюта за работа, "whiteboard interviews"
  - Анализиране на проблем
  - Разработване на решение
  - Извличане на тестови сценарии
  - Тестване на решението
  - Оценка на решението
  
- Придобиване на разбиране за това как са имплементирани готовите структури в езика, които използваме ежедневно. Така можем да оценим:
  - каква е тяхната очаквана производителност?
  - как скалират при нарастване на данните?

- Развиване на способност за оценка на сложността на даден алгоритъм. Възможност за разграничаване на бързи и бавни решения на даден проблем.

## Приложения в реалния свят:
- Google Maps
- Internet
- Google, търсачки
- ДНК

## Как ще се провеждат домашните?
- В платформата [HackerRank](https://www.hackerrank.com/).
- Предварително зададени тестови.
- Автоматично оценяване на решения.
- Неограничен брой опити за предаване на решение.
- Получавате точки от най-високия резултат, получен от някое решение.
- Дори решението да не покрива 100% от тестовете, получавате точките за тестовете, които покривате.
- Автоматичните тестове не могат да се виждат преди да е приключило домашното.
- Възможност за собствено тестване преди предаване.

## Как се работи с HackerRank?
Различните грешки при изпълнение на автоматичен тест:
- Wrong Answer - Логическа грешка в алгоритъма.
- Runtime error - Синтактична грешка в кода, възникване на изключение.
- Terminated due to timeout - Бавен, неподходящ алгоритъм.
- Memory limit - Изчерпване на паметта.
- Abort called - Грешка от ниско ниво (C++ препълване на стека).

## Особености на C++

### Размер на типовете данни

| Data Type   | Size    | Size (bits) | Signed Value Range                                       | Unsigned Value Range            |
| ----------- | ------- | ----------- | -------------------------------------------------------- | ------------------------------- |
| `char`      | 1 byte  | 8 bits      | -128 to 127                                              | 0 to 255                        |
| `bool`      | 1 byte  | 8 bits      | `true` (1) or `false` (0)                                | N/A                             |
| `short`     | 2 bytes | 16 bits     | -32,768 to 32,767                                        | 0 to 65,535                     |
| `int`       | 4 bytes | 32 bits     | -2,147,483,648 to 2,147,483,647                          | 0 to 4,294,967,295              |
| `long`      | 4 bytes | 32 bits     | -2,147,483,648 to 2,147,483,647                          | 0 to 4,294,967,295              |
| `long long` | 8 bytes | 64 bits     | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807  | 0 to 18,446,744,073,709,551,615 |
| `float`     | 4 bytes | 32 bits     | Approximately ±3.4E−38 to ±3.4E+38 (7 decimal places)    | N/A                             |
| `double`    | 8 bytes | 64 bits     | Approximately ±1.7E−308 to ±1.7E+308 (15 decimal places) | N/A                             |

Формулите са: от -2<sup>n-1</sup> до 2<sup>n-1</sup> - 1 за *signed* типовете, и от 0 до 2<sup>n</sup> - 1 за *unsigned* типовете, където n е броят битове.

### Припомняне на концепции от Увод в програмирането
Чудесно място за преговаряне на основните теми [УП репото на Г. Йоков и M. Илиев](https://github.com/SinestroWhite/Introduction-To-Programming)

- [Масиви](https://drive.google.com/file/d/1NNkObHSMl1Q1S662kCwlVJDJFr4mc6L9/view) и [Многомерни масиви](https://drive.google.com/file/d/1KAkYQEMB7zz0G2V9d7v6JBJX4W7WEOm0/view)
- [Референции](https://drive.google.com/file/d/1XEC9ECvcOFD7RN_O3ks3rEx-PQOq-p7q/view) и [Пойнтъри](https://drive.google.com/file/d/1iuYRTiykAXkQZ6x24VNRncndfKxFX4UF/view)
- [Видове памет](https://drive.google.com/file/d/1eGU0bzZOcPqcAOYkTi_AOFgTO3jZrTyS/view)
- [Рекурсия](https://drive.google.com/file/d/1ltVRg7LSUHess_2QAXH-lgSj1jbFOelP/view)

### STL библиотеката
- [STL vector](https://drive.google.com/file/d/1Sw78-R0GoyI86zsqB90BSLPqH-tiW3D4/view)
- [STL string](https://drive.google.com/file/d/1EcTh7k-ldd3d9kXWoitstyYgC-ydGp5A/view)

---

## Задачи за запознаване с платформите HackerRank и LeetCode

- [Solve Me First](https://www.hackerrank.com/challenges/solve-me-first/problem)
- [Simple Array Sum](https://www.hackerrank.com/challenges/simple-array-sum/problem)
- [Roommates](https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/1-410)
- [Two sum](https://leetcode.com/problems/two-sum/)
