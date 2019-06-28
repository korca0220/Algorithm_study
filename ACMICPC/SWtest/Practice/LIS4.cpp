#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N;
int input[MAX+1];
int dp[MAX+1];
int v[MAX+1];
void printDp(int n){

    if(n == 0)return ;
    printDp(v[n]);
    cout << input[n] << " ";
}

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%d", &input[i]);

    for(int i=1; i<=N; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(input[i] > input[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
                v[i] = j;
            }
        }
    }
    int max_num = 0;
    int start_index = 0;
    for(int i=1; i<=N; i++){
        if(max_num <dp[i]){
            max_num = dp[i];
            start_index = i;
        }

    }
    printDp(start_index);


    return 0;
}