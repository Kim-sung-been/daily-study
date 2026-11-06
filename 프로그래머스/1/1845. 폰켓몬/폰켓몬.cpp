#include <vector>
#include <unordered_set>
using namespace std;
// N마리의 포켓몬중 N/2만큼 가져감. 같은 포켓몬은 같은 번호를 부여받음
// 중복 포켓몬이 최대한 적게 가져가기. N마리의 포켓몬의 도감번호 nums배열. 최대한 많은 종류의 포켓몬을 가져가는 경우의 포켓몬 종류 수 return
// 반복문을 통해 도감번호로 해쉬셋 생성. N/2 와 포켓몬 종류 수 중 더 작은값이 답
int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> set;
    for(int n : nums){
        set.insert(n);
    }
    if(set.size() > nums.size()/2){
        answer = nums.size()/2;
    }else answer = set.size();
    
    return answer;
}