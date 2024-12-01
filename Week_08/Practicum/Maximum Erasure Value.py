class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        ans = []
        current_sum = 0
        q = deque()
        s = set()

        for num in nums:
            if num in s:
                while q and q[0] != num:
                    current_sum -= q[0]
                    s.remove(q[0])
                    q.popleft()
                current_sum -= num
                s.remove(num)
                q.popleft()

            q.append(num)
            current_sum += num
            s.add(num)
            ans.append(current_sum)

        return max(ans)