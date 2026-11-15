// N개의 자연수가 주어짐, 최소 1개를 선택해서 합이 K가 되는 경우의 수를 구해라
#include <bits/stdc++.h>
using namespace std;
int N, K, cnt = 0, nums[20];

void dfs(int idx, int sum){
    if(sum > K) return;
    if(idx == N){
        if(sum == K) cnt++;
        return;
    }
    dfs(idx + 1, sum + nums[idx]);
    dfs(idx + 1, sum);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        cin >> N >> K;
        for(int i=0; i<N; i++){
            cin >> nums[i];
        }
        cout << "#" << tc << " ";
        cnt = 0;
        dfs(0, 0);
        cout << cnt << '\n';
    }

    return 0;
}