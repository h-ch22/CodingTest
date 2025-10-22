def solution(dots):
    w = abs(dots[0][0] - dots[2][0] if dots[0][0] == dots[3][0] else dots[0][0] - dots[3][0])
    h = abs(dots[1][1] - dots[2][1] if dots[1][1] == dots[3][1] else dots[1][1] - dots[3][1])
    
    return w * h