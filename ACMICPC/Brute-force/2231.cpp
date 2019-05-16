#include <iostream>
#include <cstdio>
using namespace std;

int input;

int getSum(int num){

    int sum=0;
    int temp=num;

    while(temp){

        sum += temp%10;
        temp = temp/10;
    }
    return num+sum;

}

int main(){

    scanf("%d", &input);

    int find_number;
    for(int i=1; i<input; i++){
        find_number = getSum(i);
        if (find_number == input){
            find_number = i;
            break;
        }else find_number = 0;
    }
    printf("%d", find_number);

    return 0;
}