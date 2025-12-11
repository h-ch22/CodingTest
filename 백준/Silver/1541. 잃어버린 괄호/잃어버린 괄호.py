import sys

exp = sys.stdin.readline().strip()
exp_split = exp.split('-')

for i in range(len(exp_split)):
    if '+' in exp_split[i]:
        nums = list(map(int, exp_split[i].split('+')))
        sum = 0
        
        for n in nums:
            sum += n
            
        exp_split[i] = sum
        
    else:
        exp_split[i] = int(exp_split[i])
        
result = exp_split[0]

for i in range(1, len(exp_split)):
    result -= exp_split[i]
    
print(result)
