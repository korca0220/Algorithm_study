#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool dp[101][1001];


int main(){

    int n,s,m;
    scanf("%d %d %d", &n, &s, &m);
    vector<int> v(n+1);

    for(int i=1; i<=n; i++)scanf("%d", &v[i]);
    
    dp[0][s] = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(dp[i-1][j]){
                if(j-v[i] >=0){
                    dp[i][j-v[i]] = true;
                }
                if(j+v[i] <= m){
                    dp[i][j+v[i]] = true;
                }
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=m; i++){
        if(dp[n][i]) ans = i;
    }
    printf("%d", ans);

    return 0;
}