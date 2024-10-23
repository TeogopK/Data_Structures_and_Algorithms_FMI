#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comparator_concat(const string &left, const string &right)
{
    return left + right > right + left;
}

int main()
{
    int N;
    cin >> N;

    vector<string> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    // If the array has only zeros, the result is 0
    if (count(arr.begin(), arr.end(), "0") == N)
    {
        cout << 0 << endl;
        return 0;
    }

    // Else sort the vector by which concatenation is bigger
    sort(arr.begin(), arr.end(), comparator_concat);

    for (const string &s : arr)
    {
        cout << s;
    }

    cout << endl;
    return 0;
}
