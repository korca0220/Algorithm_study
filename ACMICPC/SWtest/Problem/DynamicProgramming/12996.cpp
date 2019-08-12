#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

const int MOD = 1000000007;

int N;
int in[3];
ll dp[51][51][51][51];

ll getNum(int a, int b, int c, int m){

    if(m==0){
        if(a==0 && b==0 && c==0) return 1;
        else return 0;
    }
    if(a <0 || b<0 || c<0 ) return 0;
    ll &ans = dp[a][b][c][m];
    if(ans != -1) return ans;

    ans = 0;
    for(int i=0; i<=1; i++)                         {
        for(int j=0; j<=1; j++)                     {
            for(int k=0; k<=1; k++)                 {
                if(i+j+k==0) continue               ;
                ans += getNum(a-i, b-j, c-k, m-1)   ;}}}

    ans %= MOD;
    return ans;
}

int main(){

    scanf("%d", &N);
    for(int i=0; i<3; i++)              {
        scanf("%d", &in[i])            ;}

    memset(dp, -1, sizeof(dp));
    printf("%lld", getNum(in[0], in[1], in[2], N));
    return 0;
}