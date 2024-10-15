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

static void acceptByCopy(std::vector<int> vec) {
    int a = 1;
}

static void acceptByRef(std::vector<int>& vec) {
    int a = 2;
}

static void acceptByRvalueRef(std::vector<int>&& vec) {
    int a = 3;
}

void normalSwap(std::vector<int>& a, std::vector<int>& b) {
	auto temp = a;
	a = b;
	b = temp;
}

void moveSwap(std::vector<int>& a, std::vector<int>& b) {
	auto temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main() {
    auto vector = std::vector<int>(1000000, 0);
    std::cout << "Accept by copy" << std::endl;
    printMeasuredTime([&vector]() {
        acceptByCopy(vector);
    });
    std::cout << std::endl;
    std::cout << "Accept by ref" << std::endl;
    printMeasuredTime([&vector]() {
        acceptByRef(vector);
    });
    std::cout << std::endl;
    std::cout << "Accept by rvalue ref" << std::endl;
    printMeasuredTime([&vector]() {
        acceptByRvalueRef(std::move(vector));
    });

    auto a = std::vector<int>(1000000, 0);
    auto b = std::vector<int>(1000000, 0);
    std::cout << std::endl;
    std::cout << "Normal swap" << std::endl;
    printMeasuredTime([&a, &b]() {
		normalSwap(a, b);
	});
    std::cout << std::endl;
    std::cout << "Move swap" << std::endl;
	printMeasuredTime([&a, &b]() {
		moveSwap(a, b);
	});
}