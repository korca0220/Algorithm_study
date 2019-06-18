#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
int dp[1001];
int in[1001];

int getDp(){

    for(int i = 0; i<input; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(in[i] > in[j] && dp[i] < dp[j]+1){
                dp[i] = dp[i] + 1;
            }
        }
    }

    int max_number=0;
    for(int i=0; i<input; i++){
        if(max_number < dp[i]){
            max_number = dp[i];
        }
    }

    return max_number;
}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=0; i<input; i++){
        cin >> in[i];
    }
    cout << getDp() << "\n";

    return 0;
}