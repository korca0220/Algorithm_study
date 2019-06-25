#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
const long long MOD = 1000000009;
int t,n;
long long dp[MAX+1][4];

int main(){
    scanf("%d", &t);

    for(int i=1; i<=MAX; i++){
        if(i-1>= 0){
            dp[i][1] = dp[i-1][2] + dp[i-1][3];
            if(i==1)dp[i][1] = 1;
        }
        if(i-2>= 0){
            dp[i][2] = dp[i-2][1] + dp[i-2][3];
            if(i==2)dp[i][2] = 1;
        }
        if(i-3>= 0){
            dp[i][3] = dp[i-3][1] + dp[i-3][2];
            if(i==3)dp[i][3] = 1;
        }
        dp[i][1] %=MOD;
        dp[i][2] %=MOD;
        dp[i][3] %=MOD;
    }

    while(t--){
        scanf("%d", &n);
        printf("%lld\n", (dp[n][1]+dp[n][2]+dp[n][3])%MOD);
    }

    return 0;
}