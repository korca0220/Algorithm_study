#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

const int MAX = 100000;
int N;
long long input[MAX+1];
long long dp[2][MAX+1];

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%ld", &input[i]);

    long long r_max=-987654321;
    for(int i=1; i<=N; i++){
        dp[0][i] = max(dp[0][i-1]+input[i], input[i]);
        dp[1][i] = max({dp[1][i-1]+input[i], dp[0][i-2]+input[i], input[i]});
        r_max = max({r_max, dp[0][i], dp[1][i]});
    }
    printf("%ld", r_max);

    return 0;
}