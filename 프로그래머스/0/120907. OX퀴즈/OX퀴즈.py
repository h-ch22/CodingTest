def solution(quiz):
    answer = []
    
    for q in quiz:
        first_num, op, second_num, _, result = q.split()
        r = int(first_num) + int(second_num) if op == '+' else int(first_num) - int(second_num)
        
        answer.append('O' if r == int(result) else 'X')
    
    return answer