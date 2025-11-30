import sys

n = int(sys.stdin.readline().rstrip())
n_list = set(map(int, sys.stdin.readline().rstrip().split(" ")))
m = int(sys.stdin.readline().rstrip())
m_list = list(map(int, sys.stdin.readline().rstrip().split(" ")))

##### 시간 초과 #####
# for word in m_list:
#     print(1 if word in n_list else 0)

for m in m_list: # m_list 순회
    print(1 if m in n_list else 0) # Set에서 in 은 O(1)이므로 Set 사용