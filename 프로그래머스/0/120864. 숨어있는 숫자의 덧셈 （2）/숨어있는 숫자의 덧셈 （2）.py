def solution(my_string):
    nums = []
    current_num = ''
    
    for i in range(len(my_string)):
        s = my_string[i]

        if s.isnumeric():
            current_num += s
            
            if i == len(my_string) - 1:
                nums.append(current_num)
                
        elif current_num != '':
            nums.append(current_num)
            current_num = ''

    return sum([int(n) for n in nums])