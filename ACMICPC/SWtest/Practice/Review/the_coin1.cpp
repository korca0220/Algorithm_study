#include <iostream>
using namespace std;

const int MAX = 10000;

int dp[MAX+1];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *dirs = new int[n];

    for(int i=0; i<n; i++)scanf("%d", &dirs[i]);

    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=MAX; j++){
            if(j-dirs[i] >=0) dp[j] += dp[j-dirs[i]];
        }
    }
    printf("%d", dp[k]);

    return 0;
}