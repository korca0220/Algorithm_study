#include <iostream>
#include <initializer_list>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NUMBER = 100000;
int t_input, input;
long long in[2][MAX_NUMBER+1];
long long dp[MAX_NUMBER+1][3];

long long getDp(){

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i =1; i<=input; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = max(dp[i-1][2], dp[i-1][0])+in[0][i];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0])+in[1][i];
    }
    long long sum=0;
    for(int i=1; i<=input; i++){
        sum = max({sum, dp[i][0], dp[i][1], dp[i][2]});
    }

    return sum;
} 

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t_input;
    while(t_input--){
        cin >> input;
        for(int i=0; i<2; i++){
            for(int j=1; j<=input; j++){
                cin >> in[i][j];
            }
        }
        cout << getDp() << "\n";
    }

    return 0;
}