#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001];

int main(){
    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    printf("%d", dp[n]);

    return 0;
}