#include <initializer_list>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 100;
long long dp[MAX+1];

int main(){

    int n;
    scanf("%d", &n);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=1; i<=MAX; i++){
        for(int j=1; j<=(i-3); j++){
            dp[i] = max({dp[i], dp[i-1]+1, dp[i-(j+2)]*(j+1)});
        }
    }
    
    printf("%lld", dp[n]);


    return 0;
}