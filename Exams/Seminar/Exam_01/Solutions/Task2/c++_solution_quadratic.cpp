// O(N * M + M * logM) time complexity
// O(logM) additional space complexity for std::sort (introsort, in-place)
// O(M) if we count the input vector

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n;
	std::cin >> m >> n;

	std::vector<int> bills(m);
	for (int i = 0; i < m; i++) {
		std::cin >> bills[i];
	}

	for (int i = 0; i < n; i++) {
		int payment;
		std::cin >> payment;

		// Linear search for an unpaid bill with the same amount - O(M)
		// A matching bill is guaranteed to exist, so it != bills.end()
		auto it = std::find(bills.begin(), bills.end(), payment);

		// erase shifts the elements after it one position to the left - O(M)
		bills.erase(it);
	}

	std::sort(bills.begin(), bills.end());

	for (auto bill : bills) {
		std::cout << bill << " ";
	}
}
