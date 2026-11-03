// Контролно 2 СДА 2026/27, Вариант 2, Задача 1 - най-голямата страна k на леха, за която k * k <= N

// O(logN) time complexity
// O(1) space complexity

#include <iostream>

int main() {
	long long n;
	std::cin >> n;

	// k * k is increasing, so we binary search for the last k in [0, N] with k * k <= N
	long long left = 0, right = n, answer = 0;
	while (left <= right) {
		long long mid = left + (right - left) / 2;

		if (mid * mid <= n) {
			// mid fits - remember it and look for a bigger side
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	std::cout << answer << std::endl;
}
