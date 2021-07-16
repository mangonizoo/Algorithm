#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n,1);//크기가 n인 벡터v생성, 1로 초기화
    for(int i=0;i<lost.size();i++){
        v[lost[i]-1]--;//lost인덱스-1 찾아서 -1
        //인덱스 시작이 0이기때문에 i-1
    }
    for(int i=0;i<reserve.size();i++){
        v[reserve[i]-1]++;//reserve인덱스-1 찾아서 +1
    }
    //v벡터 순회
    for(int i=0;i<v.size();i++){
        if(v[i]==0){//체육복 잃어버린사람이 있으면
            //앞에사람이 2개 갖고있는지 확인(i가 마지막일 경우 제외)
            if(i!=(v.size()-1)&&v[i+1]==2){
                v[i]++;//0->1
                v[i+1]--;//2->1
            }
            //전사람이 2개 갖고있는지 확인(i=0일경우는 제외)
            else if(i!=0&&v[i-1]==2){
                v[i]++;//0->1
                v[i-1]--;//2->1
            }
            
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=0)
            answer++;
    }
    return answer;
}
