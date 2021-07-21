def solution(board, moves):
    answer = 0
    bucket=[]
    for m in moves:
        m-=1
        for i in range(len(board[m])):
            if board[i][m] != 0:
                bucket.append(board[i][m])
                if len(bucket)>1:
                    if bucket[len(bucket)-2] == bucket[len(bucket)-1]:
                        bucket.pop()
                        bucket.pop()
                        answer+=2
                board[i][m]=0
                break
    return answer
