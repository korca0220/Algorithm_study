#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MOD = 10007;
const int MAX = 1000;
ll dp[MAX+1][MAX+1];

int main(){

    int N,K;
    scanf("%d %d", &N, &K);

    for(int i=0; i<=MAX; i++){
        dp[i][0] = dp[i][i] = 1; 
        for(int j=1; j<i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %=MOD;
        }
    }
    printf("%d", dp[N][K]);

    return 0;
}