import collections

def solution(emergency):
    answer = [0 for _ in emergency]
    priority = {}
    e_sorted = sorted(emergency, reverse=True)
    
    for i, e in enumerate(e_sorted):
        answer[emergency.index(e)] = i+1
    
    return answer