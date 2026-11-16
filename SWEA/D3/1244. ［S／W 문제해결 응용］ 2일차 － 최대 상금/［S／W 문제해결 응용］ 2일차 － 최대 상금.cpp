// 주어진 숫자판중 두 개를 선택해 정해진 횟수만큼 위치 교환. 숫자판 위치의 가중치에 의해 상금 계산.
// 오른쪽 끝이 1 왼쪽으로 갈수록 *10. 반드시 교환은 이루어 져야 하며 같은 위치의 교환도 허용. 가장 큰 금액을 받는 법
// set<string> seen[11]로 나온 배열을 저장하고 한 번 나온건 가지치기. N: 교환 횟수 | nums: 입력받은 배열
#include <bits/stdc++.h>
using namespace std;
int N;
set<string> seen[11]; // 0번 교환부터  10번 교환까지 11개
string nums, best = "";

void solve(int idx){
    if(seen[idx].count(nums)) return;
    seen[idx].insert(nums);
    if(idx == N){ // 교환 횟수 체우면
        best = max(best, nums);
        return;
    }
    
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            solve(idx + 1);
            swap(nums[i], nums[j]);
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        cin >> nums; cin >> N;

        cout << "#" << tc << " ";
        best = "";
        for(int i=0; i<10; i++){
            seen[i].clear();
        }
        solve(0);
        cout << best << '\n';
    }

    return 0;
}