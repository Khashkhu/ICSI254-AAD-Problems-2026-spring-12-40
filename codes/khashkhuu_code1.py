#testcodea
import sys

sys.setrecursionlimit(10**7)
input = sys.stdin.readline

# ---------- DSU ----------
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1]*n

    def find(self, x):
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x

    def unite(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True


def main():
    N, M = map(int, input().split())
    NM = N*M

    cells = []
    for i in range(N):
        row = list(map(int, input().split()))
        for j in range(M):
            cells.append((row[j], i*M + j))

    # sort by height
    cells.sort()

    dsu = DSU(NM)
    active = [0]*NM

    year_to_lakes = []     # (height, lakeCount)
    lakes_to_year = []    # (lakeCount, height)

    lakeCount = 0
    p = 0

    while p < NM:
        h = cells[p][0]
        start = p
        while p < NM and cells[p][0] == h:
            p += 1
        end = p

        # activate all cells with this height
        for t in range(start, end):
            idx = cells[t][1]
            active[idx] = 1
            lakeCount += 1

            r = idx // M
            c = idx % M

            def try_union(nb):
                nonlocal lakeCount
                if active[nb]:
                    if dsu.unite(idx, nb):
                        lakeCount -= 1

            if r > 0:
                try_union((r-1)*M + c)
            if r+1 < N:
                try_union((r+1)*M + c)
            if c > 0:
                try_union(r*M + (c-1))
            if c+1 < M:
                try_union(r*M + (c+1))

        year_to_lakes.append((h, lakeCount))
        lakes_to_year.append((lakeCount, h))

    # compress lakes_to_year to earliest year
    lakes_to_year.sort()
    first = {}
    for k, y in lakes_to_year:
        if k not in first:
            first[k] = y

    # for binary search on year_to_lakes
    heights = [x[0] for x in year_to_lakes]
    counts = [x[1] for x in year_to_lakes]

    import bisect

    Q = int(input())
    out = []

    for _ in range(Q):
        A, B = map(int, input().split())
        if A == 1:
            # year B -> lakes
            pos = bisect.bisect_right(heights, B) - 1
            if pos < 0:
                out.append("0")
            else:
                out.append(str(counts[pos]))
        else:
            # lakeCount B -> earliest year
            out.append(str(first[B]) if B in first else "-1")

    print("\n".join(out))


if __name__ == "__main__":
    main()
