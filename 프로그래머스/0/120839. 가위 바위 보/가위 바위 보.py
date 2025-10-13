def get_rsp(rsp):
    if rsp == "2":
        return "0"
    
    elif rsp == "0":
        return "5"

    elif rsp == "5":
        return "2"

def solution(rsp):
    answer = ''
    
    for c in rsp:
        answer += get_rsp(c)
    
    return answer