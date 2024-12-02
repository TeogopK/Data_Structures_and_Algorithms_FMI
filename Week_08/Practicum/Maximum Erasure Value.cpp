/*
    Даден ни е вектор от цели числа nums и тъсим максималната сума на числата на някой подмасив с уникални числа.
    Върпосът е как да итерираме по тези подмасиви. Всеки такъв подмасив ще има начало и край (уау), като, за да добавим число към подмасива,
    то не трябва да се среща преди това. Оттук се сещаме да си пазим началото на подмасива в променливата start (ред 15), a елементите му в unorderder_set<int> subarray (ред 14).
    Ще обхождаме вектора с for-цикъл (ред 18), като i ще ни бъде края на подмасива с уникални елементи и начало start. Преди да добавим nums[i] към subarray,
    ще се погрижим nums[i] да не се среща в него, т.е. ще премахваме числото в началото nums[start] от него и ще местим start напред, 
    докато nums[i] е в subarray (ред 19-22). (Идеята е подобна на монотнните стек и опашка).
    След като вече имаме подмасива nums[start..i] с уникални числа в него (ред 24), търсенето на сумата от елемените му е ясно. 
    Ще си пазим subarraySum (ред 17), като при добавяне и премахване на елемент към subarray (ред 24, 20), ще я актуализираме (ред 25, 21) и накрая с maxSum ще пазим максималната (ред 26).
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        std::unordered_set<int> subarray;
        int start = 0;
        int maxSum = 0;
        int subarraySum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (subarray.count(nums[i])) {
                subarray.erase(nums[start]);
                subarraySum -= nums[start];
                start++;
            }
            subarray.insert(nums[i]);
            subarraySum += nums[i];
            maxSum = max(maxSum, subarraySum);
        }

        return maxSum;
    }
};
