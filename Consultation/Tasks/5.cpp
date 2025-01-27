#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    size_t size;
    cin >> size;
    
    // id 1, time 3
    // id 0, time 12
    // id 1, time 22
    unordered_map<size_t, size_t> counter;
    
    // 3 -> 1
    // 12 -> 0
    // 22 -> 1
    unordered_map<size_t, size_t> bestAt;

    // 3 12 22
    vector<size_t> times(size);
    // 15 -> iter -> --/++ 12 -> bestAt[12]
    
    size_t maxId = 0;
    size_t maxCount = 0;
    
    for(size_t i = 0; i < size; i++) {
        size_t id, time;
        cin >> id >> time;
        counter[id]++;
        times[i] = time;
        
        // 1 -> 1
        if(counter[id] >= maxCount) {
            maxId = id;
            maxCount = counter[id];
        }
        bestAt[time] = maxId;
    }
    
    size_t queriesSize;
    cin >> queriesSize;
    
    for(size_t i = 0; i < queriesSize; i++) {
        size_t queryTime;
        cin >> queryTime;
        
        if(queryTime < times[0]) {
            cout << -1 << endl;
            continue;
        }
        
        auto iter = upper_bound(times.begin(), times.end(), queryTime);
        --iter;
        
        // bestAt
        cout << bestAt[*iter] << endl;
    }
}
