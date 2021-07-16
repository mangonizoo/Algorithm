def solution(s):
    word={'one':1,'two':2,'three':3,'four':4,'five':5,'six':6,'seven':7,'eight':8,'nine':9,'zero':0}
    for num in word.keys():
        if num in s:
            s=s.replace(str(num),str(word[num]))
    answer=int(s)
    return answer
