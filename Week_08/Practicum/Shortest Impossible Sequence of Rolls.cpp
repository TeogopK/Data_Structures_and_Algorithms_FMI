/*
    Даден ни е вектор от числа rolls и число k, като всяко число в rolls e <= k.
    Търсим дължината на първата редица от числа от {1, 2, ..., k}, която не е подредица на rolls.

    За да се сетим за решението, е добре да се замислим кои са всичките редици от числа {1, 2, ..., k} с дължина l:
        * ако l = 1, те са (1), (2), ..., (k);
        * ako l = 2, те са (1, 1), (1, 2), (1, 3), ... (2, 1), ... (k, k);
        * и така нататък.
    Тоест редиците с дължина l са наредени l-орки от {1, ..., k}x{1, ..., k}x...x{1, ..., k} = {1, ..., k}^l.
    Това ни навежда на мисълта, че трябва да видим колко е броят на всичките подмножества {1, 2, ..., k}, 
    които са част от последовални подмасиви на rolls (т.е. гледаме за индкеси i и j, между които които имаме всички елементи на {1, 2, ..., k}).
    Ще използваме int count (ред 22) за този брой и unordered_set<int> set (ред 21) за множестово {1, ..., k} и с един for-цикъл ще обхождаме rolls (ред 23), 
    като добавяме всеки елемент rolls[i] в set (ред 24).
    Когато set има размер k (ред 25), значи, че сме намерили подмасив, които съдържа всички числа 1, 2, ..., k поне по веднъж.
    В такъв случай изтриваме всички елементи и инкрементираме count (ред 26-27). След края на цикъла count ще бъде броя на всичките множества {1, ..., k}, 
    които се срещат в последователни подмасиви и значи отговорът на задачата ще е count + 1 (ред 31).
*/
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        std::unordered_set<int> set;
        int count = 0;
        for (int i = 0; i < rolls.size(); ++i) {
            set.insert(rolls[i]);
            if (set.size() == k) {
                set.clear();
                count++;
            }
        }

        return count + 1;
    }
};
