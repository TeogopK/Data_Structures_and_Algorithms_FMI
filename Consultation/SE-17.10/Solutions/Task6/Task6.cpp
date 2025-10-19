#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<pair<int, int>>& first, vector<pair<int, int>>& second, vector<pair<int, int>>& result)
{
	size_t firstIndex = 0;
	size_t secondIndex = 0;
	size_t resultIndex = 0;

	while (firstIndex < first.size() && secondIndex < second.size())
	{
		if (first[firstIndex] <= second[secondIndex])
		{
			result[resultIndex++] = first[firstIndex++];
		}
		else
		{
			result[resultIndex++] = second[secondIndex++];
		}
	}

	while (firstIndex < first.size())
	{
		result[resultIndex++] = first[firstIndex++];
	}

	while (secondIndex < second.size())
	{
		result[resultIndex++] = second[secondIndex++];
	}
}

void evensAndOdds(vector<pair<int, int>>& arr)
{
	vector<pair<int, int>> even;
	vector<pair<int, int>> odd;

	for (int i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0)
			even.push_back(arr[i]);
		else
			odd.push_back(arr[i]);
	}

	// Linear in time - reverses array
	// Can be skipped if we modify merge to look at the second array from right to left
	std::reverse(odd.begin(), odd.end());

	merge(even, odd, arr);
}

int main()
{
	std::vector<int> arr = { 2, 3, 7, 1, 11, -15, 14, -25, 17, -33 };
	std::vector<pair<int, int>> arr2;
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr2.push_back({ arr[i], i });
	}

	evensAndOdds(arr2);

	for (size_t i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i].first << ' ' << arr2[i].second << endl;
	}
}