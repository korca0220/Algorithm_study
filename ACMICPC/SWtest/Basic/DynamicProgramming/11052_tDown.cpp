#include <iostream>
#include <algorithm>
using namespace std;

int input;
int dp[1001], p[1001];

int getDp(int n){

    if(n==0) return 0;
    if(dp[n] > 0) return dp[n];
    else{
        for(int i=1; i<=n; i++){
            dp[n] = max(dp[n], getDp(n-i)+p[i]);
        }
    }
    return dp[n];

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=1; i<=input; i++)cin >> p[i];

    cout << getDp(input) << "\n";
    return 0;
}