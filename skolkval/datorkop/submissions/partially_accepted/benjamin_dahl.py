import sys
import heapq

def ceil_div(p, q):
    return (p + q - 1) // q

def solve():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    x, a, y, b, n = map(int, data[:5])

    total = x * a + y * b

    if n == 1:
        sys.stdout.write(str(total))
        return

    if n == 2:
        best = 0
        for i in range(x + 1):
            val_a = i * a
            num = total - 2 * val_a
            if num <= 0:
                candidates = (0,)
            else:
                j0 = num // (2 * b)
                candidates = (j0 - 1, j0, j0 + 1, j0 + 2)
            for j in candidates:
                if 0 <= j <= y:
                    v = val_a + j * b
                    m = v if v <= total - v else total - v
                    if m > best:
                        best = m
        sys.stdout.write(str(best))
        return

    if a > b:
        a, b = b, a
        x, y = y, x
        total = x * a + y * b

    def t_required(V, j):
        diff = V - j * b
        if diff <= 0:
            return 0
        return ceil_div(diff, a)

    def ok(V):
        if V <= 0:
            return True
        hb = ceil_div(V, b)
        need_b = n * hb
        if y >= need_b:
            return True
        R = need_b - y
        if R > x:
            return False

        heap = []

        def push(j, t):
            if j <= 0:
                return
            nt = t_required(V, j - 1)
            heapq.heappush(heap, (nt - t, j - 1, nt))

        for _ in range(n):
            push(hb, 0)

        cost = 0
        red = 0
        while heap and red < R:
            d, nj, nt = heapq.heappop(heap)
            cost += d
            if cost > x:
                return False
            red += 1
            push(nj, nt)

        return red >= R

    lo, hi = 0, total
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if ok(mid):
            lo = mid
        else:
            hi = mid - 1

    sys.stdout.write(str(lo))

if __name__ == "__main__":
    solve()
