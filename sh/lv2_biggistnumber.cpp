#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool bigger(string a, string b){
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    vector<string> n;//스트링형 배열 선언
    string answer = "";
    //[6,2,10]=>["6","2","10"] 변환
    for(int i=0;i<numbers.size();i++){
        n.push_back(to_string(numbers[i]));
    }
    //커스텀 정렬하기 ! sort(v.begin(), v.end(), 사용자 정의함수); 
    sort(n.begin(),n.end(),bigger);
   if(n.at(0)=="0")return "0";
    for(int j=0;j<n.size();j++){
        answer+=n[j];
    }
    
    return answer;
}
