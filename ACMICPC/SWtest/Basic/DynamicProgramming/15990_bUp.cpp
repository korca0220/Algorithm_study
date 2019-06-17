#include <iostream>
using namespace std;

const int MAX = 100000;
int input, t_input;
long long dp[MAX+1][4];

void getDp(){

    for(int i=1; i<=100000; i++){
        if(i-1>= 0){
            dp[i][1] = dp[i-1][2] + dp[i-1][3];
            if(i==1)dp[i][1] =1;
        }
        if(i-2 >= 0){
            dp[i][2] = dp[i-2][1] + dp[i-2][3];
            if(i==2)dp[i][2] = 1;
        }
        if(i-3 >= 0){
            dp[i][3] = dp[i-3][1] + dp[i-3][2];
            if(i==3)dp[i][3] = 1;
        }
        dp[i][1] = dp[i][1] % 1000000009;
        dp[i][2] = dp[i][2] % 1000000009;
        dp[i][3] = dp[i][3] % 1000000009;
    }
    
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t_input;
    getDp();
    while(t_input--){
        cin >> input;
        cout << (dp[input][1]+dp[input][2]+dp[input][3])%1000000009 << "\n";
    }

    return 0;
}