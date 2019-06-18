#include <iostream>
using namespace std;

int input;
long long dp[90][2];


long long getDp(){

    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 0;
    for(int i = 3; i<=input; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    return dp[input][0] + dp[input][1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    cout << getDp() << "\n";

    return 0;
}