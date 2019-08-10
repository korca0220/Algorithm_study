#include <iostream>
#include <algorithm>
using namespace std;

bool dp[31][31][31][361];
char in[31];

int N,K;

bool testChar(int i, int a, int b, int p){

    if(i==N){
        if(K==p) return true;
        else return false;
    }
    if(dp[i][a][b][p]) return false; //memoization

    dp[i][a][b][p] = true;
    in[i] = 'A';
    if(testChar(i+1, a+1, b, p)) return true;

    in[i] = 'B';
    if(testChar(i+1, a, b+1, p+a)) return true;

    in[i] = 'C';
    if(testChar(i+1, a, b, p+a+b)) return true;

    return false;
}

int main(){
    scanf("%d %d", &N, &K);
    if(testChar(0, 0, 0, 0)){
        cout << in;
    }else cout << "-1";

    return 0;
}