// 0~9로 이루어진 번호 문자열에서 같은 번호로 붙어있는 쌍들을 소거하고 남은 번호를 비밀번호로
// 번호 쌍이 소거되고 소거된 번호 쌍의 좌우 번호가 같은 번호이면 또 소거
#include <bits/stdc++.h>
using namespace std;
stack<char> st;
stack<char> answer;
void solve(string nums){
    for(int i=0; i<nums.size(); i++){
        char current_num;
        if(!st.empty()){
            current_num = st.top();
            if(current_num == nums[i]){
                st.pop();
            }else st.push(nums[i]);
        }else st.push(nums[i]);
    }
    while(!st.empty()){
        char temp;
        temp = st.top(); st.pop();
        answer.push(temp);
    }
    while(!answer.empty()){
        cout << answer.top();
        answer.pop();
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for(int tc = 1; tc <= 10; tc++){
        int a; cin >> a;
        string nums;
        cin >> nums;
        cout << "#" << tc << " ";
        solve(nums); cout << '\n';
    }
    return 0;
}