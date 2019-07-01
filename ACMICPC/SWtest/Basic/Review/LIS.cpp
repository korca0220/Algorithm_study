#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N;
int input[MAX+1];
int dp[1001];

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%d", &input[i]);

    for(int i=1; i<=N; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(input[i] > input[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
    int long_num = 0;
    for(int i=1; i<=N; i++){
        long_num = max(long_num, dp[i]);
    }
    printf("%d", long_num);

    return 0;
}