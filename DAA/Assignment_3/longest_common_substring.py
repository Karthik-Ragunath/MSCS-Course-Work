# your code goes here
global_best = 0
def longest_common_substring(A, B, cur_A, cur_B, n, m):
	global global_best
	if cur_A >= n or cur_B >= m:
		return 0
	ignore = max(longest_common_substring(A, B, cur_A, cur_B + 1, n, m), longest_common_substring(A, B, cur_A + 1, cur_B, n, m))
	best = 0
	if A[cur_A] == B[cur_B]:
		include = 1 + longest_common_substring(A, B, cur_A + 1, cur_B + 1, n, m)
		best = include
		if include > global_best:
			global_best = include
	return best
	
A = [1, 2, 3, 5, 7, 9, 10, 12]
B = [23, 45, 2, 3, 5, 9, 11, 10, 12]
n = len(A)
m = len(B)
sol = longest_common_substring(A, B, 0, 0, n, m)
print(global_best)