def solution(box, n):
    x, y, h = box
    
    return (x // n) * (y // n) * (h // n)