#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int input;
int dp[1001][1001];


int getDp(){

    int sum=0;
    for(int i=0; i<=9; i++)dp[1][i] = 1;
    for(int i=2; i<=input; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][k])%10007;
            }
        }
    }
    for(int i=0; i<=9; i++){
        sum += dp[input][i];
    }
    return sum%10007;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    
    cout << getDp() << "\n";

    return 0;
}