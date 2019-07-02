#include <iostream>
#include <string>
using namespace std;


int main(){
    long N;
    scanf("%ld", &N);

    int len = 1;
    long long total = 0;
    for(int i=1; i<=N; i*=10){
        int end = i*10 - 1;
        if(end > N)end = N;

        total += (end - i + 1)*len; 
        len++;  
    }
    printf("%lld", total);

    return 0;
}