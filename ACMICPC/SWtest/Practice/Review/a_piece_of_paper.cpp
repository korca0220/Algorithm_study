#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N,M;
int in[5][5];

int main(){

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &in[i][j]);
        }
    }

    int ans = 0;
    for(int s=0; s<(1<<(N*M)); s++){

        int sum = 0;
        for(int i=0; i<N; i++){
            int cur = 0;
            for(int j=0; j<M; j++){
                int k = i*M+j;
                if((s&(1<<k)) == 0){
                    cur = cur * 10 + in[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for(int j=0; j<M; j++){
            int cur = 0;
            for(int i=0; i<N; i++){
                int k = i*M+j;
                if((s & (1<<k)) != 0){
                    cur = cur * 10 + in[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        if(ans < sum ) ans = sum;
    }
    printf("%d", ans);


    return 0;
}