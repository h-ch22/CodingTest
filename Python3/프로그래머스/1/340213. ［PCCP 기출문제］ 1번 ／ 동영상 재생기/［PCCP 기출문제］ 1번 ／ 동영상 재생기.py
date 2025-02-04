def process_pos(m, s, len_m, len_s, op_s_m, op_s_s, op_e_m, op_e_s):
    m, s = skip_op(m, s, op_s_m, op_s_s, op_e_m, op_e_s)

    if s > 59:
        s -= 60
        m += 1
        
    if s < 0:
        s += 60
        m -= 1
        
    if m >= len_m and s >= len_s:
        m, s = len_m, len_s
        
    if m < 0:
        m, s = 0, 0
    
    m, s = skip_op(m, s, op_s_m, op_s_s, op_e_m, op_e_s)

    return m, s

def convert_time(time):
    m, s = time.split(":")
    
    return int(m), int(s)

def skip_op(m, s, op_s_m, op_s_s, op_e_m, op_e_s):
    if m > op_s_m and m < op_e_m:
        m, s = op_e_m, op_e_s
        
    elif op_s_m != op_e_m and m == op_s_m and s >= op_s_s:
        m, s = op_e_m, op_e_s
        
    elif op_s_m != op_e_m and m == op_e_m and s < op_e_s:
        m, s = op_e_m, op_e_s

    elif (op_s_m == op_e_m and m == op_s_m) and (s >= op_s_s and s < op_e_s):
        m, s = op_e_m, op_e_s
        
    return m, s

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    
    m, s = convert_time(pos)
    len_m, len_s = convert_time(video_len)
    op_s_m, op_s_s = convert_time(op_start)
    op_e_m, op_e_s = convert_time(op_end)
    
    for command in commands:  
        m, s = skip_op(m, s, op_s_m, op_s_s, op_e_m, op_e_s)

        if command == 'next':
            s += 10
            m, s = process_pos(m, s, len_m, len_s, op_s_m, op_s_s, op_e_m, op_e_s)

        elif command == 'prev':
            s -= 10
            m, s = process_pos(m, s, len_m, len_s, op_s_m, op_s_s, op_e_m, op_e_s)
                                    
    answer = f"{str(m).zfill(2)}:{str(s).zfill(2)}"
    
    return answer