def organizingContainers(container):
    row_sums = [sum(row) for row in container]
    col_sums = [sum(col) for col in zip(*container)]
    if sorted(row_sums) == sorted(col_sums):
        return "Possible"
    else:
        return "Impossible"

container = [
    [1, 1, 1],
    [0, 2, 0],
    [0, 0, 1]
]
print(organizingContainers(container))  # Example input
