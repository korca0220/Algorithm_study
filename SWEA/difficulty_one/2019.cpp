#include <iostream>
using namespace std;

int getB(int num){

    if(num == 1) return 2;
    return 2 * getB(num-1);
}

int input;
int main(){
    scanf("%d", &input);
    for(int i=0; i<=input; i++){
        if(i==0)printf("1 ");
        else printf("%d ", getB(i));
    }
    return 0;
}