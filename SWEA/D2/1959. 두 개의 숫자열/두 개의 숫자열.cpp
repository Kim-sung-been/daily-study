// N개의 숫자로 구성된 문자열 A, M개의 숫자로 구성된 문자열 B 양수 음수 0 다 가능
// A와 B를 마주보게 해서 곱함 이때 마주보는 위치 변경 가능 마주보는 위치 곱해서 더할 최대값
// A, B중 더 작은 배열의 사이즈만큼 | 큰 배열 크기 - 작은 배열 크기 + 1만큼 반복
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int  A[20], B[20];
int N, M;

int solve(int b, int s){
    int answer = -1000000000;
    if(N > M){ // A의 크기가 더 큼 -> 
        for(int i=0; i<b-s + 1; i++){
            int sum =0; 
            for(int j=0; j<s; j++){
                sum += (B[j] * A[j+i]);
            }
            answer = max(sum, answer);
        }
        return answer;
    }
    else if(N < M){ // B의 크기가 더 큼 -> 
        for(int i=0; i<b-s + 1; i++){
            int sum =0; 
            for(int j=0; j<s; j++){
                sum += (A[j] * B[j+i]);
            }
            answer = max(sum, answer);
        }
        return answer;
    }else{
        for(int i=0; i<N; i++){
            int sum =0;
            sum += (B[i] * A[i]);
            answer = sum;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, tc; cin >> T;
    for(tc = 1; tc <= T; tc++){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            cin >> A[i];
        }
        for(int i=0; i<M; i++){
            cin >> B[i];
        }
        int big; int small;
        if(N > M) {
            big = N;
            small = M;
        }else {
            big = M;
            small = N;
        }
        
        cout << "#" << tc << " ";
        cout << solve(big, small) << '\n';
    }

    return 0;
}