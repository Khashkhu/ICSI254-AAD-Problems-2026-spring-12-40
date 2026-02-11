def dp_solution_with_path(a, n):
    dp = [[0]*n for _ in range(n)]
    parent = [[None]*n for _ in range(n)]

    dp[0][0] = a[0][0]

    # First row
    for j in range(1, n):
        dp[0][j] = dp[0][j-1] + a[0][j]
        parent[0][j] = (0, j-1)

    # First column
    for i in range(1, n):
        dp[i][0] = dp[i-1][0] + a[i][0]
        parent[i][0] = (i-1, 0)

    # Fill DP
    for i in range(1, n):
        for j in range(1, n):
            if dp[i-1][j] > dp[i][j-1]:
                dp[i][j] = dp[i-1][j] + a[i][j]
                parent[i][j] = (i-1, j)
            else:
                dp[i][j] = dp[i][j-1] + a[i][j]
                parent[i][j] = (i, j-1)

    # Reconstruct path
    path = set()
    i, j = n-1, n-1
    while True:
        path.add((i, j))
        if parent[i][j] is None:
            break
        i, j = parent[i][j]

    return dp[n-1][n-1], path


# INPUT (only once!)
n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

max_value, path = dp_solution_with_path(a, n)

print("Max value:", max_value)
print("Path:")

for i in range(n):
    for j in range(n):
        if (i, j) in path:
            print(f"*{a[i][j]:2}", end=" ")
        else:
            print(f" {a[i][j]:2}", end=" ")
    print()