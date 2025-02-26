from collections import defaultdict


def list_duplicates(seq, item):
    start_index = -1
    locs = []

    while True:
        try:
            loc = seq.index(item, start_index + 1)

        except ValueError:
            break

        else:
            locs.append(loc)
            start_index = loc

    return locs


N = int(input())
data = list(map(int, input().split()))
data_sorted = sorted(data)

seen = []

for d in data:
    index = data_sorted.index(d)
    if index not in seen:
        print(index, end=" ")
        seen.append(index)

    else:
        indexes = list_duplicates(data_sorted, data_sorted[index])

        for i in indexes:
            if i not in seen:
                print(i, end=" ")

                seen.append(i)
                break
