# ===============================
# Задача 2 (40 точки) - Тестове
# ===============================

"""Напиши твоето решение тук без приемането на входа!"""


def minimal_loss_probability(P):
    """
    P: NxN matrix of floats (probabilities)
    Returns the minimal probability to lose the game.
    """
    if not P or not P[0]:
        return 0.0

    N = len(P)
    # dp[i][j] = maximal survival probability to reach (i,j)
    dp = [[0.0] * N for _ in range(N)]
    dp[0][0] = 1.0 - P[0][0]  # survival chance at start

    # fill first row
    for j in range(1, N):
        dp[0][j] = dp[0][j - 1] * (1.0 - P[0][j])

    # fill first column
    for i in range(1, N):
        dp[i][0] = dp[i - 1][0] * (1.0 - P[i][0])

    # fill rest of the grid
    for i in range(1, N):
        for j in range(1, N):
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) * (1.0 - P[i][j])

    # minimal loss probability = 1 - maximal survival probability
    return 1.0 - dp[N - 1][N - 1]


# ====== Тестове ======
def test_minimal_loss_probability():
    tests = [
        # Пример от условието
        ([[0, 0.25, 0.5], [0.4, 0.5, 0.5], [0.1, 0, 0]], 0.46),
        # Допълнителни тестове
        ([[0, 0.1], [0.2, 0]], 0.1),
        ([[0]], 0.0),  # само едно поле
        ([[0, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0]], 0.875),
        ([[0, 0.1, 0.2], [0.2, 0.1, 0.3], [0.1, 0.2, 0]], 0.352),
    ]

    for i, (P, expected) in enumerate(tests, 1):
        result = minimal_loss_probability(P)
        # закръгляме до 4 цифри за точност
        result_rounded = round(result, 4)
        expected_rounded = round(expected, 4)
        print(f"Тест {i}: изход={result_rounded} | очаквано={expected_rounded}")
        assert (
            result_rounded == expected_rounded
        ), f"Грешка при тест {i}, очаквано {expected_rounded}, получено {result_rounded}"


# Стартиране на тестовете
if __name__ == "__main__":
    test_minimal_loss_probability()
    print("Всички тестове преминаха успешно.")
