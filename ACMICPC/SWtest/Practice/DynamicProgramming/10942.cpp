#include <iostream>
#include <vector>
using namespace std;

int N, M;
long in[2001];
bool dp[2001][2001];

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &in[i]);
        dp[i][i] = true;
    }
    scanf("%d", &M);
    for(int i=1; i<=N-1; i++){
        if(in[i] == in[i+1])dp[i][i+1] = true;
    }
    for(int i=3; i<=N; i++){
        for(int j=1; j<=N-i+1; j++){
            int k = i+j-1;
            if(in[j] == in[k] && dp[j+1][k-1]){
                dp[j][k] = true;
            }
        }
    }


    int S,E;
    while(M--){
        scanf("%d %d", &S, &E);
        printf(dp[S][E] ? "1\n" : "0\n");
    }

    return 0;
}