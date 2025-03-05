def solution(numbers):
    answer = []
    
    for i, n in enumerate(numbers):
        for j in range(i+1, len(numbers)):
            answer.append(n + numbers[j])
    
    answer = list(set(answer))
    
    return list(sorted(answer))