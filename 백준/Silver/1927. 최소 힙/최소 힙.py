import sys
import heapq

n = int(sys.stdin.readline().rstrip())
heap = []

for _ in range(n):
    command = int(sys.stdin.readline().rstrip())

    if command == 0:
        if len(heap) == 0:
            print('0')

        else:
            print(heapq.heappop(heap))

    else:
        heapq.heappush(heap, command)
