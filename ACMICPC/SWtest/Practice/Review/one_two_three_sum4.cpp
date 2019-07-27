#include <iostream>
using namespace std;

int dp[11];

int main(){
    int T;
    scanf("%d", &T);

    int dirs[] = {1,2,3};
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 3;
    for(int i=0; i<3; i++){
        for(int j=4; j<11; j++){
            dp[j] += dp[j-dirs[i]];
        }
    }


    return 0;
}