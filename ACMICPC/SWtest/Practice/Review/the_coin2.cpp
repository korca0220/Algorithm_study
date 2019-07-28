#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10000;
int dp[MAX+1];


int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    
    int *dirs = new int[n];
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)scanf("%d", &dirs[i]);

    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=MAX; j++){
            if(j-dirs[i] >=0 && dp[j-dirs[i]] != -1){
                if(dp[j] == -1  || dp[j] > dp[j-dirs[i]] + 1){
                    dp[j] = dp[j-dirs[i]]+1;
                }
            }   
        }
    }
    printf("%d", dp[k]);
    return 0;

}