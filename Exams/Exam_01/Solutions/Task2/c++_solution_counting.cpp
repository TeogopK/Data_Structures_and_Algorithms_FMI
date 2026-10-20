// O(M + N + K) time complexity
// O(K) space complexity, where K = 1000 is the max amount

#include <iostream>
#include <vector>

const int MAX_AMOUNT = 1000;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n;
	std::cin >> m >> n;

	// counter[x] - how many unpaid bills with amount x there are
	std::vector<int> counter(MAX_AMOUNT + 1, 0);
	for (int i = 0; i < m; i++) {
		int bill;
		std::cin >> bill;
		counter[bill]++;
	}

	for (int i = 0; i < n; i++) {
		int payment;
		std::cin >> payment;
		counter[payment]--;
	}

	// Iterating the amounts in ascending order gives sorted output
	for (int amount = 1; amount <= MAX_AMOUNT; amount++) {
		for (int i = 0; i < counter[amount]; i++) {
			std::cout << amount << " ";
		}
	}
}
