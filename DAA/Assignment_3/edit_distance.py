# your code goes here
A = "algorithm"
B = "altruistic"

def edit_distance(A, B, n, m, cur_A, cur_B):
	if cur_A == 0:
		return cur_B
	if cur_B == 0:
		return cur_A
	insertion = 1 + edit_distance(A, B, n, m, cur_A, cur_B - 1)
	deletion = 1 + edit_distance(A, B, n, m, cur_A - 1, cur_B)
	substitution = edit_distance(A, B, n, m, cur_A - 1, cur_B - 1) + (A[cur_A] != B[cur_B])
	return min(insertion, deletion, substitution)
	
edit_dist = edit_distance(A, B, len(A) - 1, len(B) - 1, len(A) - 1, len(B) - 1)
print(edit_dist)