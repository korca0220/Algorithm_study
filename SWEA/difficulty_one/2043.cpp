#include <iostream>
using namespace std;

int P, K;

int main(){

    scanf("%d %d", &P, &K);
    int count=0;

    for(int i=K; i<=P; i++)count++;
    printf("%d", count);
    

    return 0;
}