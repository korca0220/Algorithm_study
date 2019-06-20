#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000000;
int N,K;
long long dp[201][201];

int main(){

    scanf("%d %d", &N, &K);

    dp[0][0] = 1LL;
    for(int i = 1; i<=K; i++){
        for(int j = 0; j<=N; j++){
            for(int k = 0; k<=j; k++){
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= MOD;
            }
        }
    }
    printf("%lld", dp[K][N]);

    return 0;
}