def solution(score):
    answer = []
    avg_scores = list(sum(s) / len(s) for s in score)
    sorted_scores = sorted(avg_scores, reverse=True)
    
    rank = [sorted_scores.index(s) + 1 for s in avg_scores]

    return rank