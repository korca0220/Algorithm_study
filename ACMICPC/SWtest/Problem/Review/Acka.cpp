#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

const int MOD = 1000000007;
ll dp [51][51][51][51];
int cnt[4];

int getMin(int m, int a, int b, int c){

    if(m==0){
        if(a==0 && b==0 && c==0) return 1;
        else return 0;
    }
    ll &ans = dp[m][a][b][c];
    if(a<0 || b<0 || c<0) return 0;
    if(ans != -1) return ans;

    ans = 0;    
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            for(int k=0; k<=1; k++){
                if(i+j+k==0) continue;
                ans += getMin(m-1, a-i, b-j, c-k);                
            }
        }
    }
    ans %= MOD;
    return ans; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];

    memset(dp, -1, sizeof(dp));
    cout << getMin(cnt[0], cnt[1], cnt[2], cnt[3]);

    return 0;
}