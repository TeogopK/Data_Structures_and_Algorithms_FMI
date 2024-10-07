#include <iostream>
#include <chrono>
#include <thread>

std::chrono::duration<double> measureTime(void(*testedFunction)()) {
    auto start = std::chrono::steady_clock::now();
    testedFunction();
    auto end = std::chrono::steady_clock::now();
    return (end - start);
}

void printMeasuredTime(void(*testedFunction)()) {
    auto elapsedTime = measureTime(testedFunction);
    std::cout << "Time taken: " << elapsedTime.count() << " seconds" << std::endl;
}

int main() {
    printMeasuredTime([]() {
        // sleep for 1 second
        // printed time will be > 1 second!
        // this is not 100% reliable because there are other
        // processes on your computer
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    });
}