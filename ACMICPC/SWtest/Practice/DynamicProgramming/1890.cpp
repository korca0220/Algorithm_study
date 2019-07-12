#include <iostream>
#include <vector>
using namespace std;

int N;
long dp[101][101];

int main(){
    scanf("%d", &N);
    vector<vector<int>> in(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &in[i][j]);
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(in[i][j] == 0)continue; // skip to zero
            if(j+in[i][j] < N){
                dp[i][j+in[i][j]] += dp[i][j];
            }
            if(i+in[i][j] < N){
                dp[i+in[i][j]][j] += dp[i][j];
            }
        }
    }
    printf("%ld", dp[N-1][N-1]);


    return 0;
}