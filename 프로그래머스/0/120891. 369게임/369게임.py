def solution(order):
    answer = 0
    order_s = str(order)
    
    answer += order_s.count('3')
    answer += order_s.count('6')
    answer += order_s.count('9')
    
    return answer