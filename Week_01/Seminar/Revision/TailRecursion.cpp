#include <iostream>

long long sum = 0;

// Not optimized for tail recursion
void sum1toN(int N)
{
	if (N < 1)
		return;
	sum1toN(N - 1);
	sum += N;
}

// Optimized for tail recursion - when the last operation is the recursive call the compiler optimizes it in release mode into iterative process
void sum1toN_tail(int N)
{
	if (N < 1)
		return;
	sum += N;
	sum1toN_tail(N - 1);
}

int main() {
    // RUN IN RELEASE!
    
	// this will fail with stack overflow for large N
	//sum1toN(100000);
	//cout << "hello1" << endl;
	sum1toN_tail(100000);
	cout << "hello2" << endl;
}
