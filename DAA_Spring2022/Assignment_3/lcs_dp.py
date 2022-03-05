def LCS(prev_prev, prev, start, n, A):
    lcs_dp = [[[None] * (n + 1)] * n] * (n - 1)
    for i in range(0, n - 1):
        for j in range(0, n):
            lcs_dp[i][j][n] = 0
    for start in range(n - 1, 1, -1):
        for prev in range(start - 1, 0, -1):
            for prev_prev in range(prev - 1, -1, -1):
                ignore = lcs_dp[prev_prev][prev][start + 1]
                best = ignore
                if A[prev] < ((A[prev_prev] + A[start]) / 2):
                    include = 1 + lcs_dp[prev][start][start + 1]
                    if include > ignore:
                        best = include
                    lcs_dp[prev_prev][prev][start] = best
    return lcs_dp[0][1][2]

def solution(A):
    n = len(A)
    if n < 3:
        return 0
    else:
        lcs = LCS(0, 1, 2, n, A)
        return lcs

A = [1, 3, 9, 8, 16]
print(solution(A))