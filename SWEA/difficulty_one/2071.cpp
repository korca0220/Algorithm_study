#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10;
int input;
int t_input;

int main(){

    scanf("%d", &t_input);

    
    int test_count = 1;
    while(t_input--){
        double sum=0.0;
        double avg=0.0;
        for(int i=0; i<MAX; i++){
            scanf("%d", &input);
            sum += input;
        }
        avg = sum/MAX;
        printf("#%d %.0f\n", test_count, avg);
        test_count++;    
    }


    return 0;
}