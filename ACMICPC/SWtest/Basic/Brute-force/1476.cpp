#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int E,S,M;

int main(){

    int count = 1;
    bool check = true;
    scanf("%d %d %d", &E, &S, &M);

    if(E==S==M){
        count = E;
        check = false;
    }

    int temp_a=1, temp_b=1, temp_c=1;

    while(check){
        
        temp_a++;
        temp_b++;
        temp_c++;
        count++;
        if (temp_a>15) temp_a = 1;
        if (temp_b>28) temp_b = 1;
        if (temp_c>19) temp_c = 1;

        if(temp_a == E && temp_b == S && temp_c == M)break;
    }
    printf("%d\n", count);
    

    return 0;
}