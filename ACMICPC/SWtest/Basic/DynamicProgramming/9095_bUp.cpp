#include <iostream>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int t_input, input;
    int dp[11];
    dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    cin >> t_input;
    while(t_input--){
        cin>>input;
        for(int i=4; i<=input; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[input] << "\n";
    }

    return 0;
}