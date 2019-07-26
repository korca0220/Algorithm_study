#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

int dp[1001][1001]; 

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> in(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &in[i][j]);
        }
    }
    //1way
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = in[i][j];
            dp[i][j] += max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    //2way
    dp[1][1] = in[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i+1 <= n &&dp[i+1][j] < dp[i][j] + in[i+1][j]){
                dp[i+1][j] = dp[i][j] + in[i+1][j];
            }
            if(j+1 <= m && dp[i][j+1] < dp[i][j] + in[i][j+1]){
                dp[i][j+1] = dp[i][j] + in[i][j+1];
            }
            if(i+1 <= n && j+1 <= m && dp[i+1][j+1] < dp[i][j] + in[i+1][j+1]){
                dp[i+1][j+1] = dp[i][j] + in[i+1][j+1];
            }
        }
    }
    

    printf("%d", dp[n][m]);

    return 0;
}