#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
int dp[1001];
int in[1001];
int v[10001];
int p;

void printDp(int n){

    if(n == 0)return ;
    printDp(v[n]);
    cout << in[n] << " ";
}

int getDp(){

    for(int i = 1; i<=input; i++){
        dp[i] = 1;
        v[i] = 0;
        for(int j=1; j<i; j++){
            if(in[i] > in[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
                v[i] = j;
            }
        }
    }

    int max_number=0;
    for(int i=1; i<=input; i++){
        if(max_number < dp[i]){
            max_number = dp[i];
            p = i;
        }
    }

    return max_number;
}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=1; i<=input; i++){
        cin >> in[i];
    }
    cout << getDp() << "\n";
    printDp(p);

    return 0;
}