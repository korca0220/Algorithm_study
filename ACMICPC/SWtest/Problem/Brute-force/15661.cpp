#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int in[21][21];
int N;
int ans = 987654321;

void cal(vector<int> &a, vector<int> &b){

    int sum_a=0;
    int sum_b=0;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size(); j++){
            if(i!=j){
                sum_a += in[a[i]][a[j]];
            }
        }
    }

    for(int i=0; i<b.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(i!=j){
                sum_b += in[b[i]][b[j]];
            }
        }
    }

    int diff = abs(sum_a-sum_b);
    if(ans > diff) ans = diff;

}

int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &in[i][j]);
        }
    }

    for(int i=1; i<((1<<N)-1); i++){
        vector<int> a;
        vector<int> b;
        for(int j=0; j<N; j++){
            if(i&(1<<j))a.push_back(j);
            else b.push_back(j);
        }
        cal(a, b);
    }
    printf("%d", ans);

    return 0;
}