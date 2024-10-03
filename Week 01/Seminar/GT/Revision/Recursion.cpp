#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <vector>
#include <utility>

static std::chrono::duration<double> measureTime(const std::function<void()>& testedFunction) {
    auto start = std::chrono::steady_clock::now();
    testedFunction();
    auto end = std::chrono::steady_clock::now();
    return (end - start);
}

static void printMeasuredTime(const std::function<void()>& testedFunction) {
    auto elapsedTime = measureTime(testedFunction);
    std::cout << "Time taken: " << elapsedTime.count() << " seconds" << std::endl;
}

int iterativeFibonacci(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int recursiveFibonacci(int n) {
    if (n <= 1)
		return n;
	return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main() {
    int n = 40;

    std::cout << "Iterative Fibonacci: " << std::endl;
    printMeasuredTime([n](){
		std::cout << "Fibonacci(" << n << ") = " << iterativeFibonacci(n) << std::endl;
	});

    std::cout << "Recursive Fibonacci: " << std::endl;
	printMeasuredTime([n](){
		std::cout << "Fibonacci(" << n << ") = " << recursiveFibonacci(n) << std::endl;
	});
}