// N명의 사람이 자격을 얻음. 0초부터 M초마다 K개의 붕어빵 만들기 가능.
// 0초 이후에 손님들이 언제 오는지 주어지면 다 기다리는 시간 없이 제공 가능한지 판별. 
// (t/M)*K -> t초에 나온 붕어빵 수
#include <bits/stdc++.h>
using namespace std;
int N, M, K, board[100];

string solve(){
    string answer = "Possible";
    // board[i] -> 사람수: i+1, 시간: board[i] | (board[i]/M)*K 가 i+1보다 적으면 return
    for(int i=0; i<N; i++){
        if((board[i]/M)*K < i+1){
            answer = "Impossible";
        }
    } 

    return answer;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        cin >> N >> M >> K;
        for(int i=0; i<N; i++){
            cin >> board[i]; // 도착시간 입력
        }
        sort(board, board+N); // 오름차순 정렬

        cout << "#" << tc << " " << solve() << '\n';
    }

    return 0;
}