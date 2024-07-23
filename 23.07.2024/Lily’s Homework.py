def lilysHomework(arr):
    def min_swaps(arr):
        n = len(arr)
        sorted_arr = sorted(arr)
        index = {value: i for i, value in enumerate(arr)}
        swaps = 0
        for i in range(n):
            if arr[i] != sorted_arr[i]:
                swaps += 1
                swap_idx = index[sorted_arr[i]]
                arr[i], arr[swap_idx] = arr[swap_idx], arr[i]
                index[arr[swap_idx]], index[arr[i]] = swap_idx, i
        return swaps

    return min(min_swaps(arr[:]), min_swaps(arr[::-1]))

arr = [2, 5, 3, 1]
print(lilysHomework(arr))
