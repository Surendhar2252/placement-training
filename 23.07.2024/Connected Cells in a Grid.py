def max_region(grid):
    def dfs(x, y):
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]) or not grid[x][y]:
            return 0
        grid[x][y] = 0
        return 1 + sum(dfs(x+dx, y+dy) for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)])

    return max(dfs(x, y) for x in range(len(grid)) for y in range(len(grid[0])))

grid = [
    [1, 1, 0, 0],
    [0, 1, 1, 0],
    [0, 0, 1, 0],
    [1, 0, 0, 0]
]
print(max_region(grid))
