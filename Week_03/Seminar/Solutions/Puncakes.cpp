#include <iostream>

using namespace std;

int cookerTime[10000000]{};

size_t calculatePossiblePancakes(size_t cookersCount, size_t time) {
    size_t currentSolutionPancakes = 0;
    for(size_t i = 0; i < cookersCount; i++) {
        currentSolutionPancakes += (time / cookerTime[i]);
    }
    return currentSolutionPancakes;
}

int main() {
    size_t neededPancakes, cookersCount;
    cin >> neededPancakes >> cookersCount;
    
    for(size_t i = 0; i < cookersCount; i++) {
        cin >> cookerTime[i];
    }
    
    size_t left = 0;
    size_t right = cookerTime[0] * neededPancakes;
    size_t solution = right;
    
    while(left <= right) {
        size_t midTime = left + (right - left) / 2;
        size_t currentSolutionPancakes = calculatePossiblePancakes(cookersCount, midTime);
        
        if(currentSolutionPancakes >= neededPancakes) {
            solution = midTime;
            right = midTime - 1;
        }
        else {
            left = midTime + 1;
        }
    }
    
    cout << solution;
}