#include <iostream>
using namespace std;

int input;
int dp[1001];


int getDp(int n){
    
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    return dp[n];

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >>input;
    cout << getDp(input)<<"\n";

    return 0;
}