# your code goes here
def longest_common_subsequence(A, B, cur_A, cur_B, n, m):
	if cur_A >= n or cur_B >= m:
		return 0
	ignore = max(longest_common_subsequence(A, B, cur_A, cur_B + 1, n, m), longest_common_subsequence(A, B, cur_A + 1, cur_B, n, m))
	best = ignore
	if A[cur_A] == B[cur_B]:
		include = 1 + longest_common_subsequence(A, B, cur_A + 1, cur_B + 1, n, m)
		if include > ignore:
			best = include
	return best
	
A = [1,2,3,5,7,9,10]
B = [23, 45, 9, 11, 10]
n = len(A)
m = len(B)
sol = longest_common_subsequence(A, B, 0, 0, n, m)
print(sol)