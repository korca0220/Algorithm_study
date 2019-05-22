#include <iostream>
#include <algorithm>
using namespace std;


long input[1000001];
int t_input, day_input;

int main(){

    scanf("%d", &t_input);
    int test_count = 1;
    while(t_input--){
        long sum = 0;
        long max_number = 0;
        scanf("%d", &day_input);
        for(int i=0; i<day_input; i++)scanf("%d", &input[i]);

        for(int i=day_input-1; i>=0; i--){
            if (input[i]>max_number) {
                max_number = input[i];
                continue;
            }
            else{
                sum = sum + (max_number - input[i]);
            }
        }
        printf("#%d %ld\n", test_count, sum);
        test_count++;
    }

    return 0;
}