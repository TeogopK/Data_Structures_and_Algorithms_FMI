#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Interval{
  size_t start, end;  
};

bool compIntervals(const Interval& lhs, const Interval& rhs){
    return lhs.start < rhs.start;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<Interval> container;
    for(size_t i = 0; i < n; i++){
        Interval j;
        std::cin >> j.start >> j.end;
        if(j.start < j.end)
            container.push_back(j);
    }
    
    priority_queue<size_t, vector<size_t>, greater<size_t>> ends;
    
    std::sort(container.begin(), container.end(), compIntervals);
    size_t max = 0;
    for(long long i = 0; i < container.size(); i++){
        while(!ends.empty() && ends.top() <= container[i].start) {
            ends.pop();
        }
        
        ends.push(container[i].end);
        
        if(max < ends.size()){
            max = ends.size();
        }
    }
    
    std::cout << max;
}
