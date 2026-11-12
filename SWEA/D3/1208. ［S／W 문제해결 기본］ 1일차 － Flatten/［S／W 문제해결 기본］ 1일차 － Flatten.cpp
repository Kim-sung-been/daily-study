// 평탄화시 각 높이차는 최대 1. 횟수제한이 있을 때 작업 후 최고점 - 최저점 구하기
// 가장 높은걸 가장 낮은곳 -> 덤프. 가로길이 항상 100. 상자높이 최대 100. 덤프 1~1000. 주어진 덤프 안에 평탄화되면 그때의 차 반환
// 10개의 테스트 케이스, 각 테스트 케이스의 첫 번째 줄에는 덤프 횟수. 그리고 다음 줄에 각 상자의 높이값이 주어진다.
// 덤프 최대, 최솟값 찾기 -> 100*2 = 200. 덤프횟수(최대) -> 1000. tc -> 10 다 곱하면 200만. 1초에 1억번 계산 가능
#include <bits/stdc++.h>
using namespace std;
int N, board[100];

int solve(){
    int answer = 0;
    for(int i=0; i<N; i++){
        int *hi = max_element(board, board+100); // 최댓값의 주소 -board로 인덱스로 하면 실수 줄어듦
        int *lo = min_element(board, board+100); // 최솟값의 주소
        (*hi)--; (*lo)++;
    }
    int hvalue = *max_element(board, board+100); int lvalue = *min_element(board, board+100);
    answer = hvalue - lvalue;
    return answer;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for(int tc = 1; tc <= 10; tc++){
        cin >> N;
        for(int i=0; i<100; i++){
            cin >> board[i];
        }
        cout << "#" << tc << " " << solve() << '\n';
    }
    return 0;
}