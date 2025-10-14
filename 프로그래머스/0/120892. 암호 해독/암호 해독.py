def solution(cipher, code):
    answer = [cipher[x-1] for x in range(1, len(cipher)+1) if x % code == 0]
    return ''.join(answer)