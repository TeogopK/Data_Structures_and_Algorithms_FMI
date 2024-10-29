#include<iostream>
#include<vector>

int main() {
    int developersCount, teamsCount;
    std::cin >> developersCount >> teamsCount;

    std::vector<int> developers;

    long long sum = 0;
    long long highest = 0;

    for (size_t i = 0; i < developersCount; i++)
    {
        int developer;
        std::cin >> developer;
        sum += developer;
        if (developer > highest)
            highest = developer;

        developers.push_back(developer);
    }

    long long bestCase = highest;
    long long low = bestCase, high = sum;
    long long lastSucceededBestCase = 0;

    while (low <= high)
    {
        bestCase = low + (high - low) / 2;
        int currentTeamsCount = 0;
        long long currentTeamSum = 0;
        for (size_t i = 0; i < developersCount; i++)
        {
            if (developers[i] + currentTeamSum > bestCase) {
                currentTeamsCount++;
                currentTeamSum = 0;
            }
            currentTeamSum += developers[i];
        }

        if (currentTeamSum != 0)
            currentTeamsCount++;

        if (currentTeamsCount > teamsCount)
            low = bestCase + 1;
        else
            high = bestCase - 1;

        if (currentTeamsCount == teamsCount)
            lastSucceededBestCase = bestCase;

    }

    std::cout << lastSucceededBestCase;
}
