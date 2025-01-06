from collections import defaultdict 


def dijkstra(graph, start, end):
    dist = {node: 0 for node in graph.keys()}
    dist[start] = 1

    pq = [(-1, start)]

    while len(pq):
        node_dist, node = heapq.heappop(pq)

        for neighb, prob in graph[node]:
            
            if prob * -node_dist > dist[neighb]:
                dist[neighb] = prob * -node_dist
                heapq.heappush(pq, (-dist[neighb], neighb))

    if end not in graph:
        return 0

    return dist[end]


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = defaultdict(list)

        for edge, prob in zip(edges, succProb):
            graph[edge[0]].append((edge[1], prob))
            graph[edge[1]].append((edge[0], prob))

        return dijkstra(graph, start_node, end_node)