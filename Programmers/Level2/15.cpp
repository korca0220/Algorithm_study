#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(auto _m : phone_book){
        for(auto __m : phone_book){
            if(_m == __m) continue;
            if(_m.length() > __m.length())continue;
            if(_m == __m.substr(0, _m.size())){
                answer = false;
                break;
            }
        }
    }
        
    return answer;
}