#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){

    string s,t;
    cin >> s >> t;

    while(t.length() > s.length()){
        if(t.back() == 'A'){
            t.pop_back();
        }else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if(s==t)printf("1");
    else printf("0");


    return 0;
}