#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

const int MAX = 100000;
int t_input, N;  
long long dp[MAX+1][3];
int input[2][MAX+1];

int main(){
    scanf("%d", &t_input);
    
    while(t_input--){
        scanf("%d", &N);
        for(int i=0; i<2; i++){
            for(int j=1; j<=N; j++){
                scanf("%d", &input[i][j]);
            }
        }
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i=1; i<=N; i++){
            dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + input[0][i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + input[1][i];
        }
        printf("%lld\n", max({dp[N][0], dp[N][1], dp[N][2]}));
    }
    

    return 0;
}