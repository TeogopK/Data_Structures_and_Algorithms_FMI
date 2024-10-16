#include <iostream>
using namespace std;

// 6.0. Merge function - merges 2 sorted arrays
template<typename T>
void Merge(int* arr1, int len1, int* arr2, int len2)
{
	T* resultArray = new T[len1 + len2];

	int cursor1 = 0;
	int cursor2 = 0;
	int resultCursor = 0;

	while (cursor1 < len1 && cursor2 < len2)
	{
		if (arr1[cursor1] <= arr2[cursor2])
			resultArray[resultCursor++] = arr1[cursor1++];
		else
			resultArray[resultCursor++] = arr2[cursor2++];
	}

	while (cursor1 < len1)
		resultArray[resultCursor++] = arr1[cursor1++];
	while (cursor2 < len2)
		resultArray[resultCursor++] = arr2[cursor2++];

	for (int i = 0; i < len1 + len2; i++)
		arr1[i] = resultArray[i];
	delete[] resultArray;
}

template <typename T>
void MergeSort(T* arr, int len)
{
	if (len == 1)
		return;

	int mid = len / 2;

	MergeSort(arr, mid);
	MergeSort(arr + mid, len - mid);

	Merge<T>(arr, mid, arr + mid, len - mid);
}

int main()
{
	int arr[4] = { 9, 6, 5, 8 };
	MergeSort(arr, 4);

	for (int i = 0; i < 4; i++)
		cout << arr[i] << " ";
}