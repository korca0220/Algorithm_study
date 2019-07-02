#include <iostream>
#include <algorithm>
using namespace std;

int M,N;
int x,y;


int main(){
    int t_input;
    scanf("%d", &t_input);
    while(t_input--){
        bool check = false;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        x -= 1;
        y -= 1;
        for(int i=x; i<M*N; i+=M){
            if(i%N == y){
                printf("%d\n", i+1);
                check = true;
                break;
            }
        }
        if(!check)printf("-1\n");
    }

    return 0;
}