#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k;
    std::cin >> k;

    int num;
    // holds the k-min elements
    std::priority_queue<int> maxHeap;

    while (std::cin >> num && num != -1) {
        if (num == 0) {
            std::cout << ((maxHeap.size() < k) ?  -1 : maxHeap.top()) << std::endl;
            continue;
        }

        // if it is greater it will be popped in the if
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }

        // alternative - no useless pushesh
        // if (maxHeap.size() < k) {
        //     maxHeap.push(num);
        // }
        // else if (num < maxHeap.top()) {
        //     maxHeap.pop();
        //     maxHeap.push(num);
        // }
    }
}
