def solution(myString, pat):
    replacedString = ["A" if m == "B" else "B" for m in myString]
    replacedString = "".join(replacedString)
    
    return 1 if pat in replacedString else 0
    