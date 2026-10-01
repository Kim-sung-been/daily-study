#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct = 0;
    int zero = 0;
    int v = 0;
    int z = 0;
    
    for(int i=0; i< win_nums.size(); i++){
        for(int k=0; k< lottos.size(); k++){
            if(win_nums[i] == lottos[k]){
                correct++;
            }
        }
        if(lottos[i] == 0){
            zero++;
        }
    }
    switch(correct + zero){
        case 6:
            v=1;
            break;
        case 5:
            v=2;
            break;
        case 4:
            v=3;
            break;
        case 3:
            v=4;
            break;
        case 2:
            v=5;
            break;
        default:
            v=6;
    }
    
    switch(correct){
        case 6:
            z=1;
            break;
        case 5:
            z=2;
            break;
        case 4:
            z=3;
            break;
        case 3:
            z=4;
            break;
        case 2:
            z=5;
            break;
        default:
            z=6;
    }
    
    answer.push_back(v);
    answer.push_back(z);
    return answer;
}