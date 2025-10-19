#include <iostream>

void readRooms(int* rooms, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> rooms[i];
	}
}

size_t clean(int n, int* rooms, size_t size, bool* isCleaned) {
	size_t count = 0;

	while (!isCleaned[n]) {
		count++;
		isCleaned[n] = true;
		n = rooms[n];
	}

	return count;
}

void cleanBuilding(size_t n) {
	int* rooms = new int[n]; 
	readRooms(rooms, n);

	bool* isCleaned = new bool[n] {false};
	size_t longestSequence = 0;
	size_t neededCleaners = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (!isCleaned[i]) {
			longestSequence = std::max(longestSequence, clean(i, rooms, n, isCleaned));
			neededCleaners++;
		}
	}

	std::cout << longestSequence << ' ' << neededCleaners;
	delete[] rooms;
	delete[] isCleaned;
}

int main() {
	size_t n;
	std::cin >> n;
}
