def cost(B):
    low, high = 0, 0
    for i in range(1, len(B)):
        low_next = max(low, high + B[i-1] - 1)
        high_next = max(high + abs(B[i] - B[i-1]), low + B[i] - 1)
        low, high = low_next, high_next
    return max(low, high)

B = [10, 1, 10, 1, 10]
print(cost(B))
