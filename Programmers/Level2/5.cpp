#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    for(int i=0; i<arrangement.length(); i++){
        if(arrangement[i] == '(')s.push(arrangement[i]);
        else{
            s.pop();
            if(arrangement[i-1] == '('){
                answer += s.size();
            }else answer+=1;
        }
    }
    return answer;
}