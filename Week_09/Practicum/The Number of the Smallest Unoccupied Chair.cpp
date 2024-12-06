// a solution with structs
struct Friend {
    int arrives, leaves, idx;

    bool operator<(const Friend& other) {
        return this->arrives < other.arrives;
    }
};

struct Guest {
    int leaves, chair;
};

// can also be a function like object
auto compareGuests = [](const Guest& lhs, const Guest& rhs){
    return lhs.leaves > rhs.leaves;
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        std::vector<Friend> friends;
        for (int i = 0; i < times.size(); ++i) {
            friends.push_back({times[i][0], times[i][1], i});
        }
        std::sort(friends.begin(), friends.end());
        
        std::priority_queue<int, std::vector<int>, std::greater<>> availableChairs;
        for (int i = 0; i < times.size(); ++i) {
            availableChairs.push(i);
        }
        
        // std::priority_queue<Guest, std::vector<Guest>, bool (*)(const Guest&, const Guest&)> guests(compareGuests);
        std::priority_queue<Guest, std::vector<Guest>, decltype(compareGuests)> guests(compareGuests);
        for (int i = 0; i < friends.size(); ++i) {
            while (guests.size() && guests.top().leaves <= friends[i].arrives) {
                availableChairs.push(guests.top().chair);
                guests.pop();
            }

            if (friends[i].idx == targetFriend) {
                return availableChairs.top();
            }
            
            guests.push({friends[i].leaves, availableChairs.top()});
            availableChairs.pop();
        }

        return 1;
    }
};

// a solutions with pairs
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> allGuests;
        for (int i = 0; i < n; i++) {
            allGuests.push({times[i][0], {times[i][1], i}});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> currGuests;

        priority_queue<int, vector<int>, greater<>> availableSeats;
        for (int i = 0; i < n; i++) {
            availableSeats.push(i);
        }

        while (!allGuests.empty()) {
            auto event = allGuests.top();
            allGuests.pop();

            int arrival = event.first;
            int departure = event.second.first;
            int index = event.second.second;

            while (!currGuests.empty() && currGuests.top().first <= arrival) {
                availableSeats.push(currGuests.top().second);
                currGuests.pop();
            }
            int seat = availableSeats.top();
            availableSeats.pop();

            if (index == targetFriend) {
                return seat;
            }

            currGuests.push({departure, seat});
        }

        return -1;
    }
};

// a solution with tuples and pairs
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        std::vector<std::tuple<int, int, int>> friends;
        for (int i = 0; i < times.size(); ++i) {
            friends.push_back({times[i][0], times[i][1], i});
        }
        std::sort(friends.begin(), friends.end());

        std::priority_queue<int, std::vector<int>, std::greater<>> availableChairs;
        for (int i = 0; i < times.size(); ++i) {
            availableChairs.push(i);
        }
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> guests;
        for (int i = 0; i < friends.size(); ++i) {
            while (guests.size() && guests.top().first <= std::get<0>(friends[i])) {
                availableChairs.push(guests.top().second);
                guests.pop();
            }

            if (std::get<2>(friends[i]) == targetFriend) {
                return availableChairs.top();
            }
            
            guests.push({std::get<1>(friends[i]), availableChairs.top()});
            availableChairs.pop();
        }

        return 1;
    }
};
