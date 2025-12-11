#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

// can not use std::greater<>, because no c++ > 14
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> all;
std::priority_queue<int, std::vector<int>, std::greater<int>> waiting;

int main() {
    int N;
    std::cin >> N;
    
    int start, end;
    for(int i = 0; i < N; i++) {
        std::cin >> start >> end;
        all.push(std::make_pair(start, end));
    }
    
    int time = 0;
    size_t maxCount = 0;
    
    while(!all.empty()) {       
        while(!all.empty() && all.top().first <= time) { // add already started
            auto interval = all.top(); // pair(start, end)
            all.pop();
            waiting.push(interval.second); // add only end
        }
        
        while(!waiting.empty() && waiting.top() <= time) {
            waiting.pop(); // pop all ended
        }
        
        maxCount = std::max(maxCount, waiting.size());        
        time = all.top().first; // jump to next start
    }
    
    std::cout << maxCount;
    
    return 0;
}
