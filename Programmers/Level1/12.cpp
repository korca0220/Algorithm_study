#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    
    int len =s.length();
    if(len==4 ||len==6){   
        cout << len;     
        for(auto p : s){
            if(0<=p-'0' && p-'0'<=9)continue;
            else return false;
        }
    }else return false;
    return true;
}
