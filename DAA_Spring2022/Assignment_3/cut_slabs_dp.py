def recursive_cuts(n,m,p):
    cuts_dp = [[0] * (m + 1)] * (n + 1)
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            max_profit = p[i - 1][j - 1]
            for k in range(1, int((i/2) + 1)):
                max_profit = max(max_profit, (cuts_dp[k][j] + cuts_dp[n - k][j]))
            for k in range(1, int((j/2) + 1)):
                max_profit = max(max_profit, (cuts_dp[i][k] + cuts_dp[i][m - k]))
            cuts_dp[i][j] = max_profit
    return max_profit

def solution(p):
    n = len(p)
    m = len(p[0])
    max_profit = recursive_cuts(n,m,p)
    return max_profit

p = [[3,45,8], [12,23,34]]
max_profit = solution(p)
print(max_profit)# your code goes here