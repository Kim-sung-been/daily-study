// n개의 수를 처리해 8자리 암호 생성 가능
// 8개의 숫자를 입력 -> 첫번째 숫자를 1감소 후 맨뒤로. 두 번째 숫자를 2 감소 후 맨 뒤로.... 5번째까지가 1사이클 queue사용
// 숫자가 0보다 작아지는 경우 0으로 유지되며 프로그램 종료. 그때의 값을 return.
#include <bits/stdc++.h>
using namespace std;
int N; queue<int> q;

void solve(){
    int num = 0; int s = 0;
    while(true){
        num = q.front();
        num -= s%5+1; s++;
        if(num <= 0){
            num = 0; q.pop(); q.push(num);
            break;
        }
        q.pop(); q.push(num);
    }
    while (q.empty() != true)
    {
        cout << q.front() << " ";
        q.pop();
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for(int tc = 1; tc <= 10; tc++){
        int a; cin >> a;
        for(int i=0; i<8; i++){
            cin >> N;
            q.push(N);
        }
        cout << "#" << tc << " ";
        solve(); cout << '\n';
    }
    return 0;
}