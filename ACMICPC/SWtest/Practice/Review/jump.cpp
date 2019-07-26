#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[101][101];

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> in(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &in[i][j]);
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(in[i][j] == 0)continue;
            if(j + in[i][j] < n){
                dp[i][j+in[i][j]] += dp[i][j];
            }
            if(i + in[i][j] < n){
                dp[i+in[i][j]][j] += dp[i][j];
            }
        }
    }
    printf("%lld", dp[n-1][n-1]);


    return 0;

}