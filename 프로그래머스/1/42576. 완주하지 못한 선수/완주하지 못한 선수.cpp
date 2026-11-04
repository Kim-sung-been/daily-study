#include <string>
#include <vector>
#include <unordered_map>
// 마라톤에 참가한 선수 명단: participant, 완주한 선수 명단: completion 
// 완주 못한 선수 리턴
// 참가선수 이름으로 키 생성. 값은 각 이름의 명 수
// 완주한 명단을 보면서 하나씩 --

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    for(string name : participant){
        map[name]++;
    }
    for(string name : completion){
        map[name]--;
    }
    for(string name : participant){
        if (map[name] != 0){
            answer = name;
        }
    }

    
    
    return answer;
}