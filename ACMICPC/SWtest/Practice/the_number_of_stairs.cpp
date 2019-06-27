#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;
const long long MOD = 1000000000;
int N;
long long dp[MAX+1][10];

int main(){

    scanf("%d", &N);
    for(int i=1; i<=9; i++)dp[1][i] = 1;
    for(int i=2; i<=MAX; i++){
        for(int j=0; j<=9; j++){
            if(j-1 >= 0) dp[i][j] += dp[i-1][j-1];
            if(j+1 <= 9) dp[i][j] += dp[i-1][j+1];

            dp[i][j] %=MOD;
        }
    }
    
    long long sum=0;
    for(int i=0; i<=9; i++){
        sum = (sum + dp[N][i])%MOD;
    }
    printf("%lld", sum);

    return 0;
}