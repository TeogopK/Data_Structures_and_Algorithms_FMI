#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Task {
    int start_time;  
    int duration;    
    int index;      
};

struct CompareArrival {
    bool operator()(const Task& a, const Task& b) {
        return a.start_time > b.start_time; 
    }
};

struct CompareReady {
    bool operator()(const Task& a, const Task& b) {
        if (a.duration == b.duration) {
            return a.index > b.index; 
        }
        return a.duration > b.duration;
    }
};

int main() {
    int n;
    cin >> n;

    priority_queue<Task, vector<Task>, CompareArrival> arrival; 
    priority_queue<Task, vector<Task>, CompareReady> ready;     

    for (int i = 0; i < n; ++i) {
        int t, f;
        cin >> t >> f;
        arrival.push({t, f, i});
    }

    int currentTime = 0;

    while (!arrival.empty() || !ready.empty()) {
        while (!arrival.empty() && arrival.top().start_time <= currentTime) {
            ready.push(arrival.top());
            arrival.pop();
        }

        if (!ready.empty()) {
            Task currentTask = ready.top();
            ready.pop();
            currentTime = max(currentTime, currentTask.start_time) + currentTask.duration;
            cout << currentTask.index << " ";
        } else if (!arrival.empty()) {
            currentTime = arrival.top().start_time;
        }
    }

    cout << endl;

    return 0;
}
