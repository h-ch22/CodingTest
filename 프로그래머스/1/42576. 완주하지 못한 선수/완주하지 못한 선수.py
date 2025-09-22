def solution(participant, completion):
    participants = {}

    for p in participant:
        if p in participants.keys():
            participants[p] += 1
            
        else:
            participants[p] = 1
            
    for c in completion:
        participants[c] -= 1
        
        if participants[c] == 0:
            del participants[c]
        
    return list(participants.keys())[0]
    