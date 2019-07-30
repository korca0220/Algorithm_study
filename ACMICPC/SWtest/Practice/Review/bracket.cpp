#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX = 5000;
long long dp[MAX+1];

int main(){
    int T;
    scanf("%d", &T);

    dp[0] = 1;
    for(int i=1; i<=MAX; i++){
        for(int j=0; j<=i; j++){
            dp[i] += (dp[j-2] * dp[i-j])%MOD;
        }
        dp[i] %= MOD;
    }

    while(T--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }


    return 0;
}