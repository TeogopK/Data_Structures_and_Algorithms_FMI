#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <unordered_map>
using namespace std;

// add number - O(logN)
// find max - O(logN)

void streamSolution() {
	// key -> frequency
	// value -> ordered set of numbers with that frequency in ascending order
	map<int, set<int>> frequencyToNumber;
	// key -> number
	// value -> frequency
	unordered_map<int, int> numberToFrequency;

	int number;
	while (cin >> number) {
		if (number == 0) {
			if (frequencyToNumber.empty()) {
				cout << "empty" << endl;
				continue;
			}

			// get the highest frequency from the map thats the iterator to the last element
			auto iterToLastElement = frequencyToNumber.rbegin();
			// first is the frequence
			auto frequency = iterToLastElement->first;
			// second is the set of numbers with that frequency
			// first element of that set is the smallest number with that frequency
			auto minNumberWithMaxFrequency = *(iterToLastElement->second.begin());
			cout << minNumberWithMaxFrequency << endl;

			// remove the number from the that frequency set
			iterToLastElement->second.erase(minNumberWithMaxFrequency);
			// if the set is now empty remove the frequency from the map
			if (iterToLastElement->second.empty()) {
				frequencyToNumber.erase(frequency);
			}
			// set the frequency of the number to 0
			numberToFrequency[minNumberWithMaxFrequency] = 0;
		}
		else {
			// by default on microsoft compiler returns 0 if the key is not found
			int oldFrequency = numberToFrequency[number];
			numberToFrequency[number]++;
			frequencyToNumber[oldFrequency].erase(number);
			frequencyToNumber[oldFrequency + 1].insert(number);
		}
	}
}

void arraySolution(const std::vector<int>& arr) {

	// key -> frequency
	// value -> ordered set of numbers with that frequency in ascending order
	map<int, set<int>> frequencyToNumber;
	// key -> number
	// value -> frequency
	unordered_map<int, int> numberToFrequency;

	for(auto number : arr) {
		if (number == 0) {
			if (frequencyToNumber.empty()) {
				cout << "empty" << endl;
				continue;
			}

			// get the highest frequency from the map thats the iterator to the last element
			auto iterToLastElement = frequencyToNumber.rbegin();
			// first is the frequence
			auto frequency = iterToLastElement->first;
			// second is the set of numbers with that frequency
			// first element of that set is the smallest number with that frequency
			auto minNumberWithMaxFrequency = *(iterToLastElement->second.begin());
			cout << minNumberWithMaxFrequency << endl;

			// remove the number from the that frequency set
			iterToLastElement->second.erase(minNumberWithMaxFrequency);
			// if the set is now empty remove the frequency from the map
			if (iterToLastElement->second.empty()) {
				frequencyToNumber.erase(frequency);
			}
			// set the frequency of the number to 0
			numberToFrequency[minNumberWithMaxFrequency] = 0;
		}
		else {
			// by default on microsoft compiler returns 0 if the key is not found
			int oldFrequency = numberToFrequency[number];
			numberToFrequency[number]++;
			frequencyToNumber[oldFrequency].erase(number);
			frequencyToNumber[oldFrequency + 1].insert(number);
		}
	}
}

int main() {
	// streamSolution();
	arraySolution({ 1, 5, 1, 5, 4, 1, 4, 4, 0, 0, 2, 2, 0 });
}
