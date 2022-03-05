def recursive_cuts(n,m,p):
    if (n == 0  or  m == 0):
        return 0 # Base Case.
    else:
        max_val = p[n - 1][m - 1] # Full Slab
        for i in range(1, int(n/2) + 1): # Horizontal Cuts.
            max_val = max(max_val, (recursive_cuts(i,m,p) + recursive_cuts(n-i,m,p)))
        for j in range(1, int(m/2) + 1): # Vertical Cuts.
            max_val = max(max_val, (recursive_cuts(n,j,p) + recursive_cuts(n,m-j,p)))
    return max_val

def solution(p):
    n = len(p)
    m = len(p[0])
    max_profit = recursive_cuts(n,m,p)
    return max_profit

p = [[3,45,8], [12,23,34]]
max_profit = solution(p)
print(max_profit)