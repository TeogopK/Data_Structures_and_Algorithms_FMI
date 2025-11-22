#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	std::vector<int> result(nums.size(), 0);
	for (size_t i = 0; i < nums.size(); i++) {
		size_t counter = 0;
		for (size_t j = 0; j < nums.size(); j++) {
			if (nums[j] > nums[i]) {
				counter++;
			}
		}

		result[i] = counter;
	}


	for (auto num : result) {
		std::cout << num << " ";
	}
}
