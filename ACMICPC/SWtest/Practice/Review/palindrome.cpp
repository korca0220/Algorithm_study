#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2000;

int dp[MAX+1][MAX+1];

int getPal(vector<int> &in, int s, int e){

    if(s==e) return 1;
    if(s+1 == e){
        if(in[s] == in[e]) return 1;
        else return 0;
    }

    if(dp[s][e] > 0 ) return dp[s][e];
    if(in[s] != in[e]) return dp[s][e] = 0;
    else return dp[s][e] = getPal(in, s+1, e-1);

}

int main(){

    int N;
    scanf("%d", &N);

    vector<int> in(N+1);
    for(int i=1; i<=N; i++)scanf("%d", &in[i]);

    int M;
    scanf("%d", &M);
    memset(dp, -1, sizeof(dp));
    while(M--){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", getPal(in, s, e));
    }


    return 0;
}