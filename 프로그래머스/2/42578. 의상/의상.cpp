#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int num = 0;
    unordered_map <string, int> map;
    for (const auto& cloth : clothes){
        string category = cloth[1];
        map[category]++;
    }
    for (auto a : map){
        int temp = a.second;
        if (answer == 0){
            answer += (temp + 1);
        }else answer *= (temp + 1);
    }
    answer -= 1;
    return answer;
}