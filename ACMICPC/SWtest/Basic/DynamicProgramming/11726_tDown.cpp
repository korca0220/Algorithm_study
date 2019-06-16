#include <iostream>
using namespace std;

int input;
int dp[1001];

int getNum(int n){

    if(n==0 || n==1) return 1;
    if(dp[n] > 0) return dp[n];
    else{
        dp[n] = (getNum(n-1) + getNum(n-2))%10007;
        return dp[n];
    }

}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    cout << getNum(input)<< "\n";

    return 0;
}