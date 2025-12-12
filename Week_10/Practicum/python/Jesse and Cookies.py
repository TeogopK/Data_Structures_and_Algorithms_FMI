def cookies(k, A):
    heapq.heapify(A)
    
    ans = 0
    
    while A[0] < k and len(A) >= 2:
        new_cookie = heapq.heappop(A) + 2 * heapq.heappop(A)
        
        heapq.heappush(A, new_cookie)
        ans += 1
        
    return ans if A[0] >= k else -1