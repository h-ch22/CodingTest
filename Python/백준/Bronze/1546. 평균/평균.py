if __name__ == '__main__':
    N = int(input())
    scores = input().split(" ")
    assert len(scores) == N

    scores = [int(x) for x in scores]

    max_score = max(scores)
    sum = 0

    for score in scores:
        new_score = (int(score) / int(max_score)) * 100
        sum += new_score

    print(sum / N)
