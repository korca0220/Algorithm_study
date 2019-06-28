#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N;
long long input[MAX+1];
long long dp[MAX+1];

int main(){

    scanf("%d", &N);
    
    for(int i=1; i<=N; i++){
        dp[i] = i;
        for(int j=1; j*j<=i; j++){
            if(dp[i] > dp[i-j*j]+1){
                dp[i] = dp[i-j*j]+1;
            }
        }
    }
    printf("%lld", dp[N]);

    return 0;
}