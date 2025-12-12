class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tasks = [(x[0], x[1], i) for i, x in enumerate(tasks)]
        tasks.sort()

        i, current_time = 0, tasks[0][0]

        ans, pq = [], []

        while i < len(tasks):
            while i < len(tasks) and current_time >= tasks[i][0]:
                enq_time, proc_time, idx = tasks[i]
                heapq.heappush(pq, (proc_time, idx))
                i += 1

            if pq:
                proc_time, idx = heapq.heappop(pq)
                current_time += proc_time
                ans.append(idx)
            else:
                current_time = tasks[i][0]

        while pq:
            proc_time, idx = heappop(pq)
            ans.append(idx)

        return ans