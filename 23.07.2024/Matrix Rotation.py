def rotate_matrix(matrix):
    return [list(reversed(col)) for col in zip(*matrix)]

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
print(rotate_matrix(matrix))
