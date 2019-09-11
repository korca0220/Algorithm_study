#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer; 
    int len = s.length();
    if(len % 2 == 0){
        int half = len/2;
        answer += s[half-1];
        answer += s[half];
    }else answer = s[s.length()/2];
    return answer;
}