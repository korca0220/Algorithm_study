#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 500;

int dp[MAX+1][MAX+1];

int getMin(vector<int> &in, int s, int e){

    if(s==e) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    int &ans = dp[s][e];

    int sum = 0;
    for(int i=s; i<=e; i++)sum += in[i];

    for(int i=s; i<e; i++){
        int temp = getMin(in, s, i) + getMin(in, i+1, e) + sum; 
        if(ans == -1 || ans > temp){
            ans = temp;
        }
    }
    return ans;

}

int main(){

    int T;
    scanf("%d", &T);

    while(T--){
        int n;
        scanf("%d", &n);
        vector<int> in(n+1);
        for(int i=1; i<=n; i++)scanf("%d", &in[i]);

        memset(dp, -1, sizeof(dp));
        printf("%d\n", getMin(in, 1, n));
    }

    return 0 ;

}