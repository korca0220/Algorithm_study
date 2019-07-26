#include <iostream>
using namespace std;

int dp[11];

int main(){

    int T;
    scanf("%d", &T);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;
    for(int i=5; i<11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }

    return 0;
}