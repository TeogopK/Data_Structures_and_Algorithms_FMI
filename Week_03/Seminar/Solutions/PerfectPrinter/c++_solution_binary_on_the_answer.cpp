// Literally the same solution as puncakes
// just renamed the variables
#include <iostream>

using namespace std;

int printerTime[10000000]{};

size_t calculatePossibleCopies(size_t printersCount, size_t time) {
    size_t currentSolutionCopies = 0;
    for (size_t i = 0; i < printersCount; i++) {
        currentSolutionCopies += (time / printerTime[i]);
    }
    return currentSolutionCopies;
}

int main() {
    size_t neededCopies, printersCount;
    cin >> neededCopies >> printersCount;

    for (size_t i = 0; i < printersCount; i++) {
        cin >> printerTime[i];
    }

    size_t left = 0;
    size_t right = printerTime[0] * neededCopies;
    size_t solution = right;

    while (left <= right) {
        size_t midTime = left + (right - left) / 2;
        size_t currentSolutionCopies = calculatePossibleCopies(printersCount, midTime);

        if (currentSolutionCopies >= neededCopies) {
            solution = midTime;
            right = midTime - 1;
        }
        else {
            left = midTime + 1;
        }
    }

    cout << solution;
}