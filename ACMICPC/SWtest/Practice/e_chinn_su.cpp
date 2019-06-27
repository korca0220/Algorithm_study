#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 90;
int N;
long long dp[MAX+1][2];


int main(){
    scanf("%d", &N);
    
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 0;
    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    long long sum = dp[N][0] + dp[N][1];
    printf("%lld", sum);
    return 0;
}
