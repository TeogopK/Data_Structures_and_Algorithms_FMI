/*
    Задачата е да имплементираме клас, който поддържа два метода:
        1. добавяне на число: void addNum(int num); (ред 38)
        2. намиране на медианата на всички добавени до момента числа: double findMedian(). (ред 55)
    
    Ясно е, че може да пазим числата в сортиран вектор и при всяко добавяне на ново число да го вмъкваме на правилното място.
    Тогава лесно ще намираме медианата за константно време, но добавянето ще се случва за линейно време. Можем да се справим по-добре!

    Нека да си представим, че имаме 2k + 1 на брой числа и те са сортирани: x_1 < x_2 < ... < x_k < x_(k+1) < x_(k + 2) ... < x_(2k + 1). 
    Toгава медината е x_(k + 1). Нека сега да добавим числото y. Интересува ни къде ще се намира y спрямо x_(k + 1), като имаме 2 случая:
        1) ако y < x_(k + 1), ще го вмъкнем отляво.
        2) ако y >= x_(k + 1), ще го вмъкнем отдясно.
    За да намерим медианата след това (имаме вече четен брой числа), ще трябва да знаем единствено най-лявото преди и най-дясното число след x_(k + 1).
    Друго, което забелязваме е, че преди да добавим у, x_(k + 1) е най-големият елемент от тези вляво и най-малкият от тези вдясно. 
    Оттук се досещаме, че вместо да пазим всички числа в един вектор, може да пазим двете половини в две приоритетни опашки, 
    едната от които е максимален хийп, а другата - минимален хийп. (редове 30-31)

    Сега въпросът за намиране на медианата е лесен. Ако двата хийпа имат равен брой елементи, връщаме средното от двата елемента във върховете им (ред ).
    В противен случай медианата е върхът на хийпа с повече елементи (редове 55-61)

    Сега остава да поддържаме двата хийпа наистина да са двете половини на всички добавени числа.
    Вече видяхме, че когато добавяме число num, го сравняваме с върха на лeвия хийп (ако има елементи) и ако num < върха, 
    то го добавяме в лявата половина, а иначе - в дясната (редове 39-43). А за да е изпълнено условието двата хийпа да са двете половини, трябва разликата от броя елементи в тях
    да е най-много 1, т.е. |leftHalf.size() - rightHalf.size()| <= 1. Това ще е нарушено, когато |leftHalf.size() - righHalf.size()| > 1, 
    т.е. leftHalf.size() - rightHalf.size() < -1 или leftHalf.size() - rightHalf.size() > 1.
    В такъв случай ще трябва да махнем върха от хийпа с повече елементи и да го добавим към хийпа с по-малко (редове 45-51). 
    Така вече добавянето на елемент става за логаритмично време и намирането на медианата за константно.
*/
class MedianFinder {
    std::priority_queue<int> firstHalf; // max heap
    std::priority_queue<int, std::vector<int>, std::greater<>> secondHalf; // min heap

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (firstHalf.size() && num < firstHalf.top()) {
            firstHalf.push(num);
        } else {
            secondHalf.push(num);
        }
        
        if (firstHalf.size() + 1 < secondHalf.size()) { 
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        } else if (firstHalf.size() > secondHalf.size() + 1) {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }

    }
    
    double findMedian() {
        if (firstHalf.size() == secondHalf.size()) {
            return (firstHalf.top() + secondHalf.top()) / 2.0;
        }

        return firstHalf.size() > secondHalf.size() ? firstHalf.top() : secondHalf.top();
    }
};

// alternative
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>>begin;
    priority_queue<int, vector<int>, greater<int>>end;

    MedianFinder() {}
    
    void addNum(int num) {
        if (begin.empty() && end.empty()) {
            begin.push(num);
            return;
        }

        double med = findMedian();

        if (num < med) {
            begin.push(num);
        } 
        else {
            end.push(num);
        }

        if (begin.size() < end.size()) {
            begin.push(end.top());
            end.pop();
        }
        if (begin.size() - end.size() > 1) {
            end.push(begin.top());
            begin.pop();
        }
    }
    
    double findMedian() {
        if ((begin.size() + end.size()) % 2 == 0 ) {
            return (double)(begin.top() + end.top()) / 2.0;
        }
        return begin.top();
    }
};
