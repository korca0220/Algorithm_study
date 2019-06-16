#include <iostream>
using namespace std;

int input, t_input;
int dp[11];

int getDp(int n){

    if(n==0) return 1;
    if(dp[n] > 0) return dp[n];
    else{
        if(n-1>=0)dp[n] = dp[n] + getDp(n-1);
        if(n-2>=0)dp[n] = dp[n] + getDp(n-2);
        if(n-3>=0)dp[n] = dp[n] + getDp(n-3);
    }
    return dp[n];

}
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t_input;
    while(t_input--){
        cin >> input;
        cout << getDp(input) << "\n";
    }
    return 0;
}