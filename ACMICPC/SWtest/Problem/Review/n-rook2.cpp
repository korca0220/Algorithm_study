#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

const int MOD = 1000001;
ll dp[101][101][101];
int n,m,k;

ll getNum(int n, int m, int k){

    if(k==0) return 1;
    if(n<=0 || m<=0 || k<0) return 0;

    ll &ans = dp[n][m][k];
    if(ans != -1) return ans;

    ans = getNum(n-1, m, k)
    + getNum(n-1, m-1, k-1) * m
    + getNum(n-1, m-2, k-2) * m*(m-1)/2
    + getNum(n-2, m-1, k-2) * m*(n-1);

    ans %= MOD;
    return ans;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    memset(dp, -1 ,sizeof(dp));
    cout << getNum(n,m,k);
    return 0;
}