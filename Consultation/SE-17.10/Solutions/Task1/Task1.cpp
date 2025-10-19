#include <iostream>

void getRooms(unsigned rooms[], unsigned size)
{
	unsigned idx = 0;

	for (size_t i = 0; i < size; i++)
	{
		std::cin >> rooms[i];
	}
}

unsigned clean(const unsigned* rooms, bool* visited, unsigned idx)
{
	unsigned cycleLength = 0;
	while (!visited[idx])
	{
		visited[idx] = true;
		idx = rooms[idx];
		cycleLength++;
	}

	return cycleLength;
}

void cleanBuilding(unsigned n)
{
	unsigned* rooms = new unsigned[n];

	getRooms(rooms, n);

	unsigned cleanersNeeded = 0;
	unsigned longestCycle = 0;
	bool* visited = new bool[n] { false };

	for (size_t i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			longestCycle = std::max(longestCycle, clean(rooms, visited, i));
			cleanersNeeded++;
		}
	}

	std::cout << "Cleaners needed: " << cleanersNeeded << std::endl << "Time needed: " << longestCycle << " hours" << std::endl;
	delete[] rooms;
	delete[] visited;
}

int main()
{
	unsigned n = 0;
	std::cin >> n;

	cleanBuilding(n);
}