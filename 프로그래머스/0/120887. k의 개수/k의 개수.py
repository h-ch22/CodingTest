def solution(i, j, k):
    nums = ''.join([str(n) for n in range(i, j+1)])
    return nums.count(str(k))