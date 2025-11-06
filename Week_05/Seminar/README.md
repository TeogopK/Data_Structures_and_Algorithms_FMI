# Упражнение 5

## Темата включва
- Queue
- Stack
- Deque
- Monotonic Stack
- Sliding window
- Задачи

## Queue
Опашката е абстрактен тип данни, която представлява колекция от елементи с три основни операции:

- push - която добавя елемент към колекцията
- pop - която премахва най-отдавна добавения елемент.
- peek - връща стойността на най-отдавна добавения елемент

Редът, по който елементите се добавят или премахват от опашката, се описва като „първи влязъл, първи излязъл“ (на английски: First In, First Out, или съкратено FIFO).

Може да бъде имплементиран чрез:
- Linked list
- Dynamic array (Circular)

### Сравнение на имплементациите
| Queue with       | Dynamic Array                      | Linked list      |
| ---------------- | ---------------------------------- | ---------------- |
| push()/enqueue() | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| pop()/dequeue()  | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| peek()/top()     | $\mathcal{O}(1)$                   | $\mathcal{O}(1)$ |
| clear()          | $\mathcal{O}(p)$ - delete memory   | $\mathcal{O}(n)$ |
| isEmpty()        | $\mathcal{O}(1)$                   | $\mathcal{O}(1)$ |
| initialize       | $\mathcal{O}(p)$ - allocate memory | $\mathcal{O}(1)$ |

[Stl queue documentation](https://en.cppreference.com/w/cpp/container/queue)

### Задачи
- [Number of recent calls](https://leetcode.com/problems/number-of-recent-calls/) - Easy
- [Rotting oranges](https://leetcode.com/problems/rotting-oranges/) - Medium

## Stack
Стек е абстрактен тип данни, който представлява колекция от елементи с три основни операции:

- push - която добавя елемент към колекцията
- pop - която премахва най-скоро добавения елемент.
- peek - връща стойността на последния добавен елемент

Редът, по който елементите се добавят или премахват от стека, се описва като „последен влязъл, първи излязъл“ (на английски: Last In, First Out, или съкратено LIFO).

Често срещани проблеми:
- Overflow - Препълване на стека. Добяване на твърде много елементи, които стекът не може да побере.
- Underflow - Опит за достъп на елемент от празен стек

Може да бъде имплементиран чрез:
- Linked list
- Dynamic array

И двете имплементации се постигат след като се изтрият няколко член-функции от стандартните имплементации на Linked list и Vector.

### Сравнение на имплементациите
| Stack with   | Dynamic Array                      | Linked list      |
| ------------ | ---------------------------------- | ---------------- |
| push()       | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| pop()        | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| peek()/top() | $\mathcal{O}(1)$                   | $\mathcal{O}(1)$ |
| clear()      | $\mathcal{O}(p)$ - delete memory   | $\mathcal{O}(n)$ |
| isEmpty()    | $\mathcal{O}(1)$                   | $\mathcal{O}(1)$ |
| initialize   | $\mathcal{O}(p)$ - allocate memory | $\mathcal{O}(1)$ |

[Stl stack documentation](https://en.cppreference.com/w/cpp/container/stack)

### Задачи
- [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) - Easy
- [Asteroid collision](https://leetcode.com/problems/asteroid-collision/) - Medium
- [Evaluate reverse polish notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) - Medium

## Deque (Double-ended queue)
Опашка с два края или дек е абстрактна структура от данни, която е подобна на опашката, но може да бъдат добавяни/премахни/преглеждани елементи и в двата края на структурата (front и back).

Може да бъде имплементиран чрез:
- Linked list
- Dynamic array (Circular)

| Stack with     | Dynamic Array                      | Linked list      |
| ------------   | ---------------------------------- | ---------------- |
| push_back()    | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| pop_back()     | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| push_front()   | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| pop_front()    | Amortized $\mathcal{O}(1)$         | $\mathcal{O}(1)$ |
| front()/back() | $\mathcal{O}(1)$                   | $\mathcal{O}(1)$ |
| clear()        | $\mathcal{O}(p)$ - delete memory   | $\mathcal{O}(n)$ |
| isEmpty()      | $\mathcal{O}(1)$                   | $\mathcal{O}(1)$ |
| initialize     | $\mathcal{O}(p)$ - allocate memory | $\mathcal{O}(1)$ |

[Stl deque documentation](https://en.cppreference.com/w/cpp/container/deque)

## Monotonic Stack

Monotonic stack е техника, използвана често за решаване на задачи тип - намиране на следващ по-голям/по-малък елемент в масив. Основната идея на монотонния стек е, че подреждаме елементите в стека така, че те да бъдат сортирани в монотонно нарастващ или монотонно намаляващ ред. Това означава, че когато добавяме нов елемент в стека, премахваме елементи, които нарушават реда.

```c++
void monotonicStackExample(const std::vector<int>& v) {
    // Нека v = {4, 1, 2, 6, 7, 3}
    // В стека можем да пазим стойности или индекси в зависимост от задачата. 
    // По името може да познаете какво пазим и какъв е типа на стека.
    std::stack<int> minMonotonicValues; 

    for(int i = 0; i < v.size(); i++) {
        while(!minMonotonicValues.empty() && minMonotonicValues.top() < v[i]) {
            minMonotonicValues.pop();
        }
        minMonotonicValues.push(v[i]);
    }

    /*
    В края на for цикъла при индекс i стека изглежда така:
    (върха на стека е най - десния елемент)
    i = 0 : [4]
    i = 1 : [4, 1]
    i = 2 : [4, 2]
    i = 3 : [6]
    i = 4 : [7]
    i = 5 : [7, 3]    
    */

    // credit: https://github.com/stoychoX/Data-structures-and-algorithms/
}
```
Какво можем да забележим от този пример? Примерно, вярно е, че при i = k максимума на подмасива [0..k - 1] е на дъното на стека.

### Задачи
- [Next greater element 2](https://leetcode.com/problems/next-greater-element-ii/description/) - Medium
- [Number of visible people in a queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/) - Hard
- [Next Greater Node in Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/) - Medium
- [Daily temperatures](https://leetcode.com/problems/daily-temperatures/) - Medium

## Sliding window
Sliding window е техника за оптимизация, използвана при задачи, в които трябва да се обработват подмасиви (или поднизове) с фиксирана или променлива дължина, разположени последователно в основния масив или низ. Тази техника ни помага да избегнем многократно пресмятане на едни и същи елементи, което я прави много ефективна за задачи като намиране на сума, средна стойност, максимум, минимум и други характеристики на подмасиви или низове.

Основната идея е вместо да пресмятаме стойностите за всеки подмасив отначало, да "плъзгаме" прозореца по масива, като добавяме нов елемент и премахваме стария(или не изпълняващи условието). Така обновяваме резултата само чрез добавяне и изваждане на малки промени, вместо да правим пресмятания от нулата за всяко ново положение.

### Задачи
- [Maximum average subarray 1](https://leetcode.com/problems/maximum-average-subarray-i/) - Easy
    - с queue
    - без queue
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) - Hard

<details>
  <summary>Визуализация на това как би трябвало да работи последната</summary>
    
  ![sliding_window_maximum](https://github.com/user-attachments/assets/2b728e60-4f88-4fcf-8296-12aaa448a880)
</details>

# Бонус
- [Min stack](https://leetcode.com/problems/min-stack/) - Medium
  - 2*n памет
  - n памет
