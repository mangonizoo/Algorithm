#include <iostream>

using namespace std;

int alpha[26], cnt = 0;
string input;
//아스키코드 : 대문자 65~90, 소문자 97~122

int main() {
    cin >> input;
    //알파벳 빈도수 구하기
    for (int i = 0; i < input.length(); i++) {
        if (input[i] < 97) alpha[input[i] - 65]++; //대문자
        else alpha[input[i] - 97]++; //소문자
    }

    int max = -1, max_indx = 0;

    for (int i = 0; i < 26; i++) {
        if (max < alpha[i]) {
            max = alpha[i];
            max_indx = i;
        }
    }
    //최대값이 여러개인지 확인
    for (int i = 0; i < 26; i++) {
        if (max == alpha[i]) cnt++;
    }
    //최대값이 2개이상이면? 1개면 아스키코드->char로 형변환 출력
    if (cnt > 1) cout << "?";
    else cout << (char)(max_indx + 65);
}
