#include <iostream>
using namespace std;

void getReverse(int num){

    printf("%d ", num);
    if(num == 0){        
        return ;
    }
    else return getReverse(num-1);

}
int input;
int main(){
    scanf("%d", &input);
    getReverse(input);

    return 0;
}