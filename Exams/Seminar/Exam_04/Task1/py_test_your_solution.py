# ===============================
# Задача 1 (60т) - Тестове
# ===============================

"""Напиши твоето решение тук без приемането на входа!"""


def longest_subarray(nums, k):
    freq = {}
    left = 0
    best = 0

    for right in range(len(nums)):
        x = nums[right]
        freq[x] = freq.get(x, 0) + 1

        while freq[x] > k:
            y = nums[left]
            freq[y] -= 1
            left += 1

        best = max(best, right - left + 1)

    return best


# ====== Тестове ======
def test_longest_subarray():
    tests = [
        # Пример от условието
        (([1, 3, 4, 1, 3, 2, 1, 1], 2), 6),
        # Допълнителни тестове
        (([1, 1, 1, 1], 2), 2),
        (([1, 2, 3, 4, 5], 1), 5),
        (([1, 2, 2, 2, 3, 3, 3], 2), 4),
        (([], 1), 0),  # празен списък
        (([5, 5, 5, 5, 5], 3), 3),
        (([1, 2, 1, 2, 1, 2], 2), 4),
        (([1, 2, 3, 1, 2, 3, 1, 2, 3], 2), 6),
    ]

    for i, ((nums, k), expected) in enumerate(tests, 1):
        result = longest_subarray(nums, k)
        print(f"Тест {i}: nums={nums}, K={k} → изход={result} | очаквано={expected}")
        assert result == expected, f"Грешка при тест {i}, очаквано {expected}, получено {result}"


# Стартиране на тестовете
if __name__ == "__main__":
    test_longest_subarray()
    print("Всички тестове преминаха успешно.")
