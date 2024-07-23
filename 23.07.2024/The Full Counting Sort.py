def count_sort(arr):
    count = [[] for _ in range(100)]
    n = len(arr) // 2
    for i, (num, word) in enumerate(arr):
        if i < n:
            count[int(num)].append("-")
        else:
            count[int(num)].append(word)
    result = []
    for bucket in count:
        result.extend(bucket)
    return " ".join(result)

arr = [(0, "a"), (1, "b"), (0, "c"), (1, "d")]
print(count_sort(arr))  # Example input
