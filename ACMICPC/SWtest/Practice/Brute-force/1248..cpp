#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
int S[22][22];
int ans[22];

bool check(int index){

    int sum = 0;
    for(int i=index; i>=0; i--){
        sum += ans[i];
        if(S[i][index] == 0){
            if(sum != 0)return false;
        }else if(S[i][index] > 0){
            if(sum <= 0)return false;
        }else if(S[i][index] < 0){
            if(sum >= 0)return false;
        }
    }
    return true;

}

bool getNum(int index){

    if(index == N){
        return true;
    }

    if(S[index][index] == 0){
        ans[index] = 0;
        return check(index) && getNum(index+1);
    }
    for(int i=1; i<=10; i++){
        ans[index] = S[index][index] * i;
        if(check(index) && getNum(index+1)) return true;
    }
    return false;

}

int main(){

    cin >> N;
    string str_input;
    cin >> str_input;
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(str_input[cnt] == '0'){
                S[i][j] = 0;
            }else if(str_input[cnt] == '-'){
                S[i][j] = -1;
            }else if(str_input[cnt] == '+'){
                S[i][j] = 1;
            }
            cnt+=1;
        }
    }
    getNum(0);
    for(int i=0; i<N; i++)printf("%d ", ans[i]);    

    return 0;
}