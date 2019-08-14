#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAX = 100000;
ll dp[MAX+1];
ll in[MAX+1];

int main(){

    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)scanf("%lld", &in[i]);


    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1] + in[i];
    }
    
    while(m--){
        int a,b;
        scanf("%d %d", &a,&b);
        printf("%lld\n", dp[b]-dp[a-1]);
    }

    return 0;
}