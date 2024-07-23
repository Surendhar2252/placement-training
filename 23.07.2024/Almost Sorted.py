def almostSorted(arr):
    sorted_arr = sorted(arr)
    if arr == sorted_arr:
        return "yes"
    n = len(arr)
    l, r = 0, n-1
    while l < n-1 and arr[l] <= arr[l+1]:
        l += 1
    while r > 0 and arr[r] >= arr[r-1]:
        r -= 1
    arr[l:r+1] = arr[l:r+1][::-1]
    return "yes" if arr == sorted_arr else "no"

arr = [1, 5, 4, 3, 2, 6]
print(almostSorted(arr))
