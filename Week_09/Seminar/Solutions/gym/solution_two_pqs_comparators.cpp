// Copied the solution from the exam
#include <vector>
#include <iostream>
#include <queue>
#include <utility>

struct ComparatorFirst
{
    bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right)
    {
        return left.first > right.first;
    }
};

struct ComparatorSecond
{
    bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right)
    {
        return left.second > right.second;
    }
};

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparatorFirst> byStart;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparatorSecond> byEnd;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    
    int start, end;
    for(int i = 0; i < N; i++)
    {
        std::cin >> start >> end;
        if(start != end)
        {
            byStart.push(std::make_pair(start, end));
        }
    }
    
    int max = 0;
    int wanted_max;
    
    std::pair<int, int> curr;
    while(!byStart.empty())
    {
        curr = byStart.top();
        byEnd.push(curr);
        byStart.pop();
        
        while(!byEnd.empty() && curr.first >= byEnd.top().second)
        {
            byEnd.pop();
        }

        while(!byStart.empty() && curr.first == byStart.top().first)
        {
            byEnd.push(byStart.top());
            byStart.pop();
        }
        wanted_max = byEnd.size();
        
        if(wanted_max > max)
        {
            max = wanted_max;
        }
        
    }
    std::cout << max;
    
    return 0;
}
