#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

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

static void populateArray(short* arr, size_t length) {
    for (size_t i = 0; i < length; i++) {
        arr[i] = i;
    }
}

const int MAX_COLS = 500;
static void populateMatrix(short arr[][MAX_COLS], size_t rows, size_t cols) {
    int i = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            arr[i][j] = i * j;
        }
    }
}

static void iterateArr(const short* arr, size_t length) {
    int x = 0;
    for (size_t i = 0; i < length; i++) {
        x <<= arr[i];
    }
}

static void iterateMatrix(short arr[][MAX_COLS], size_t rows, size_t cols) {
    int x = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            x <<= arr[i][j];
        }
    }
}

static void iterateMatrixByCols(short arr[][MAX_COLS], size_t rows, size_t cols) {
    int x = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            x <<= arr[j][i];
        }
    }
}

static void iterateDynamicMatrixByRows(int** matrix, size_t rows, size_t cols) {
    int x = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            x <<= matrix[i][j];
        }
    }
}
static void iterateDynamicMatrixByCols(int** matrix, size_t rows, size_t cols) {
    int x = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            x <<= matrix[j][i];
        }
    }
}

static int** createDynamicMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
	}

    return matrix;
}

int main() {
    short arr[MAX_COLS * MAX_COLS];
    populateArray(arr, MAX_COLS * MAX_COLS);
    short matrix[MAX_COLS][MAX_COLS];
    populateMatrix(matrix, MAX_COLS, MAX_COLS);

    std::cout << "iterate array: " << std::endl;
    printMeasuredTime([&arr]() {
        iterateArr(arr, MAX_COLS * MAX_COLS);
    });
    std::cout << std::endl;
    std::cout << "iterate matrix by rows: " << std::endl;
    printMeasuredTime([&matrix]() {
        iterateMatrix(matrix, MAX_COLS, MAX_COLS);
    });
    std::cout << std::endl;
    std::cout << "iterate matrix by cols: " << std::endl;
    printMeasuredTime([&matrix]() {
        iterateMatrixByCols(matrix, MAX_COLS, MAX_COLS);
    });


    const int DYNAMIC_MAX_COLS = 10000;
    int** dynamicMatrix = createDynamicMatrix(DYNAMIC_MAX_COLS, DYNAMIC_MAX_COLS);

    std::cout << std::endl;
    std::cout << "iterate dynamic matrix by rows: " << std::endl;
    printMeasuredTime([&dynamicMatrix]() {
        iterateDynamicMatrixByRows(dynamicMatrix, DYNAMIC_MAX_COLS, DYNAMIC_MAX_COLS);
    });
    std::cout << std::endl;
    std::cout << "iterate dynamic matrix by cols: " << std::endl;
    printMeasuredTime([&dynamicMatrix]() {
        iterateDynamicMatrixByCols(dynamicMatrix, DYNAMIC_MAX_COLS, DYNAMIC_MAX_COLS);
    });
}