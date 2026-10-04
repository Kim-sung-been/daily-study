#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> temp;
    for (int i=0; i<ingredient.size(); i++){
        temp.push_back(ingredient[i]);
        if(temp.size() >= 4){
            if(temp[temp.size() - 4]==1){
                if(temp[temp.size() - 3]==2){
                    if(temp[temp.size() - 2]==3){
                        if(temp[temp.size() - 1]==1){
                            answer++;
                            temp.pop_back();
                            temp.pop_back();
                            temp.pop_back();
                            temp.pop_back();
                        }
                    }
                }    
            }

        }
    }
    return answer;
}