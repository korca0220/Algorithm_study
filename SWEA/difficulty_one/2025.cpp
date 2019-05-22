#include <iostream>
using namespace std;

int input;

int getSum(int num){

    if(num == 1)return 1;
    return num + getSum(num-1);
}

int main(){
    scanf("%d", &input);
    printf("%d", getSum(input));

    return 0;
}