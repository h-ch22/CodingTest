import sys
sys.setrecursionlimit(10**6)

def solve():
    ans = 0

    # 1. 열(수직)에 퀸이 있는지 확인
    v_col = [False] * n

    """
    2. 오른쪽 위 대각선에 퀸이 있는지 확인 (r + c)
    r + c의 최대값은 (n-1) + (n-1) = 2n-2
    """
    v_ne = [False] * (2 * n)

    """
    3. 왼쪽 위 대각선에 퀸이 있는지 확인 (r - c)
    r - c의 최대값은 -(n-1) ~ (n-1)이지만, 인덱스를 양수로 만들어야 함. (+n 처리)
    """
    v_nw = [False] * (2 * n)

    def dfs(row):
        nonlocal ans

        # 모든 행에 퀸을 놓았다면 성공
        if row == n:
            ans += 1
            return

        for col in range(n):
            # 현재 (r, c) 위치에 퀸을 놓을 수 있는지 확인
            if v_col[col] or v_ne[row + col] or v_nw[row - col + n]:
                continue

            v_col[col] = True
            v_ne[row + col] = True
            v_nw[row - col + n] = True

            dfs(row + 1)

            v_col[col] = False
            v_ne[row + col] = False
            v_nw[row - col + n] = False

    dfs(0)
    return ans


n = int(sys.stdin.readline().strip())
print(solve())
