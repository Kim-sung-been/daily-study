// 격자판으로 이루어진 맵에 전차가 움직임| .: 평지, *: 벽돌벽, #: 강철벽, -: 물(전차는 못들어감), >: 각 방향을 바라보는 전차(아래는평지)
// U:바라보는 방향을 위로. 위칸이 평지면 이동, D: L: R: S: 바라보는 방향으로 포탄 발사
// 전차, 포탄은 맵 밖으로는 나갈 수 없다 | 포탄은 직진. 벽에 부딪히면 벽돌이면 같이 없어지고 강철이면 포탄만 없어짐
// 전차의 방향, 위치, 맵의 상태.
#include <bits/stdc++.h>
using namespace std;
int N; char board[20][20]; string cmd;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int tank_state = 0; int tx=0, ty=0; int H, W; char tank_char[4] = {'^', 'v', '<', '>'};

void shoot(){ // 전차가 바라보는 방향으로 전진. if맵끝 if 벽을 만나면 정지 if벽돌벽이면 평지로.
    int nx = tx, ny = ty;
    while(true){
        nx += dx[tank_state]; ny += dy[tank_state];
        if(nx < 0 || nx >= W || ny < 0 || ny >= H){
            break;
        }else if(board[ny][nx] == '*'){
            board[ny][nx] = '.'; break;
        }else if(board[ny][nx] == '#') break;
    }
}

void move(){ // 1.방향 바꾸기(맵 최신화) 2.맵 범위 안에서 평지라면 3.한 칸 이동 4.맵 최신화
    board[ty][tx] = tank_char[tank_state];
    int nx = tx + dx[tank_state]; int ny = ty + dy[tank_state];
    if(nx >= 0 && nx < W && ny >= 0 && ny < H && board[ny][nx] == '.'){
        board[ty][tx] = '.';
        tx = nx; ty = ny;
        board[ty][tx] = tank_char[tank_state];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        cin >> H >> W;
        for(int i=0; i<H; i++){
            string str; cin >> str;
            for(int j=0; j<W; j++){
                board[i][j] = str[j];
            }
        }
        cin >> N;
        cin >> cmd;
        for(int i=0; i<N; i++){// 1. 맵을 읽고 전차의 위치, 방향 저장
            for(int j=0; j<H; j++){
                for(int k=0; k<W; k++){
                    if(board[j][k] == '^'){ // 상
                        tx = k; ty = j; tank_state = 0;
                    } else if(board[j][k] == 'v'){ // 하
                        tx = k; ty = j; tank_state = 1;
                    } else if(board[j][k] == '<'){ // 좌
                        tx = k; ty = j; tank_state = 2;
                    } else if(board[j][k] == '>'){ // 우
                        tx = k; ty = j; tank_state = 3;
                    }
                }
            }
        }
        for(int i=0; i<N; i++){
            if(cmd[i] == 'S'){
                shoot();
            }else if(cmd[i] == 'U'){
                tank_state = 0;
                move();
            }else if(cmd[i] == 'D'){
                tank_state = 1;
                move();
            }else if(cmd[i] == 'L'){
                tank_state = 2;
                move();
            }else if(cmd[i] == 'R'){
                tank_state = 3;
                move();
            }
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