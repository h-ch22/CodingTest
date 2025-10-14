from collections import deque

def solution(numbers, direction):
    nums_q = deque(numbers)
    
    if direction == 'left':
        first = nums_q.popleft()
        nums_q.append(first)
        
        return list(nums_q)
    
    else:
        last = nums_q.pop()
        nums_q.appendleft(last)
        
        return list(nums_q)
    