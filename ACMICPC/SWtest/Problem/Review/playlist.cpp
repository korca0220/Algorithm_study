#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

const int MOD = 1000000007;
ll dp[101][101];
int n,m,p;
ll getMax(int music, int in){

    int y = n - in; // 남은 음악
    if(music==p){
        if(y==0) return 1;
        else return 0;
    }
    ll &ans = dp[music][in];
    if(ans != -1) return ans;

    ans = 0;
    if(y>0){
        ans += getMax(music+1, in+1) * y;
    }
    if(in > m){
        ans += getMax(music+1, in) * (in-m);
    }
    ans %= MOD;
    return ans;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    memset(dp, -1 ,sizeof(dp));
    cout << getMax(0, 0);


    return 0;
}