#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> tickets(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
    }

    // Step 1: Ignore negative numbers and count only positive ones
    vector<int> count(n + 1, 0); // We only need to count up to n

    for (int i = 0; i < n; i++)
    {
        if (tickets[i] > 0 && tickets[i] <= n)
        {
            count[tickets[i]] = 1; // Mark that this number is present
        }
    }

    // Step 2: Find the smallest missing positive number
    for (int i = 1; i <= n; i++)
    {
        if (count[i] == 0)
        {
            cout << i;
            return 0;
        }
    }

    // If all numbers from 1 to n are present, the missing number is n+1
    cout << n + 1;

    return 0;
}
