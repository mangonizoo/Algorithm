def solution(numbers,hand):
    leftdistance={1:[0,0],4:[1,0],7:[2,0]}
    rightdistance={3:[0,2],6:[1,2],9:[2,2]}
    middledistance={2:[0,1],5:[1,1],8:[2,1],0:[3,1]}
    Lflag=[3,0]
    Rflag=[3,2]
    answer=''
    for n in numbers:
        if n in leftdistance.keys():
            Lflag=leftdistance[n]
            answer+='L'
        elif n in rightdistance.keys():
            Rflag=rightdistance[n]
            answer+='R'
        elif n in middledistance.keys():
            LD=abs(Lflag[0]-middledistance[n][0])+abs(Lflag[1]-middledistance[n][1])
            RD=abs(Rflag[0]-middledistance[n][0])+abs(Rflag[1]-middledistance[n][1])
            if LD < RD:
                Lflag=middledistance[n]
                answer+='L'
            elif LD == RD:
                if hand == 'right':
                    Rflag=middledistance[n]
                    answer+='R'
                else:
                    Lflag=middledistance[n]
                    answer+='L'
            else:
                Rflag=middledistance[n]
                answer+='R'
    return answer
