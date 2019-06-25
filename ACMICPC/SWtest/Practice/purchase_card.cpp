#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10000;
int N;
int P[1001];
int dp[1001];   

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &P[i]);
    }
    memset(dp, MAX, sizeof(dp));
    dp[0] = 0;
    dp[1] = P[1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i] = min(dp[i], dp[i-j]+P[j]);
        }
    }
    printf("%d", dp[N]);

    return 0;
}