#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	std::vector<int> counter(1001, 0);
	for (size_t i = 0; i < nums.size(); i++) {
		counter[nums[i]]++;
	}

	for (int i = counter.size() - 1; i >= 1; i--) {
		counter[i - 1] += counter[i];
	}

	std::vector<int> result(nums.size(), 0);
	for (size_t i = 0; i < nums.size(); i++) {
		result[i] = nums[i] == 1000 ? 0 : counter[nums[i] + 1];
	}

	for (auto num : result) {
		std::cout << num << " ";
	}
}
