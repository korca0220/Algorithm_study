#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

const int MOD = 1000001;
ll dp[101][101][101];
int n,m,k;

ll getDp(int n, int m, int k){

    if(k==0) return 1;
    if(n<=0 || m<=0 || k<0) return 0;
    if(dp[n][m][k] != -1) return dp[n][m][k];

    dp[n][m][k] = getDp(n-1, m, k) 
    + getDp(n-1,m-1,k-1) * m
    + getDp(n-1,m-2,k-2) * m*(m-1)/2
    + getDp(n-2,m-1,k-2) * m*(n-1);

    dp[n][m][k] %= MOD;
    return dp[n][m][k];

}

int main(){

    scanf("%d %d %d", &n, &m, &k);

    memset(dp, -1, sizeof(dp));
    printf("%lld", getDp(n,m,k));

    return 0;
}