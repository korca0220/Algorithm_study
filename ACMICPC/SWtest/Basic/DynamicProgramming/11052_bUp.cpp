#include <iostream>
#include <algorithm>
using namespace std;

int input;
int dp[1001];
int p[1001];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=1; i<=input; i++){
        cin >> p[i];
    }
    dp[0] = 0;
    dp[1] = p[1];
    for(int i=1; i<=input; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j]+p[j]);
        }
    }
    cout << dp[input] << "\n";
    return 0;
}