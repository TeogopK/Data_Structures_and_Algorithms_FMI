def can_we_place_K_routers_with_atleast_D_distance(rooms, N, K, D):
    """
    We can early exit the function when count == K.
    This means we can place K routers with minimum distance D.
    All other rooms after the room with the Kth router do not matter to us.
    They do not change the minimum distance between all routers.

    If we get to the end and still need to place routers, the answer is False (No).
    """
    count = 1
    last = rooms[0]

    for i in range(1, N):
        if rooms[i] - last >= D:
            count += 1
            last = rooms[i]
            if count == K:
                return True

    return False


def binary_search(rooms, N, K):
    """
    1, 2, 4, 8, 9
    We start by searching for distance 8 which will be the best distance - the biggest.
    Can we put all K routers with at least 8 distance between them.
    We put the first router always in the leftmost room.
    Can we put another one at room[0] + D.
    Lets see iteratively which room is at least D distance to the first one.
    When we get to that room we add another router. And repeat the same process.

    If we go to the end of the rooms and we must put another router - well it is not possible.
    So we should try with a smaller D.

    If it is possible to put K routers with distance of at least D, we try a bigger D.

    For our example, we put a router at the last room.
    But we must put another one since K = 3 and we have only 2 placed.
    There is no space for another one.
    So lets try with a smaller D.

    The monotonic function we are searching onto will look like this:

    1 2 3 4 5 6 7 8
    v v v x x x x x
    """
    l = 0
    r = rooms[-1] - rooms[0]

    answer = r

    while l <= r:
        m = (l + r) // 2

        if not can_we_place_K_routers_with_atleast_D_distance(rooms, N, K, m):
            r = m - 1
        else:
            l = m + 1
            answer = m  # Note where the answer is updated.

    return answer


N, K = map(int, input().split())
rooms = list(map(int, input().split()))

rooms.sort()

answer = binary_search(rooms, N, K)
print(answer)
