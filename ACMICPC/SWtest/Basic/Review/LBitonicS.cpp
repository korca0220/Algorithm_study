#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N;
int input[MAX+1];
int idp[MAX+1], ddp[MAX+1];

int main(){

    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%d", &input[i]);

    for(int i=1; i<=N; i++){
        idp[i] = 1;
        for(int j=1; j<i; j++){
            if(input[i] > input[j] && idp[i] < idp[j] + 1){
                idp[i] = idp[j] + 1;
            }
        }
    }
    for(int i=N; i>0; i--){
        ddp[i] = 1;
        for(int j=N; j>i; j--){
            if(input[i] > input[j] && ddp[i] < ddp[j] + 1){
                ddp[i] = ddp[j] + 1;
            }
        }
    }
    int max_sum = 0;
    for(int i=1; i<=N; i++){
        max_sum = max(max_sum, ddp[i]+idp[i]);
        
    }
    printf("%d", max_sum-1);

    return 0;
}