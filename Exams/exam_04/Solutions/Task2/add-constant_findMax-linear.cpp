#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <unordered_map>
using namespace std;

// add number -> O(1)
// find max -> O(n)
void arraySolution(const std::vector<int>& arr) {
	unordered_map<int, int> numberToFrequency;
	for(auto number : arr) {
		if (number == 0) {
			if (numberToFrequency.empty()) {
				cout << "empty" << endl;
				continue;
			}

			// get max frequency min number
			int minNumber = numeric_limits<int>::max();
			int maxFrequency = 0;
			for(auto& kvp: numberToFrequency) {
				if (kvp.second > maxFrequency) {
					maxFrequency = kvp.second;
					minNumber = kvp.first;
				}
				else if (kvp.second == maxFrequency) {
					minNumber = min(minNumber, kvp.first);
				}
			}
			cout << minNumber << endl;
			numberToFrequency[minNumber] = 0;
		}
		else {
			numberToFrequency[number]++;
		}
	}
}

int main() {
	// streamSolution();
	arraySolution({ 1, 5, 1, 5, 4, 1, 4, 4, 0, 0, 2, 2, 0 });
}
