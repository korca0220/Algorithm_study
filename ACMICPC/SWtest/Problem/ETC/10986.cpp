#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    vector<int> num(n);
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
        num[i]%=m;
    }
    vector<ll> cnt(m, 0);
    cnt[0] = 1;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += num[i];
        sum %= m;
        cnt[sum] += 1;
    }
    ll ans =0;
    for(int i=0; i<m; i++){
        ans += (ll)cnt[i] * (ll)(cnt[i]-1)/2LL;
    }
    printf("%lld", ans);

    return 0;
}