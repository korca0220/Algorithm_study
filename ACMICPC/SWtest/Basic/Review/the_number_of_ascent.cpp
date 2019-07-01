#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
const int MOD = 10007;
int N;
int dp[MAX+1][10];

int main(){
    scanf("%d", &N);

    for(int i=0; i<=9; i++)dp[1][i] = 1;
    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
            }
        }
    }
    int sum = 0;
    for(int i=0; i<=9; i++){
        sum += dp[N][i];
    }
    printf("%d", sum%MOD);
    return 0;
}