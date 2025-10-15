def solution(my_string):
    answer = 0
    exp = my_string.split()
    answer = int(exp[0])
    
    for i in range(1, len(exp), 2):
        op = exp[i]
        target = int(exp[i+1])

        if op == '+':
            answer += target
            
        else:
            answer -= target
                
    return answer