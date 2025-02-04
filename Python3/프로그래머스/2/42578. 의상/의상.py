import math

def solution(clothes):
    clothes_dict = { }
    
    for v, k in clothes:
        if k in clothes_dict.keys():
            clothes_dict[k] += 1
            
        else:
            clothes_dict[k] = 1
        
    for k in clothes_dict.keys():
        clothes_dict[k] += 1
    
    return math.prod(clothes_dict.values()) - 1
