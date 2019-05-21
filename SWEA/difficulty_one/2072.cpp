#include <iostream>
using namespace std;

const int MAX =10;
int input[MAX];
int t_input;

int main(){

    scanf("%d", &t_input);
    
    int test_count = 1;
    while(t_input--){
        int sum=0;
        for(int i=0; i<MAX; i++)scanf("%d", &input[i]);
        for(int i=0; i<MAX; i++){
            if(input[i] % 2 != 0)sum+=input[i];
        }
        printf("#%d %d\n", test_count, sum);
        test_count++;
    }

    return 0;
}