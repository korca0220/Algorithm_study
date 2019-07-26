#include <iostream>
#include <vector>
using namespace std;

int dp[11];

int main(){

    int T;
    scanf("%d", &T);

    int dir[] = {1,2,3};
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<11; i++){
        for(int j=0; j<3; j++){
            dp[i] += dp[i-dir[j]];
        }
    }
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}