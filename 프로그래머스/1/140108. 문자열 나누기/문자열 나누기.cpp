#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 0;
    int diff = 0;
    char x = s[0];
    
    for(int i = 0; i < s.size(); i++){
        if(same == 0 && diff == 0){
            x = s[i];
        }
        if(x == s[i]){
            same++;
        }else{
            diff++;
        }
        
        if(same == diff){
            answer++;
            same = 0;
            diff = 0;
        }
        
    }
    if(same != diff){
        answer++;
    }
    
    return answer;
}