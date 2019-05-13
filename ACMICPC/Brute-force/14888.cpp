#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 11;
int N;
int input_number[MAX];
int operator_array[4];

int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d", input_number[i]);
    for(int i=0; i<4; i++)scanf("%d", &operator_array[i]);


    return 0;
}