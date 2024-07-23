def balancedSums(arr):
    left_sum = 0
    right_sum = sum(arr)
    for num in arr:
        right_sum -= num
        if left_sum == right_sum:
            return "YES"
        left_sum += num
    return "NO"

arr = [1, 2, 3, 3]
print(balancedSums(arr))  # Expected output: "YES"
