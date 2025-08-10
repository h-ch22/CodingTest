import heapq
import sys

heap = []

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    command = int(sys.stdin.readline().rstrip())

    if command == 0:
        if len(heap) == 0:
            print('0')

        else:
            print(heapq.heappop(heap) * -1)

    else:
        heapq.heappush(heap, -command) # Python의 heapq에서는 최대 힙을 제공하지 않기 때문에 부호 변경하는 방식으로 최대 힙 구현
