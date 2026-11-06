#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_set <string> set;
    for(string a : phone_book){
        set.insert(a);
    }
    for(const auto& elem : set){
        string temp;
        for(int i=0; i<elem.size()-1; i++){
            temp += elem[i];
            if (set.contains(temp)) {
                answer = false;
            }
        }
    }
    
    return answer;
}