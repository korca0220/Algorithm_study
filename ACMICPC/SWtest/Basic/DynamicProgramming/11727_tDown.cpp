#include <iostream>
using namespace std;


const int MAX = 1000;
int dp[MAX+1];
int input;

int getDp(int n){

    if(n==0 || n == 1) return 1;
    if(dp[n] >0) return dp[n];

    dp[n] = ((2*getDp(n-2))+getDp(n-1))%10007;
    return dp[n];

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    cout << getDp(input) << "\n";


    return 0;
}