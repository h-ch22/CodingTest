def solution(num, k):
    answer = list(map(int, str(num)))
    return answer.index(k)+1 if k in answer else -1