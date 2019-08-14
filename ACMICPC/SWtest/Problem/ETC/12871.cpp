#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string s,t;
    cin >> s >> t;

    int l_size, s_size;
    string l_str, s_str;
    if(s.length() >= t.length()){
        l_size = s.length(); l_str = s;
        s_size = t.length(); s_str = t;
    }else{
        l_size = t.length(); l_str = t;
        s_size = s.length(); s_str = s;
    }

    bool ok = false;
    for(int i=0; i<2500; i++){
        if(l_str[i%l_size] == s_str[i%s_size]){
            ok = true;
        }else{
            ok = false;
            break;
        }
    }
    printf(ok ? "1" : "0");

    return 0;
}