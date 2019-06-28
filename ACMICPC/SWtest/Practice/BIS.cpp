#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N;
int input[MAX+1];
int dp[MAX+1];

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%d", &input[i]);

    
    for(int i=1; i<=N; i++){
        dp[i] = input[i];
        for(int j=1; j<i; j++){
            if(input[i] > input[j] && dp[i] < dp[j] + input[i]){
                dp[i] = dp[j] + input[i];
            }
        }
    }

    int max_num = 0;
    for(int i=1; i<=N; i++){
        max_num = max(max_num, dp[i]);
    }
    printf("%d", max_num);

    return 0;
}