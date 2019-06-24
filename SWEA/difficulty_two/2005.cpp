#include <iostream>
using namespace std;


int main(){
    int t_input, input;
    scanf("%d", &t_input);
    int t_count = 1;
    while(t_input--){
        scanf("%d", &input);
        printf("#%d\n", t_count++);
        for(int i=0; i<input; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    printf("1 ");
                }
                else printf("%d ", i);
            }
            printf("\n");
        }
    }
    return 0;
}