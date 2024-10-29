#include <iostream>
#include <vector>
#include <algorithm>

struct Tournament {
    size_t min, max;
    size_t counter = 0;
};

int main() {
    int studentsCount, tournametsCount;
    std::cin >> studentsCount >> tournametsCount;

    std::vector<Tournament> tournaments;
    std::vector<size_t> studentsWeights;

    for (int i = 0; i < studentsCount; i++) {
        size_t weight;
        std::cin >> weight;
        studentsWeights.push_back(weight);
    }

    for (int i = 0; i < tournametsCount; i++) {
        Tournament t;
        std::cin >> t.min >> t.max;
        tournaments.push_back(t);
    }

    std::sort(studentsWeights.begin(), studentsWeights.end());

    for (int i = 0; i < tournametsCount; i++) {
        std::vector<size_t>::iterator lower, upper;
        lower = std::lower_bound(studentsWeights.begin(), studentsWeights.end(), tournaments[i].min);
        upper = std::upper_bound(studentsWeights.begin(), studentsWeights.end(), tournaments[i].max);

        if (tournaments[i].min <= tournaments[i].max) {
            tournaments[i].counter = upper - lower;
        }
    }

    for (int i = 0; i < tournametsCount; i++)
        std::cout << tournaments[i].counter << "\n";
}
