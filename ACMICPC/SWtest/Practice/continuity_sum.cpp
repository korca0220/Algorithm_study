#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N;
int input[MAX+1];
long dp[MAX+1];

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%d", &input[i]);

    dp[0] = 0;
    for(int i=1; i<=N; i++){
        dp[i] = input[i];
        if(dp[i-1]+input[i] > input[i])
            dp[i] = dp[i-1]+input[i];
    }
    long max_num = -987654321;
    for(int i=1; i<=N; i++){
        max_num = max(max_num, dp[i]);
    }
    printf("%ld", max_num);

    return 0;
}
