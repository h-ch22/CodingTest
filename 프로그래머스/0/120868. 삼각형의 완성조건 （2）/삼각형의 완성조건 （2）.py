def solution(sides):
    answer = 0
    longest = max(sides)
    shortest = min(sides)
    results = []
    
    # 가장 긴 변이 longest_side인 경우
    for i in range(longest, 0, -1):
        if i + shortest > longest:
            results.append(i)
            
        else:
            break
            
    # 나머지 한 변이 가장 긴 변인 경우
    for i in range(1, sum(sides)):
        if sum(sides) > i and longest < i:
            results.append(i)
        
    results = list(set(results))
    
    return len(results)