#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int input;
int dp[1001], p[1001];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=1; i<=input; i++){
        cin >> p[i];
        dp[i] = 1000*10000;
    }
    for(int i=1; i<=input; i++){
        for(int j=1; j<=i; j++){
            dp[i] = min(dp[i], dp[i-j]+p[j]);
        }
    }
    cout << dp[input] << "\n";


    return 0;
}