def solution(hp):
    answer = 0
    current_hp = hp
    
    answer += (current_hp // 5)
    current_hp %= 5
    
    if current_hp != 0 and current_hp >= 3:
        answer += (current_hp // 3)
        current_hp %= 3
        
    answer += current_hp
    
    return answer