#include <string>
#include <vector>
#include <iostream>

using namespace std;

//숫자들, 정답횟수(레퍼런스로 보내기ㅡㅡ), 찾아야 하는 숫자, 들어간 깊이, 현재까지 합
int sooong(vector<int> numbers, int& answer, int target, int cnt, int sum){
    //마지막까지 순회했다면
    if (cnt == numbers.size()) {
        if (target == sum) answer++;
        return 0;
    }
    //끝까지 돌때까지
    sooong(numbers, answer, target, cnt+1, sum + numbers[cnt]);
    sooong(numbers, answer, target, cnt+1, sum - numbers[cnt]);
    
    return 0;//필수필수
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    sooong(numbers, answer, target,0,0);//cnt랑sum은 0으로 보내
    return answer;
}
