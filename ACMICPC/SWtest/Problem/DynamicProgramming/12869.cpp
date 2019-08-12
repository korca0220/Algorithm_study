#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 987654321;
int dp[61][61][61];
int in[3];

int getMin(int a, int b, int c){

    if(a<0) return getMin(0,b,c);
    if(b<0) return getMin(a,0,c);
    if(c<0) return getMin(a,b,0);
    if(a==0 && b==0 && c==0) return 0;
    int &ans = dp[a][b][c];
    if(ans != -1) return ans;

    ans = MAX;
    int ans_m = 0;
    vector<int> p = {1,3,9};
    do{
        int temp = getMin(a-p[0], b-p[1], c-p[2]);
        if(ans > temp) ans = temp;
    }while(next_permutation(p.begin(), p.end()));
    ans +=1;
    return ans;
}

int main(){

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &in[i]);
    }    

    memset(dp, -1, sizeof(dp));
    printf("%d", getMin(in[0], in[1], in[2]));

    return 0;
}