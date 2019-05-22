#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char input[201];


int main(){
    
    scanf("%s", input);
    
    for(int i=0; i<strlen(input); i++){
        if(97 <= input[i] && input[i] <= 122 ){
            printf("%c", input[i]-32);
        }
        else printf("%c", input[i]);
    }

    return 0;
}