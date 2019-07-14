#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;

int N;
int dp[MAX+1];

int main(){
    int T;
    scanf("%d", &T);

    dp[0] = 1;
    int num[] = {1,2,3};
    for(int i=0; i<3; i++){
        for(int j=1; j<=MAX; j++){
            if(j-num[i] >= 0)dp[j] += dp[j-num[i]];
        }
    }
    while(T--){
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }


    return 0;
}