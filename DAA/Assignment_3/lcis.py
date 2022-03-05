# your code goes here
def lcis(A, B, prev_A, prev_B, cur_A, cur_B, n, m):
	if cur_A >= n:
		return 0
	if cur_B >= m:
		return 0
	ignore = max(lcis(A, B, prev_A + 1, prev_B, cur_A + 1, cur_B), lcis(A, B, prev_A, prev_B + 1, cur_A, cur_B + 1), lcis(A, B, prev_A, prev_B, cur_A + 1, cur_B, n, m), lcis(A, B, prev_A, prev_B, cur_A, cur_B + 1, n, m))
	best = ignore
	if A[cur_A] == B[cur_B] and A[cur_A] > A[prev_A] and B[cur_B] > B[prev_B]:
		print(cur_A, cur_B, prev_A, prev_B)
		include = 1 + lcis(A, B, cur_A, cur_B, cur_A + 1, cur_B + 1, n, m)
		if include > ignore:
			best = include
	return best
	
A = [1,2,89, 98, 3, 0, 4, 6]
B = [87, 2, 43, 78, 1, 3, 78, 5, 4, 8, 6]
n = len(A)
m = len(B)
sol = lcis(A, B, 0, 0, 1, 1, len(A) - 1, len(B) - 1)
print(sol)