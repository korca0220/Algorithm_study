#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long dp[101][21];

int main(){

    int n;
    scanf("%d", &n);

    vector<int> v(n+1);
    for(int i=1; i<=n; i++)scanf(" %d", &v[i]);

    dp[1][v[1]] = 1;
    for(int i=2; i<n; i++){
        for(int j=0; j<=20; j++){
            if(j-v[i] >= 0) dp[i][j] += dp[i-1][j-v[i]];
            if(j+v[i] <= 20) dp[i][j] += dp[i-1][j+v[i]];
        }
    }
    printf("%lld", dp[n-1][v[n]]);


    return 0;
}