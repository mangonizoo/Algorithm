#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++){
        //임시 벡터 생성
        vector<int> copy;
        //주어진 인덱스 부분을 copy백터에 넣음
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            copy.push_back(array[j]);
        //정렬
        sort(copy.begin(), copy.end());
        //copy백터의 인덱스를 answer에 넣음
        answer.push_back(copy.at(commands[i][2] - 1));
    }
    return answer;
}
