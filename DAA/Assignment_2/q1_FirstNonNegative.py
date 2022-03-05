# your code goes here
a = [-4, -3, -2, -1, 0, 1, 2]
def find_n_gt_zero(input_list, low = None, high = None):
	if low == high:
		return low # given there is atleast one element > 0
	mid = int((low + high) / 2)
	if a[mid] <= 0:
		return find_n_gt_zero(input_list, low=mid + 1, high=high)
	else:
		return find_n_gt_zero(input_list, low=low, high=mid)

smallest_n_gt_zero = find_n_gt_zero(a, low = 0, high = len(a))
print(smallest_n_gt_zero)