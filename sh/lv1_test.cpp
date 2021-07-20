#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[3]={0,};
    int max_cnt=0;
    //패턴3개
    int supo1[5]={1,2,3,4,5};
    int supo2[8]={2,1,2,3,2,4,2,5};
    int supo3[10]={3,3,1,1,2,2,4,4,5,5};

    //답 검사
    for(int i=0;i<answers.size();i++){
        if(answers[i]==supo1[i%5]){
            cnt[0]++;
        }
        if(answers[i]==supo2[i%8]){
            cnt[1]++;
        }
        if(answers[i]==supo3[i%10]){
            cnt[2]++;
        }
    }
    max_cnt = max(max(cnt[0], cnt[1]), cnt[2]);
    for(int i=0;i<3;i++){
        if(max_cnt==cnt[i]){
            answer.push_back(i+1);
        }
    }
    return answer;
}
