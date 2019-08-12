#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

const int MOD = 1000000007;
ll dp[101][101];
int n,m,p;

ll getPlaylist(int music, int list_in){

    int y = n-list_in;
    if(music==p){
        if(y==0) return 1;
        else return 0;
    }
    ll &ans = dp[music][list_in];
    if(ans != -1) return ans;

    ans = 0;
    if(y>0){ // 아무 음악이나 넣는 수
        ans += getPlaylist(music+1, list_in+1) * y;
    }
    if(list_in > m){
        ans += getPlaylist(music+1, list_in) * (list_in-m);
    }
    ans %= MOD;
    return ans;
}

int main(){

    scanf("%d %d %d", &n, &m, &p);

    memset(dp,-1, sizeof(dp));
    printf("%lld", getPlaylist(0,0));

    return 0;
}