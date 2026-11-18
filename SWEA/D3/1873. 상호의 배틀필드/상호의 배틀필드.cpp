#include <bits/stdc++.h>
using namespace std;
int N, H, W; char board[20][20];
int dh[4] = {-1, 1, 0, 0}; int dw[4] = {0, 0, -1, 1}; // 상, 하, 좌, 우
char tank_char[4] = {'^', 'v', '<', '>'}; int tank_look; int tank_r, tank_c;

void shoot(int look){
    int r = tank_r; int c = tank_c;
    while(true){
        int nr = r + dh[look]; int nc = c + dw[look];
        if(nr < 0 || nr >= H || nc < 0 || nc >= W) return;
        if(board[nr][nc] == '#') return;
        if(board[nr][nc] == '*'){
            board[nr][nc] = '.';
            return;
        }
        r = nr; c = nc;
    }

}

void tank_move(int l){
    tank_look = l;
    board[tank_r][tank_c] = tank_char[tank_look];
    int nr = tank_r + dh[tank_look]; int nc = tank_c + dw[tank_look];
    if(nr < 0 || nr >= H || nc < 0 || nc >= W) return;
    if(board[nr][nc] != '.') return;
    board[tank_r][tank_c] = '.';
    tank_r = nr; tank_c = nc;
    board[tank_r][tank_c] = tank_char[tank_look];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        cin >> H >> W;
        for(int i=0; i< H; i++){
            string str; cin >> str;
            for(int j=0; j<W; j++){
                board[i][j] = str[j]; //맵 완성
            }
        }
        cin >> N; //명령 개수
        string order; cin >> order; // 명령 배열
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(board[i][j] == '^'){
                    tank_r = i; tank_c = j; tank_look = 0;
                }else if(board[i][j] == 'v'){
                    tank_r = i; tank_c = j; tank_look = 1;
                }else if(board[i][j] == '<'){
                    tank_r = i; tank_c = j; tank_look = 2;
                }else if(board[i][j] == '>'){
                    tank_r = i; tank_c = j; tank_look = 3;
                }
            }
        }
        for(int i=0; i<N; i++){
            if(order[i] == 'U') tank_move(0);
            else if(order[i] == 'D') tank_move(1);
            else if(order[i] == 'L') tank_move(2);
            else if(order[i] == 'R') tank_move(3);
            else if(order[i] == 'S') shoot(tank_look);
        }
        cout << "#" << tc << " ";
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}