#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAX = 1500000;
ll dp[MAX+50];
ll T[MAX+1];
ll P[MAX+1];
int N;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%lld %lld", &T[i], &P[i]);
    }

    for(int i=0; i<N; i++){
        dp[i+T[i]] = max(dp[i+T[i]], dp[i]+P[i]);
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    printf("%lld", dp[N]);

    return 0;
}