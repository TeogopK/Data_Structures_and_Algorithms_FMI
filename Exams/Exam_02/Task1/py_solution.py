def can_finish(X, H, boxes):
    import math

    # Закръгляме нагоре нужните часове т.е. 5 големина с 4 скорост изисква 2 часа
    hours = sum(math.ceil(box_amount / X) for box_amount in boxes)
    return hours <= H


def min_eating_speed(boxes, H):
    if not boxes or H <= 0:
        return 0

    left, right = 1, max(boxes)
    answer = right  # Приемаме, че няма вариант, в който да има невъжможен случай. (-1)

    while left <= right:
        mid = (left + right) // 2

        if can_finish(mid, H, boxes):
            right = mid - 1
            answer = mid
        else:
            left = mid + 1

    return answer


N, H = map(int, input().split())
boxes = list(map(int, input().split()))

result = min_eating_speed(boxes, H)
print(result)
