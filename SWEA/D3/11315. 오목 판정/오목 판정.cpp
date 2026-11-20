// N크기의 정사각형 바두판 각 간에는 돌이 있을수도 없을수도. 가로세로대각선으로 5개 이상이면 YES 아니면 NO
// o -> 있음 . -> 없음
#define _CRT_SEQUER_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
char board[20][20]; int N;
int dr[4] = { -1, 0, -1, -1 }; int dc[4] = { 0, -1, -1, 1 }; // 상 좌 상좌 상우 4개만 있어도 됨

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'o') {
				for(int d = 0; d < 4; d++) {
					int cnt = 0;
					for (int k = 0; k < 5; k++) {
						int nr = i +dr[d] * k; int nc = j +dc[d] * k; //k칸 떨어진 곳
						if (nr < 0 || nr >= N || nc < 0 || nc >= N) break; // 끊기면 이 방향은 끝
						if (board[nr][nc] != 'o') break;
						cnt++; // 안끊기면 cnt++
					}
					if (cnt == 5) { cout << "YES"; return; }
				}
			}
		}
	}
	cout << "NO"; return;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T, tc; cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			string str; cin >> str;
			for (int j = 0; j < N; j++) {
				board[i][j] = str[j];
			}
		}
		cout << "#" << tc << " ";
		solve(); cout << '\n';
	}
	return 0;
}