#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[501][101];
int n,m;
int line[501];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start, end, del, add;
    cin >> n >> m;
    cin >> start >> end >> del >> add;
    
    start-=1;
    end-=1;
    
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 987654321;
        }
    }
    for(int i=1; i<=m; i++){
        cin >> line[i];
        line[i]-=1;
    }

    // 가로줄이 없는 경우
    for(int i=0; i<n; i++){
        if(i==start) dp[0][i] = 0;
        else dp[0][i] = abs(start-i) *add;
    }

    // 가로줄이 한 줄 이상인 경우
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){ // k는 중간 지점(중간 출발지점이자 도착지점)
                
                // 가로줄을 지우는 경우
                if(k==j && (line[i]+1 == k  || line[i]==k)){
                    if(dp[i][j] > dp[i-1][k] + del){
                        dp[i][j] = dp[i-1][k] + del;
                    }
                }
                // 가로줄을 추가하는 경우(2가지)
                // 1. 출발과 도착 사이에 가로줄이 한개 있는 경우
                else if((line[i]>=k && line[i] <= j-1) || (line[i]<=k-1 && line[i]>=j)){
                    if(dp[i][j] > dp[i-1][k] + (abs(k-j)-1)*add){
                        dp[i][j] = dp[i-1][k] + (abs(k-j)-1)*add;
                    }
                }// 2. 출발과 도착점 사이에 아무것도 없는 경우
                else{
                    if(dp[i][j] > dp[i-1][k] + abs(k-j)*add){
                        dp[i][j] = dp[i-1][k] + abs(k-j)*add;
                    }
                }
            }
        }
    }
    cout << dp[m][end];

    return 0;
}