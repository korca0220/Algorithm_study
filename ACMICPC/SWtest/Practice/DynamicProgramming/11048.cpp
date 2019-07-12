#include <iostream>
#include <algorithm>
#include <vector>
#include <initializer_list>
using namespace std;
int N,M;
int dp[1001][1001];
int main(){

    scanf("%d %d", &N, &M);
    vector<vector<int>> in(N+1, vector<int>(M+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &in[i][j]);
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = in[i][j];
            dp[i][j] += max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    printf("%d", dp[N][M]);

    return 0;

}