#include <iostream>
using namespace std;
const int MAX = 10000;

int dp[MAX+1];

int main(){
    int T;
    scanf("%d", &T);

    int dirs[] = {1,2,3};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=0; i<3; i++){
        for(int j=2; j<=MAX; j++){
            dp[j] += dp[j-dirs[i]];
        }
    }

    while(T--){
        int N;
        scanf("%d", &N);
        printf("%d\n", dp[N]);

    }

    return 0;
}