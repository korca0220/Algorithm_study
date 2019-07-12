#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[2001][2001];
int in[2001];

int getDp(int s, int e){

    
    if(s==e)return 1;
    else if(s+1 == e){
        if(in[s] == in[e]) return 1;
        else return 0;
    }
    if(dp[s][e] >= 0) return dp[s][e]; // memoization, 이미한거 스킵
    if(in[s] != in[e]) return dp[s][e] = 0;
    else return dp[s][e] = getDp(s+1, e-1); 

}

int main(){

    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf(" %d", &in[i]);
    
    int M;
    scanf("%d", &M);
    memset(dp, -1, sizeof(dp));
    while(M--){
        int s,e;
        scanf("%d %d", &s, &e);
        printf("%d\n", getDp(s,e));
    }


    return 0;
}