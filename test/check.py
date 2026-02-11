from collections import deque
import sys

input = sys.stdin.readline

# t үед хэдэн нуур байгааг brute force-оор бодох
def count_lakes(grid, t):
    N = len(grid)
    M = len(grid[0])

    water = [[grid[i][j] <= t for j in range(M)] for i in range(N)]
    vis = [[False]*M for _ in range(N)]

    def bfs(si, sj):
        q = deque()
        q.append((si, sj))
        vis[si][sj] = True
        while q:
            x, y = q.popleft()
            for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                nx, ny = x+dx, y+dy
                if 0 <= nx < N and 0 <= ny < M:
                    if water[nx][ny] and not vis[nx][ny]:
                        vis[nx][ny] = True
                        q.append((nx, ny))

    lakes = 0
    for i in range(N):
        for j in range(M):
            if water[i][j] and not vis[i][j]:
                lakes += 1
                bfs(i, j)

    return lakes


def main():
    N, M = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]

    Q = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(Q)]

    # боломжит бүх t (матриц дээрх өндөр)
    heights = sorted(set(v for row in grid for v in row))

    # year -> lakeCount
    lake_at_year = {}
    for h in heights:
        lake_at_year[h] = count_lakes(grid, h)

    # lakeCount -> earliest year
    first_year = {}
    for h in heights:
        c = lake_at_year[h]
        if c not in first_year:
            first_year[c] = h

    # асуултуудад хариулах
    for A, B in queries:
        if A == 1:
            # t онд хэдэн нуур?
            ans = count_lakes(grid, B)
            print(ans)
        else:
            # яг B нуур анх хэдэн онд?
            print(first_year[B] if B in first_year else -1)


if __name__ == "__main__":
    main()
