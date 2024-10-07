#include <iostream>
#include <chrono>

void whatIsTheComplexity(int n) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			if (j == i + 3) {
				break;
				i += 2;
			}
		}
	}
}

int main() {
}