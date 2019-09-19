#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string s : skill_trees){
        string str="";
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<skill.length(); j++){
                if(skill[j] == s[i]){
                    str += s[i];
                    break;
                }
            }
        }
        bool ok = true;
        for(int k=0; k<str.length(); k++){
            if(str[k] != skill[k]){
                ok = false; 
                break;
            }
        }
        if(ok){
            answer +=1;
        }
    }
    return answer;
}