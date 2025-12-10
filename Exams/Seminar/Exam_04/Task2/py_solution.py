def minimal_loss_probability(P):
    """
    P: NxN matrix of floats (probabilities)
    Returns the minimal probability to lose the game.
    """
    if not P or not P[0]:
        return 0.0

    N = len(P)
    dp = [[0.0] * N for _ in range(N)]
    dp[0][0] = 1.0 - P[0][0]

    for j in range(1, N):
        dp[0][j] = dp[0][j - 1] * (1.0 - P[0][j])

    for i in range(1, N):
        dp[i][0] = dp[i - 1][0] * (1.0 - P[i][0])

    for i in range(1, N):
        for j in range(1, N):
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) * (1.0 - P[i][j])

    return 1.0 - dp[N - 1][N - 1]
