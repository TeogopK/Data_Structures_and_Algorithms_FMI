# ===============================
# Задача 1 (50т) - Тестове
# ===============================

"""Напиши твоето решение тук без приемането на входа!"""


def can_finish(X, H, boxes):
    import math

    hours = sum(math.ceil(box_amount / X) for box_amount in boxes)
    return hours <= H


def min_eating_speed(boxes, H):
    if not boxes or H <= 0:
        return 0

    left, right = 1, max(boxes)
    answer = right

    while left <= right:
        mid = (left + right) // 2
        if can_finish(mid, H, boxes):
            right = mid - 1
            answer = mid
        else:
            left = mid + 1

    return answer


# ====== Тестове ======
def test_min_eating_speed():
    tests = [
        # Примерни тестове от условието
        (([3, 6, 7, 11], 8), 4),
        (([30, 11, 23, 4, 20], 5), 30),
        # Допълнителни тестове
        (([1, 1, 1, 1], 4), 1),  # точно 1 плод на час
        (([10, 10, 10, 10], 4), 10),  # точно 10 на час
        (([10, 10, 10, 10], 8), 5),  # 5 на час е достатъчно
        (([100], 10), 10),  # само една кутия
        (([5, 9, 7, 3, 8], 10), 4),  # различни стойности
        (([1000, 2000, 3000], 6), 1000),  # големи числа
        (([5], 1), 5),  # 1 кутия, 1 час
        (([], 5), 0),  # празен списък
    ]

    for i, ((boxes, h), expected) in enumerate(tests, 1):
        result = min_eating_speed(boxes, h)
        print(f"Тест {i}: кутии={boxes}, H={h} → изход={result} | очаквано={expected}")
        assert result == expected, f"Грешка при тест {i}"


# Стартиране на тестовете
if __name__ == "__main__":
    test_min_eating_speed()
    print("Всички тестове преминаха успешно.")
