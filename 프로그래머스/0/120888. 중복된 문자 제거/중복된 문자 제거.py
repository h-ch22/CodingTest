def solution(my_string):
    answer = ''
    keys = []
    
    for s in my_string:
        if not s in keys:
            keys.append(s)
            answer += s
            
    return answer