#include <iostream>
using namespace std;
const int MAX = 100000;
int dp[MAX+1];

int main(){

    int n,k;
    scanf("%d %d", &n, &k);
    int nums[n];

    for(int i=0; i<n; i++)scanf("%d", &nums[i]);

    dp[0]=1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(j-nums[i]>= 0)dp[j] += dp[j-nums[i]];
        }
    }
    printf("%d", dp[k]);

}