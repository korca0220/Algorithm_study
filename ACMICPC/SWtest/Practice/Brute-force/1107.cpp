#include <iostream>
#include <string>
using namespace std;

int N, M;
bool con[10];

int getCheck(int n){
    int len = 0;
    if(n==0){
        if(con[0]) return 0;
        else return 1;
    }
    
    while(n > 0){
        if(con[n%10])return 0;
        len += 1;
        n = n/10;
    }
    return len;
}

int main(){

    scanf("%d", &N);
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int temp;
        scanf("%d", &temp);
        con[temp] = true;
    }
    int ans = abs(N-100);

    for(int i=0; i<=1000000; i++){
        int len = getCheck(i);
        if(len > 0){
            int press = abs(i-N); 
            if(ans > len + press){
                ans = len + press;
            }
        }
    }

    printf("%d", ans);


    return 0;
}