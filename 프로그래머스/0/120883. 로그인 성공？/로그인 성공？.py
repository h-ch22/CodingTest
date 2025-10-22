def solution(id_pw, db):
    answer = ''
    ids = [i for i in range(len(db)) if db[i][0] == id_pw[0]]
    
    if len(ids) == 0:
        return 'fail'
    
    pws = [db[x][1] for x in ids]
    
    if id_pw[1] in pws:
        return 'login'
    
    else:
        return 'wrong pw'
    