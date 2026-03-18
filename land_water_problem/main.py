from collections import deque

def count_islands(grid):
    n = len(grid)
    visited = [[False]*n for _ in range(n)]

    # Only 4 directions (NO diagonals)
    directions = [(-1,0), (1,0), (0,-1), (0,1)]

    def dfs(x, y):
        visited[x][y] = True
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n:
                if not visited[nx][ny] and grid[nx][ny] == 1:
                    dfs(nx, ny)

    count = 0

    for i in range(n):
        for j in range(n):
            if grid[i][j] == 1 and not visited[i][j]:
                dfs(i, j)
                count += 1

    return count


# 🧪 TEST GRIDS

grid1 = [
    [1, 1, 0, 0],
    [0, 1, 0, 1],
    [0, 0, 1, 1],
    [1, 0, 0, 0]
]  # Expected: 3

grid2 = [
    [0, 0],
    [0, 0]
]  # Expected: 0

grid3 = [
    [1, 1],
    [1, 1]
]  # Expected: 1

grid4 = [
    [1, 0, 1],
    [0, 1, 0],
    [1, 0, 1]
]  # Expected: 5 (diagonals NOT connected)

grid5 = [
    [1, 0, 0, 1],
    [0, 0, 0, 0],
    [1, 0, 1, 0],
    [0, 0, 0, 1]
]  # Expected: 5

grid6 = [
    [1, 1, 0],
    [0, 1, 0],
    [0, 1, 1]
]  # Expected: 1


# RUN TESTS

tests = [grid1, grid2, grid3, grid4, grid5, grid6]
expected = [3, 0, 1, 5, 5, 1]

for i in range(len(tests)):
    result = count_islands(tests[i])
    print(f"Test {i+1}: Got = {result}, Expected = {expected[i]}")
