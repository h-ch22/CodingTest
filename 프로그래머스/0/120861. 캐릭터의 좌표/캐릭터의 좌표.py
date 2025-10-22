def solution(keyinput, board):
    limit_x_min, limit_x_max = ((board[0] - 1) // 2) * -1, (board[0] - 1) // 2
    limit_y_min, limit_y_max = ((board[1] - 1) // 2) * -1, (board[1] - 1) // 2
    
    answer = [0, 0]
    
    for k in keyinput:
        if k == 'left' and limit_x_min < answer[0]:
            answer[0] -= 1
            
        elif k == 'right' and answer[0] < limit_x_max:
            answer[0] += 1
            
        elif k == 'up' and answer[1] < limit_y_max:
            answer[1] += 1
            
        elif k == 'down' and limit_y_min < answer[1]:
            answer[1] -= 1
    
    return answer