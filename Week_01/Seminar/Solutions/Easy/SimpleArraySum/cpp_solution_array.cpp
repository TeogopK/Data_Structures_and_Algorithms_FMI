#include <iostream>

// Since we know the max number of elements is 1000
// we can preemptively allocate the memory.
const int MAXSIZE = 1000;

int main()
{
    int n;
    int arr[MAXSIZE];

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    // Using "int" is also possible since
    // the max sum is 1000 elements each one being 1000 => 1_000_000
    // which can be stored inside an int.

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    std::cout << sum;
}