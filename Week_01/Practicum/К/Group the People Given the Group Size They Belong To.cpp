// За решението може да използваме един помощен масив от вектори groups, в който
// на позиция i се намира група от i на брой души. 
// Обхождаме вектора groupSizes, като всеки един човек поставяме в група от groupSizes[i] на брой души. 
// Когато размерът на групата стане groupSizes[i], тогава я добавяме в отговора (вектора grouped)
// и изтриваме (group.clear()) хората от нея, защото вече са разпределени (така изполваме вектора groups[i] за всички групи от i на брой души)
class Solution {
    vector<int> groups[501] {};
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> grouped;
        for (int i = 0; i < groupSizes.size(); ++i) {
            auto& group = groups[groupSizes[i]];
            group.push_back(i);

            if (group.size() == groupSizes[i]) {
                grouped.push_back(group);
                group.clear();
            }

        }
        return grouped;
    }
};