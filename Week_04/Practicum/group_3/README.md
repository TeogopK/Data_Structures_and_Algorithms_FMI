###### (3.11.2025)
## Задачи:

#### Hard
- [**Merge K sorted linked lists**](https://leetcode.com/problems/merge-k-sorted-lists/)
  - N is the sum of all elements
  - K is the count of linked lists in input
      - N * K (Time complexity) - Naive with memory complexity O(N) <-> O(N) in heap and O(N) from recursion stack
      - (N + K) * log(K) - Warning solution: Merge with copying vectors on recursion steps (The steps are log(K), but the memory complexity: O(K*logK)
      - N * log(K) - Merge lists with indexes <-> memory complexity O(logK)

