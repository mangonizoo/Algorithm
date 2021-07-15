#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int idx=0;
    //1단계: 소문자를 대문자로 교환.
    for (int i=0; i<new_id.length(); i++)
    {
     new_id[i]=tolower(new_id[i]);
    }
    //2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    for(int i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
              || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }
    //3단계: 마침표가 2번이상 연속 -> 1개로 치환
    for(int i = 1; i < new_id.length(); ){
        if (new_id[i] == '.' && new_id[i - 1] == '.'){
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else i++;
    }
    //4단계: 처음위치,끝위치의 . 제거
    if(new_id[0]=='.'){
        new_id.erase(0,1);
    }
    if(new_id[new_id.length()-1]=='.'){
        new_id.erase(new_id.length()-1,1);
    }
    //5단계: new_id가 빈 문자열이 되었을 경우 a 대입
    if(new_id==""){
        new_id="a";
    }
    //6단계: 길이가 16이상이면 15까지 자름 제거후에 마침표가 남으면 그것도 제거
    if(new_id.length()>=16){
        new_id=new_id.substr(0,15);
        if(new_id.back()=='.'){
            new_id.erase(new_id.length()-1,1);
        }
    }
    //7단계: 길이가 2자 이하라면 마지막 문자를 길이가 3 될때까지 반복
    if(new_id.length()<=2){
        while(new_id.length()!=3){
            new_id+=new_id.back();
        }    
    }
    answer=new_id;
    return answer;    
}
