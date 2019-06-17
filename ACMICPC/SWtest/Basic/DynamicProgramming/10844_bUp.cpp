#include <iostream>
using namespace std;

const long long mod = 1000000000;
int input;
long dp[101][10];


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=1; i<=9; i++)dp[1][i] = 1;
    for(int i=2; i<=input; i++){
        for(int j=0; j<=9; j++){
            if(j-1 >= 0) dp[i][j] = dp[i][j] + dp[i-1][j-1];
            if(j+1 <= 9) dp[i][j] = dp[i][j] + dp[i-1][j+1];
            dp[i][j] = dp[i][j]%mod;
        }
    }
    long long sum = 0;
    for(int i=0; i<=9; i++)sum+=dp[input][i];
    cout << sum%mod;

    return 0;
}