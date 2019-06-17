#include <iostream>
using namespace std;

const int MAX = 1000000;
int t_input, input;
int dp[MAX+1];

int getDp(int n){

    if(n==0) return 1;
    if(dp[n] > 0) return dp[n];
    else{
        if(n-1 >= 0) dp[n] = (dp[n] + getDp(n-1))%1000000009;
        if(n-2 >= 0) dp[n] = (dp[n] + getDp(n-2))%1000000009;
        if(n-3 >= 0) dp[n] = (dp[n] + getDp(n-3))%1000000009;
    }
    return dp[n];

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t_input;
    while(t_input--){
        cin >>input;
        cout << getDp(input) << "\n";
    }

    return 0;
}