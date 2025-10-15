def solution(before, after):
    before_sorted, after_sorted = sorted(before), sorted(after)
    return 1 if before_sorted == after_sorted else 0