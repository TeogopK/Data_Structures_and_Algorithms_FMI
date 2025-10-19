###### (20.10.2025)
## Задачи:

#### Easy
- [**Merge sorted arrrays**](https://leetcode.com/problems/merge-sorted-array)
- [**Move zeroes**](https://leetcode.com/problems/move-zeroes)
  
#### Medium
- [**Hand-written Sort O(n*logN)**](https://leetcode.com/problems/sort-an-array/)
  - Merge sort
  
#### Hard
- [**Merge K sorted linked lists**](https://leetcode.com/problems/merge-k-sorted-lists/)
  - N is the sum of all elements
  - K is the count of linked lists in input
      - N * K (Time complexity) - Naive with memory complexity O(N) <-> O(N) in heap and O(N) from recursion stack
      - (N + K) * log(K) - Warning solution: Merge with copying vectors on recursion steps (The steps are log(K), but the memory complexity: O(K*logK)
      - N * log(K) - Merge lists with indexes <-> memory complexity O(logK)
