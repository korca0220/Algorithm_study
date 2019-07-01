#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000001];
int main(){

    scanf("%d", &N);

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    if(N <=3)printf("%d\n", dp[N]);
    else{
        for(int i=4; i<=N; i++){
            dp[i] = dp[i-1] + 1;
            if(i%3 ==0)dp[i] = min(dp[i], dp[i/3]+1);
            if(i%2 ==0)dp[i] = min(dp[i], dp[i/2]+1);
        }
        printf("%d\n", dp[N]);
    }

    return 0;
}