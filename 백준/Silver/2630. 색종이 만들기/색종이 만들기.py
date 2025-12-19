import sys

def div(x, y, n):
    color = papers[y][x]
    
    for i in range(y, y+n):
        for j in range(x, x+n):
            if color != papers[i][j]:
                m = n // 2
                div(x, y, m)
                div(x + m, y, m)
                div(x, y + m, m)
                div(x + m, y + m, m)
                return
            
    if color == 0:
        result[0] += 1
        
    else:
        result[1] += 1

n = int(sys.stdin.readline().strip())
papers = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
result = [0, 0]
div(0, 0, n)
print(f'{result[0]}\n{result[1]}')
