#include <string.h>
#include <iostream>
#include <string>
using namespace std;

char* changeChar(){

    char text[9];
    strcpy(text, "TTTTT");
    return text;
}
int main(){

    char* pptr=nullptr;
    pptr = changeChar();
    cout << pptr;
}

