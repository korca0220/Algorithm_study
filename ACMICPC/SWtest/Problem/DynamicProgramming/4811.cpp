#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

ll dp[31][31];

ll getN(int f, int h){

    if(dp[f][h] != -1) return dp[f][h];
    if(f==0) return 1;
    if(h==0) return dp[f][h] = getN(f-1,h+1);
    return dp[f][h] = getN(f-1,h+1) + getN(f, h-1);
}

int main(){

    memset(dp, -1, sizeof(dp));
    while(true){
        int N;
        scanf("%d", &N);
        if(N==0) break;
        printf("%lld\n", getN(N, 0));
    }

    return 0;
}