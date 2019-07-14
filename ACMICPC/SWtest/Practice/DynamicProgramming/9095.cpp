#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int N;
int dp[1001];
int main(){

    int T;
    scanf("%d", &T);
    
    dp[0] = 1;
    int nums[] = {1,2,3};
    for(int i=1; i<=10; i++){
        for(int j=0; j<3; j++){
            if(i - nums[j] >= 0)dp[i] += dp[i-nums[j]];
        }
    }

    while(T--){
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
    


    return 0;
}