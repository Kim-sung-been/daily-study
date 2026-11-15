// 햄버거 재료에 대한 점수, 재료에 대한 칼로리. 정해진 칼로리 이하에서 가장 선호하는 조합 고르기
// 햄버거의 선호도는 조합된 재료들의 맛에 대한 점수의 합, 같은 재료 사용 불가, 햄버거의 조합의 제한은 오직 칼로리.
#include <bits/stdc++.h>
using namespace std;
int N, L, best;
int kcal[20], score[20];

void dfs(int idx, int sc, int kc){
    if(kc > L) return;
    best = max(best, sc);
    if(idx == N) return;
    dfs(idx + 1, sc + score[idx], kc + kcal[idx]);
    dfs(idx + 1, sc, kc);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        best = 0;
        cin >> N >> L;
        for(int i=0; i<N; i++){
            cin >> score[i] >> kcal[i];
        }
        cout << "#" << tc << " ";
        dfs(0, 0, 0);
        cout << best << '\n';
    }

    return 0;
}