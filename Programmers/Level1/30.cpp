#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> p;
    for(string s : participant)p[s] +=1;
    for(string s : completion)p[s] -=1;
    for(auto pp : p){
        if(pp.second > 0){
            answer= pp.first;
            break;
        }
    }
    return answer;
}