def solution(spell, dic):
    answer = 0
    
    for d in dic:
        is_break = False
        
        for s in spell:
            if not s in d:
                is_break = True
                break
                
        if not is_break:
            return 1
    
    return 2