#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int dp[501][101];
int line[501];

int main(){

    int start,end,add,del;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &start, &end, &del, &add);

    start-=1; end-=1;
    for(int i=1; i<=m; i++){
        scanf("%d", &line[i]);
        line[i]-=1;
    }

    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 987654321;
        }
    }

    // 가로줄이 없는 경우
    for(int i=0; i<n; i++){
        if(i==start)dp[0][i] = 0;
        else{
            dp[0][i] = abs(start-i)*add;
        }
    }

    // 가로줄이 1줄 부터 ~M줄까지
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){ //도착 
            for(int k=0; k<n; k++){ // 이전

                // 지우는 경우
                if(k==j && (line[i] == k || line[i]+1 == k)){
                    if(dp[i][j] > dp[i-1][k] + del){
                        dp[i][j] = dp[i-1][k] + del;
                    }
                }
                // 추가하는 경우(2가지)
                else if((k <= line[i] && line[i] <= j-1)||(k-1 >= line[i] && j<=line[i])){
                    if(dp[i][j] > dp[i-1][k] + (abs(k-j)-1)*add){
                        dp[i][j] = dp[i-1][k] + (abs(k-j)-1)*add;
                    }
                    
                }else{
                    if(dp[i][j] > dp[i-1][k] + abs(k-j)*add){
                        dp[i][j] = dp[i-1][k] + abs(k-j)*add;
                    }
                }
            }
        }
    }

    printf("%d", dp[m][end]);

    return 0;
}