#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>
using namespace std;

int input;
vector<int> in(10001, 0);
int dp[10001][3];

int getDp(){

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i=1; i<=input; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = dp[i-1][0] + in[i];
        dp[i][2] = dp[i-1][1] + in[i];
    }
    
    int sum =0;
    for(int i=1; i<=input; i++){
        sum = max({sum, dp[i][0], dp[i][1], dp[i][2]});
    }
    return sum;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=1; i<=input; i++){
        cin >> in[i];
    }
    cout << getDp() << "\n";

    return 0;
}