# your code goes here
def merge_points(left_points, right_points, count_inv_l, count_inv_r):
	ptr_l = 0
	ptr_r = 0
	left_points_len = len(left_points)
	right_points_len = len(right_points)
	merged_points = []
	count_invs = 0
	# print("**************")
	# print(left_points, right_points)
	while ptr_r < right_points_len:
		if ptr_l == left_points_len:
			break
		if left_points[ptr_l] < right_points[ptr_r]:
			merged_points.append(left_points[ptr_l])
			ptr_l += 1
		else:
			merged_points.append(right_points[ptr_r])
			count_invs += (left_points_len - ptr_l)
			ptr_r += 1
	if ptr_r != right_points_len:
		merged_points.extend(right_points[ptr_r:right_points_len])
	if ptr_l != left_points_len:
		merged_points.extend(left_points[ptr_l:left_points_len])
	total_count_inversions = count_invs + count_inv_l + count_inv_r
	# print(count_invs, count_inv_l, count_inv_r)
	return total_count_inversions, merged_points
	

def divide_and_conquer(points, low, high):
	if low == high:
		# print("T:", low, [points[low]])
		return 0, [points[low]]
	mid = int((low + high) / 2)
	# print("----------")
	# print("Mid:", mid, "L:", low, "H:", high)
	# print("----------")
	count_inversion_l, left_inversions = divide_and_conquer(points, low, mid)
	# print("T1:", count_inversion_l, left_inversions)
	count_inversion_r, right_inversions = divide_and_conquer(points, mid + 1, high)
	# print("T2:", count_inversion_r, right_inversions)
	count_total, total_inversions = merge_points(left_inversions, right_inversions, count_inversion_l, count_inversion_r)
	return count_total, total_inversions

# points = [6,5,4,3,2,1]
points = [1,2,3,4,5,6]
# points = [1,2,3,5,4,-1,-2]
low = 0
high = len(points) - 1
count_inversions, sorted_list = divide_and_conquer(points, low, high)
print(count_inversions)