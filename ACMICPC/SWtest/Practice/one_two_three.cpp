#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
const long long MOD = 1000000009;
int t, n;
long long dp[MAX+1];

int main(){
    scanf("%d", &t);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    // 미리 구해놓기
    for(int i=4; i<=MAX; i++){
        // dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000009;
        if(i-1 >= 0) dp[i] += dp[i-1];
        if(i-2 >= 0) dp[i] += dp[i-2];
        if(i-3 >= 0) dp[i] += dp[i-3];

        dp[i] %= MOD;
    }
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}