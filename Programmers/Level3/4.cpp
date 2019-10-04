#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

bool checkWord(string a, string b){

    int sum = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i])sum+=1;
    }
    return sum==1?true:false;
}

int solution(string begin, string target, vector<string> words) {

    map<string, int> check;
    for(int i=0; i<words.size(); i++)check[words[i]] = 0;
    queue<string> q;
    q.push(begin);
    while(!q.empty()){
        string now = q.front();
        q.pop();        
        for(int i=0; i<words.size(); i++){
            if(check[words[i]] == 0){
                if(checkWord(now, words[i])){
                    q.push(words[i]);
                    check[words[i]] = check[now] + 1;
                }
            }
        }
    }
    return check[target];
}