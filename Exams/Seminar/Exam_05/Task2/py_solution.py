import heapq


def add_to_pq(num, pq):
    if len(pq) < K:
        heapq.heappush(pq, -num)

    elif len(pq) == K and num < -pq[0]:
        heapq.heappop(pq)
        heapq.heappush(pq, -num)


def get_k_lowest(pq, K):
    k_lowest = -pq[0] if len(pq) >= K else -1

    print(k_lowest)
    return k_lowest


K = int(input())
arr = list(map(int, input().split()))

QUERY_SYMBOL = 0

pq = []
for num in arr:
    if num == QUERY_SYMBOL:
        get_k_lowest(pq, K)
    else:
        add_to_pq(num, pq)
