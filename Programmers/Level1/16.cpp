#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    for(char &c : s){
        if(c==' ')continue;
        if('a'<= c && c<='z'){
            if(c+n>'z')c= c + n -26;
        }else if('A'<= c && c<='Z'){
            if(c+n>'Z')c = c +n - 26;
        }
    }
    return s;
}