#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int N;
int dp[MAX];

int main(){

    scanf("%d", &N);
    
    dp[0] = 0;
    for(int i=1; i<=N; i++){
        dp[i] = i;
        for(int j=1; j*j<=i; j++){
            if(dp[i] > dp[i-j*j]+1)
                dp[i] = dp[i-j*j] + 1;
        }
    }
    printf("%d", dp[N]);


    return 0;
}