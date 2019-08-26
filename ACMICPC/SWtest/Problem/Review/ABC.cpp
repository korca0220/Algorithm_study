#include <iostream>
using namespace std;

int dp[30][30][30][435];
int n, k;
char in[31];
bool getChar(int i, int a, int b, int p){

    if(i==n){
        if(k==p) return true;
        else return false;
    }
    if(dp[i][a][b][p] > 0 ) return false;

    dp[i][a][b][p] = true;

    in[i] = 'A';
    if(getChar(i+1, a+1, b, p)) return true;

    in[i] = 'B';
    if(getChar(i+1, a, b+1, p+a)) return true;

    in[i] = 'C';
    if(getChar(i+1, a, b, p+a+b)) return true;

    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    if(getChar(0,0 ,0,0)){
        cout << in;
    }else cout << "-1";

    return 0;
}