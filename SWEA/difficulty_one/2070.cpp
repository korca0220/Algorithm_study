#include <iostream>
using namespace std;

int t_input;
int a,b;

int main(){

    scanf("%d", &t_input);
    int test_case = 1;
    while(t_input--){
        scanf("%d %d", &a, &b);
        if(a>b)printf("#%d >\n",test_case);
        else if(a<b)printf("#%d <\n",test_case);
        else printf("#%d =\n",test_case);
        test_case++;
    }

    return 0;
}