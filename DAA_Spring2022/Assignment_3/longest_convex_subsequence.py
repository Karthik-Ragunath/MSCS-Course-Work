def LCS(prev_prev, prev, start, n, A):
    if start >= n:
        return 0
    ignore = LCS(prev_prev, prev, start + 1, n, A)
    best = ignore
    if A[prev] < ((A[prev_prev] + A[start]) / 2):
        include = 1 + LCS(prev, start, start + 1, n, A)
        if include > ignore:
            best = include
    return best

def solution(A):
	A = [0,0] + A
	n = len(A)
	if n < 3:
		return 0
	else:
		lcs = LCS(0, 1, 2, n, A)
		return lcs

A = [1, 3, 9, 8, 16]
print(solution(A))