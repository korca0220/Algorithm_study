#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k;
int dp[10001];

int main(){

    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof(dp));

    int in[n];
    for(int i=0; i<n; i++)scanf("%d", &in[i]);

    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j-in[i] >= 0 && dp[j-in[i]] != -1){
                if(dp[j] == -1 || dp[j] > dp[j-in[i]]+1){
                    dp[j] = dp[j-in[i]]+1;
                }
            }
        }
    }
    printf("%d", dp[k]);

    return 0;
}