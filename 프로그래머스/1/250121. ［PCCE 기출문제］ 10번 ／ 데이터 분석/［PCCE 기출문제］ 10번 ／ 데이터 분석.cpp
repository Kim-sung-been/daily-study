#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int e;
    int s;
    vector<vector<int>> temp;
    if(ext=="code")e=0;
    else if(ext=="date")e=1;
    else if(ext=="maximum")e=2;
    else e=3;
    for(int i=0; i<data.size(); i++){
        if(data[i][e]<val_ext){
            temp.push_back(data[i]);
        }
    }
    if(sort_by=="code")s=0;
    else if(sort_by=="date")s=1;
    else if(sort_by=="maximum")s=2;
    else s=3;
    sort(temp.begin(), temp.end(), [s](vector<int> a, vector<int> b){
        return a[s] < b[s];
    });
    answer=temp;
    
    return answer;
}