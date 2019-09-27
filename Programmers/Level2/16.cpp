#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> ot;
    for(int i=0; i<clothes.size(); i++){
        ot[clothes[i][1]]+=1;
    }
    for(auto p : ot){
        cout << p.second << "\n";
        answer *= (p.second + 1);
    }
    return answer-1;
}