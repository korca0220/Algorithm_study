#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> w(n+1);
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    printf("%d", dp[n][k]);


    return 0;
}