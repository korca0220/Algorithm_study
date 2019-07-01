#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

const int MAX = 10000;
int N;
int dp[MAX+1][3];
int input[MAX+1];

int main(){
    scanf("%d", &N);
    
    for(int i=1; i<=N; i++)scanf("%d", &input[i]);

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i=1; i<=N; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = dp[i-1][0] + input[i];
        dp[i][2] = dp[i-1][1] + input[i];
    }

    printf("%d", max({dp[N][0], dp[N][1], dp[N][2]}));

    return 0;
}