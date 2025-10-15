def solution(s):
    answer = 0
    s_split = s.split()
    stack = []
    
    for c in s_split:
        if c == 'Z':
            answer -= stack[-1]
            stack.pop()
            
        else:
            answer += int(c)
            stack.append(int(c))
    
    return answer