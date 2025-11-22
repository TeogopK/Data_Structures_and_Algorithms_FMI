// gpt generated
// this task was similar to:
// pancakes, koko eating bananas etc.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция за проверка дали можем да изядем всички плодове за даден брой часове с дадена стойност X
bool canEatAllFruits(const vector<int>& boxes, int H, int X) {
    int hoursNeeded = 0;
    for (int fruits : boxes) {
        hoursNeeded += (fruits + X - 1) / X; // заобляне нагоре, за да намерим броя часове, нужни за кутията
    }
    return hoursNeeded <= H;
}

int findMinX(const vector<int>& boxes, int H) {
    int left = 1;
    int right = *max_element(boxes.begin(), boxes.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canEatAllFruits(boxes, H, mid)) {
            right = mid;  // ако можем да изядем всички плодове, пробваме с по-малка стойност на X
        } else {
            left = mid + 1;  // ако не можем, пробваме с по-голяма стойност на X
        }
    }
    return left;
}

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> boxes(N);
    for (int i = 0; i < N; ++i) {
        cin >> boxes[i];
    }

    int result = findMinX(boxes, H);
    cout << result << endl;

    return 0;
}
