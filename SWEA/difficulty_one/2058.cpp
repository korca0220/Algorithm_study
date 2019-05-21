#include <iostream>
using namespace std;

int main(){

    int input;
    scanf("%d", &input);

    int sum= 0;
    while(input){
        sum += input % 10;
        input = input/10;
    }
    printf("%d", sum);


    return 0;
}