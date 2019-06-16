#include <iostream>
using namespace std;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int input;
    int dp[1001];
    cin >> input;
    dp[0] = 1; dp[1] = 1;
    for(int i=2; i<=input; i++)dp[i] = (2*dp[i-2] + dp[i-1])%10007;
    cout << dp[input];
    return 0;

}