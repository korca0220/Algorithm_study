#include <iostream>
using namespace std;

int t_input;
int a,b;

int main(){

    scanf("%d", &t_input);
    int test_count=1;
    while(t_input--){
        scanf("%d %d", &a, &b);
        printf("#%d %d %d\n", test_count, a/b, a%b);
        test_count++;
    }

    return 0;
}