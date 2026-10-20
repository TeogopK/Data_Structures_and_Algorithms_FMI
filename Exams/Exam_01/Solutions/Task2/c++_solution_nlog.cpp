// O(M * logM + N * logN) time complexity
// O(M + N) space complexity

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

	std::vector<int> payments(n);
	for (int i = 0; i < n; i++) {
		std::cin >> payments[i];
	}

	std::sort(bills.begin(), bills.end());
	std::sort(payments.begin(), payments.end());

	// Two pointers - every payment has a matching bill, so when both arrays are sorted
	// the current payment is either equal to the current bill (paid) or bigger (bill stays unpaid)
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (j < n && bills[i] == payments[j]) {
			j++;
		}
		else {
			std::cout << bills[i] << " ";
		}
	}
}
