#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int cnt = 0;

void subCount(vector<int> &num, int index, int sum){

    if(index == N){
        if(sum == S){
            cnt++;            
        }
        return ;
    }
    subCount(num, index+1, sum+num[index]);
    subCount(num, index+1, sum);

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> num;
    cin >> N >> S;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp; num.push_back(temp);
    }
    subCount(num, 0, 0);
    if(S==0)cnt-=1;
    cout << cnt;

    return 0;
}