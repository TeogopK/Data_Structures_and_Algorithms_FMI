class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        available_servers = [(server, idx) for idx, server in enumerate(servers)]
        
        heapq.heapify(available_servers)

        ans = []

        servers_taken = []

        current_time = 0

        for time, task_time in enumerate(tasks):
            current_time = max(time, current_time)

            if not available_servers:
                current_time, _ = servers_taken[0]

            task_end = current_time + task_time
                
            while servers_taken and servers_taken[0][0] <= current_time:
                _, server_idx = heapq.heappop(servers_taken)
                heapq.heappush(available_servers, (servers[server_idx], server_idx))

            server, server_idx = heapq.heappop(available_servers)
            
            ans.append(server_idx)

            heapq.heappush(servers_taken, (task_end, server_idx))

        return ans