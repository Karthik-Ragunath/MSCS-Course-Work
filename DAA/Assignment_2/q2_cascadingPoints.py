# your code goes here
def merge_points(left_sub_points, right_sub_points):
	left_sub_points_len = len(left_sub_points)
	ptr_l = 0
	ptr_r = 0
	merged_points = []
	# print("left_sub_points_len:", left_sub_points_len)
	while ptr_l < left_sub_points_len:
		# print("ptr_l:", ptr_l)
		if left_sub_points[ptr_l][1] < right_sub_points[ptr_r][1]:
			break
		merged_points.append(left_sub_points[ptr_l])
		ptr_l += 1
	merged_points.extend(right_sub_points)
	# print("MP:", merged_points)
	return merged_points


def divide_and_conquer(sorted_coords, low, high):
	if low == high:
		return [sorted_coords[low]]
	mid = int((low + high) / 2)
	# print(low, mid, high)
	left_sub_points = divide_and_conquer(sorted_coords, low, mid)
	right_sub_points = divide_and_conquer(sorted_coords, mid + 1, high)
	# print("-------")
	# print(left_sub_points, right_sub_points)
	# print("-------")
	merged_points = merge_points(left_sub_points, right_sub_points)
	return merged_points

coords = [(2,4), (5,5), (7,3), (9,7), (11,4), (12,5), (14,1)]
sorted_coords = sorted(coords, key = lambda k: k[0])
merged_points = divide_and_conquer(sorted_coords, 0, len(sorted_coords) - 1)
print("Cascading Points:", merged_points)
