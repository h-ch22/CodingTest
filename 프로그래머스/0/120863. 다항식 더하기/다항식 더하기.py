def solution(polynomial):
    answer = ''
    units = polynomial.split()
    x = 0
    constant = 0
    
    for u in units:
        if 'x' in u:
            if u == 'x':
                x += 1
                
            else:
                x += int(u[:u.index('x')])
                
        elif u != '+':
            constant += int(u)
            
    exp = f'{x}x' if x > 1 else 'x'
    
    if x == 0:
        exp = ''
        
    if constant > 0 and x > 0:
        exp += ' + '
    
    return exp if constant == 0 else f'{exp}{constant}'