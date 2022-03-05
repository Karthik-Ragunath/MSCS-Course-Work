def kthlargest(arr1, arr2, k):
    if len(arr1) == 0:
        return arr2[k]
    elif len(arr2) == 0:
        return arr1[k]

    mida1 = len(arr1) // 2  # integer division
    mida2 = len(arr2) // 2
    if mida1 + mida2 < k:
        if arr1[mida1] > arr2[mida2]:
            return kthlargest(arr1, arr2[mida2+1:], k - mida2 - 1)
        else:
            return kthlargest(arr1[mida1+1:], arr2, k - mida1 - 1)
    else:
        if arr1[mida1] > arr2[mida2]:
            return kthlargest(arr1[:mida1], arr2, k)
        else:
            return kthlargest(arr1, arr2[:mida2], k)

arr1 = [1,2,3,4,8]
arr2 = [5,6,7]
rank = 2
pivot = rank - 1
kth_rank = kthlargest(arr1, arr2, pivot)
print(kth_rank)