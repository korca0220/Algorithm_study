#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 
char input[201];
 
 
int main(){
     
    scanf("%s", input);
     
    for(int i=0; i<strlen(input); i++){
        printf("%d ", input[i]-64);
    }
 
    return 0;
}